#include "HttpDownload.h"
#include "Http/import.h"
#include "Framework/Object.h"
#include "Net/Client.h"
#include "Net/NetData.h"
#include "Net/DNS.h"
#include "Stream/StreamWriter.h"
#include "Base/macros.h"
#include "Type/String.h"

#include <thread>

#define SLEEP_MILLISECOND 200

using namespace sys;

void HttpDownload::DownloadSlot::hand(const std::string& body)
{
	if (handler.first && handler.second)
	{
		(handler.first->*handler.second)(tag, body);
	}

	if (func)
	{
		func(tag, body);
	}
}
//////////////////////////////////////////////////////////////////////////
HttpDownload::HttpDownload()
{

}

HttpDownload::~HttpDownload()
{
	this->clear();
}

bool HttpDownload::startTask(const std::string& url, const std::string& filepath, HttpDownloadedCallback callback, int32_t tag)
{
	auto pClient = initClient(url);
	if (pClient == nullptr)
	{
		return false;
	}

	this->addListen(pClient, filepath, callback, nullptr, tag);

	return true;
}

bool HttpDownload::startTask(const std::string& url, const std::string& filepath, HttpDownloadedFunc func, int32_t tag)
{
	auto pClient = initClient(url);
	if (pClient == nullptr)
	{
		return false;
	}

	this->addListen(pClient, filepath, HttpDownloadedCallback(), func, tag);

	return true;
}

void HttpDownload::flushData(int32_t id)
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
		iter2->second.hand(pDoc->getBody());
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

	if (_downloadingFunc)
	{
		_downloadingFunc(id, netData->data, netData->size);
	}

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

void HttpDownload::addListen(Client* client, const std::string& localpath, HttpDownloadedCallback callback, HttpDownloadedFunc func, int32_t tag)
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
	slot.func = func;
	slot.localpath = localpath;

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

void HttpDownload::setDownloadingFunc(HttpDownloadingFunc func)
{
	_downloadingFunc = func;
}

Client* HttpDownload::initClient(const std::string& url)
{
	if (url.empty())
	{
		return nullptr;
	}

	std::string ip; 
	int32_t port; 
	std::string filepath; 
	std::string values;

	this->parseHttpURL(url, ip, port, filepath, values);

	Client* client = new Client(ip, port);
	if (!client->connect())
	{
		delete client;
		return nullptr;
	}

	client->setRecvHandler(this, static_cast<CLIENT_RECV_HANDLER>(&HttpDownload::onRecvHandle));

	std::thread th([&](){
		while (client->isConnected())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_MILLISECOND));
			client->update();
		}
		this->flushData(client->getID());
	});
	th.detach();

	const std::string& request = getCString("GET /%s HTTP/1.1\r\n\r\n", filepath);
	client->sendString(request);

	return client;
}

void sys::HttpDownload::parseHttpURL(const std::string& url, std::string& ip, int32_t& port, std::string& filepath, std::string& values)
{
	String content = url.c_str();
	String low = content.toLower();
	if (!low.startWith(HttpConstant::HTTP_HTTP) && !low.startWith(HttpConstant::HTTP_HTTPS))
	{
		return;
	}

	int len = 0;
	std::vector<String> params;
	if (low.startWith(HttpConstant::HTTP_HTTP))
	{
		len = strlen(HttpConstant::HTTP_HTTP);
		len = len + 3;
		content = content.subString(len, content.getSize() - len);

		port = 80;
	}
	else if (low.startWith(HttpConstant::HTTP_HTTPS))
	{
		len = strlen(HttpConstant::HTTP_HTTPS);
		len = len + 3;
		content = content.subString(len, content.getSize() - len);
		port = 443;
	}
	else
	{
		return;
	}

	int idx = content.findFirstOf('/');
	if (idx == -1) return;
	String value = content.subString(0, idx);
	int nPort = 0;
	sys::DNS::getFirstIPAddress(value.getString(), ip, nPort);

	content = content.subString(idx + 1, content.getSize() - (idx + 1));
	idx = content.findFirstOf('?');
	if (idx == -1) return;
	value = content.subString(0, idx);
	filepath = value.getString();

	content = content.subString(idx + 1, content.getSize() - (idx + 1));
	values = content.getString();
}
