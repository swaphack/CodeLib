#include "HttpDownload.h"

#include "Http/import.h"

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

bool HttpDownload::download(const std::string& url, int32_t port, const std::string& filepath, OnHttpDownloadCallback callback, int32_t tag)
{
	if (url.empty() == NULL)
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

	const std::string& request = getCString("GET /%s HTTP/1.1\r\n\r\n", filepath);
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

void HttpDownload::flushListenData(int32_t id)
{// 推送监听到的数据
	std::map<int32_t, StreamWriter*>::iterator iter1 = _downloadDatas.find(id);
	if (iter1 == _downloadDatas.end())
	{// 无缓存数据
		return;
	}

	std::map<int32_t, DownloadSlot >::iterator iter2 = _downloadSlots.find(id);
	if (iter2 == _downloadSlots.end())
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
		(iter2->second.handler.first->*iter2->second.handler.second)(iter2->second.tag, pDoc->getBody());
	}
	delete pDoc;

	// 删除客户端
	SAFE_DELETE(iter2->second.client);
	_downloadSlots.erase(iter2);
	
	// 删除数据
	SAFE_DELETE(iter1->second);
	_downloadDatas.erase(iter1);
}

void HttpDownload::onRecvHandle(int32_t id, DataQueue& data)
{// 接收数据回调
	if (data.empty())
	{
		return;
	}

	StreamWriter* pWriter;

	NetData* netData = data.popData();

	std::map<int32_t, StreamWriter*>::iterator iter = _downloadDatas.find(id);
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
		int32_t len = 0;
		if (pDoc->getIntegerHeader(HttpResponeField::CONTENT_LENGTH, len))
		{
			if (len == pDoc->getBodySize())
			{
				// 下载完毕，断开连接
				if (_downloadSlots.find(id) != _downloadSlots.end())
				{
					_downloadSlots[id].client->disconnect();
				}
			}
		}
	}

	delete pDoc;
}

void HttpDownload::addListen(Client* client, OnHttpDownloadCallback callback, int32_t tag)
{// 添加一个下载监听
	if (client == nullptr)
	{
		return;
	}

	DownloadSlot slot;
	slot.id = client->getID();
	slot.tag = tag;
	slot.client = client;
	slot.handler = callback;

	_downloadSlots[client->getID()] = slot;
}

void HttpDownload::clear()
{
	std::map<int32_t, DownloadSlot >::iterator iter2 = _downloadSlots.begin();
	while (iter2 != _downloadSlots.end())
	{// 关闭线程，注销客户端
		iter2->second.client->disconnect();
		SAFE_DELETE(iter2->second.client);
		iter2++;
	}

	std::map<int32_t, StreamWriter*>::iterator iter1 = _downloadDatas.begin();
	while (iter1 != _downloadDatas.end())
	{// 关闭接收数据
		SAFE_DELETE(iter1->second);
		iter1++;
	}

	_downloadDatas.clear();
}