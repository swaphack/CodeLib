#include "HttpDownload.h"

#include "../Http/import.h"

#include <thread>

#define SLEEP_MILLISECOND 200

using namespace web;

HttpDownload::HttpDownload()
{

}

HttpDownload::~HttpDownload()
{
	this->clear();
}

bool HttpDownload::download(const char* url, int port, const char* filepath, downloadCallback callback, int tag)
{
	if (url == NULL)
	{
		return false;
	}
	sys::Client* client = new sys::Client(url, port);
	client->setRecvHandler(this, static_cast<sys::CLIENT_RECV_HANDLER>(&HttpDownload::onRecvHand));
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
	std::map<int, sys::StreamWriter*>::iterator iter1 = _downloadDatas.find(id);
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
	HttpResponse* pResp = new HttpResponse();
	int result = pResp->tryParseMessage(iter1->second->getData(), iter1->second->getLength());
	if (pResp->isHttpFormat() && pResp->isFullCommand())
	{// 完整的http
		iter2->second.t2(iter2->second.t1, pResp->getBody(), pResp->getBodySize());
	}
	else
	{
		delete pResp;
	}

	SAFE_DELETE(iter1->second);
	_downloadDatas.erase(iter1);

	_downloadCallbacks.erase(iter2);
}

void HttpDownload::onRecvHand(int id, sys::DataQueue& data)
{// 接收数据回调
	if (data.empty())
	{
		return;
	}

	sys::StreamWriter* pWriter;

	sys::NetData* netData = data.pop();

	std::map<int, sys::StreamWriter*>::iterator iter = _downloadDatas.find(id);
	if (iter == _downloadDatas.end())
	{// 创建新的接收池
		pWriter = new sys::StreamWriter(netData->data, netData->size);
		_downloadDatas[id] = pWriter;
	}
	else
	{// 追加到已有的接收池中
		pWriter = iter->second;
		pWriter->writeString(netData->data, netData->size);
	}
	SAFE_DELETE(netData);

	HttpResponse* pResp = new HttpResponse();
	int offset = pResp->tryParseMessage(pWriter->getData(), pWriter->getLength());
	if (pResp->isHttpFormat() && pResp->isFullCommand())
	{
		int len = 0;
		if (pResp->getIntegerHeader(HttpResponeField::CONTENT_LENGTH, len))
		{
			if (len == pResp->getBodySize())
			{
				// 下载完毕，断开连接
				if (_downloadCallbacks.find(id) != _downloadCallbacks.end())
				{
					_downloadCallbacks[id].t3->disconnect();
				}
			}
		}
	}

	delete pResp;
}

void HttpDownload::addListen(sys::Client* client, downloadCallback callback, int tag)
{// 添加一个下载监听
	if (client == nullptr || callback == nullptr)
	{
		return;
	}

	_downloadCallbacks[client->getID()] = sys::make_tuple3(tag, callback, client);
}

void HttpDownload::clear()
{
	DownloadCallback::iterator iter2 = _downloadCallbacks.begin();
	while (iter2 != _downloadCallbacks.end())
	{// 关闭线程，注销客户端
		iter2->second.t3->disconnect();
		iter2++;
	}

	std::map<int, sys::StreamWriter*>::iterator iter1 = _downloadDatas.begin();
	while (iter1 != _downloadDatas.end())
	{// 关闭接收数据
		SAFE_DELETE(iter1->second);
		iter1++;
	}

	_downloadDatas.clear();
}