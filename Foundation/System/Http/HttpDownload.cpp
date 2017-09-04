#include "HttpDownload.h"

#include "../Http/import.h"

#include <thread>

#define SLEEP_MILLISECOND 200

using namespace sys;

HttpDownload::HttpDownload()
{

}

HttpDownload::~HttpDownload()
{
	this->clear();
}

bool HttpDownload::download(const char* url, int port, const char* filepath, OnHttpDownloadCallback callback, int tag)
{
	if (url == NULL)
	{
		return false;
	}
	Client* client = new Client(url, port);
	client->setRecvHandler(this, static_cast<CLIENT_RECV_HANDLER>(&HttpDownload::onRecvHandle));
	if (!client->connect())
	{
		delete client;
		return false;
	}

	const char* request = getCString("GET /%s HTTP/1.1\r\n\r\n", filepath);
	client->sendString(request);
	
	std::thread th([&](){
		while (client->isConnected())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_MILLISECOND));
			client->update();
		}
		this->flushListenData(client->getID());
		delete client;
	});
	th.detach();

	this->addListen(client, callback, tag);

	return true;
}

void HttpDownload::flushListenData(int id)
{// 推送监听到的数据
	std::map<int, StreamWriter*>::iterator iter1 = _downloadDatas.find(id);
	if (iter1 == _downloadDatas.end())
	{// 无缓存数据
		return;
	}

	DownloadCallback::iterator iter2 = _downloadCallbacks.find(id);
	if (iter2 == _downloadCallbacks.end())
	{// 无下载监听
		SAFE_DELETE(iter1->second);
		_downloadDatas.erase(iter1);
		return;
	}

	// http内容
	HttpRespDocument* pDoc = new HttpRespDocument();
	if (pDoc->parseResponse(iter1->second->getData(), iter1->second->getLength()))
	{
		// 完整的http
		(iter2->second.t2.first->*iter2->second.t2.second)(iter2->second.t1, pDoc->getBody(), pDoc->getBodySize());
	}
	delete pDoc;

	// 删除客户端
	SAFE_DELETE(iter2->second.t3);
	_downloadCallbacks.erase(iter2);
	
	// 删除数据
	SAFE_DELETE(iter1->second);
	_downloadDatas.erase(iter1);
}

void HttpDownload::onRecvHandle(int id, DataQueue& data)
{// 接收数据回调
	if (data.empty())
	{
		return;
	}

	StreamWriter* pWriter;

	NetData* netData = data.pop();

	std::map<int, StreamWriter*>::iterator iter = _downloadDatas.find(id);
	if (iter == _downloadDatas.end())
	{// 创建新的接收池
		pWriter = new StreamWriter(netData->data, netData->size);
		_downloadDatas[id] = pWriter;
	}
	else
	{// 追加到已有的接收池中
		pWriter = iter->second;
		pWriter->writeString(netData->data, netData->size);
	}
	SAFE_DELETE(netData);

	HttpRespDocument* pDoc = new HttpRespDocument();
	if (pDoc->parseResponse(pWriter->getData(), pWriter->getLength()))
	{
		int len = 0;
		if (pDoc->getIntegerHeader(HttpResponeField::CONTENT_LENGTH, len))
		{
			if (len == pDoc->getBodySize())
			{
				// 下载完毕，断开连接
				if (_downloadCallbacks.find(id) != _downloadCallbacks.end())
				{
					_downloadCallbacks[id].t3->disconnect();
				}
			}
		}
	}

	delete pDoc;
}

void HttpDownload::addListen(Client* client, OnHttpDownloadCallback callback, int tag)
{// 添加一个下载监听
	if (client == nullptr)
	{
		return;
	}

	_downloadCallbacks[client->getID()] = make_tuple3(tag, callback, client);
}

void HttpDownload::clear()
{
	DownloadCallback::iterator iter2 = _downloadCallbacks.begin();
	while (iter2 != _downloadCallbacks.end())
	{// 关闭线程，注销客户端
		iter2->second.t3->disconnect();
		SAFE_DELETE(iter2->second.t3);
		iter2++;
	}

	std::map<int, StreamWriter*>::iterator iter1 = _downloadDatas.begin();
	while (iter1 != _downloadDatas.end())
	{// 关闭接收数据
		SAFE_DELETE(iter1->second);
		iter1++;
	}

	_downloadDatas.clear();
}