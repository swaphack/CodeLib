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
{// ���ͼ�����������
	std::map<int32_t, StreamWriter*>::iterator iter1 = _downloadDatas.find(id);
	if (iter1 == _downloadDatas.end())
	{// �޻�������
		return;
	}

	std::map<int32_t, DownloadSlot >::iterator iter2 = _downloadSlots.find(id);
	if (iter2 == _downloadSlots.end())
	{// �����ؼ���
		SAFE_DELETE(iter1->second);
		_downloadDatas.erase(iter1);
		return;
	}

	// http����
	HttpRespDocument* pDoc = new HttpRespDocument();
	if (pDoc->parseResponse(iter1->second->getData(), iter1->second->getLength()))
	{
		// ������http
		(iter2->second.handler.first->*iter2->second.handler.second)(iter2->second.tag, pDoc->getBody());
	}
	delete pDoc;

	// ɾ���ͻ���
	SAFE_DELETE(iter2->second.client);
	_downloadSlots.erase(iter2);
	
	// ɾ������
	SAFE_DELETE(iter1->second);
	_downloadDatas.erase(iter1);
}

void HttpDownload::onRecvHandle(int32_t id, DataQueue& data)
{// �������ݻص�
	if (data.empty())
	{
		return;
	}

	StreamWriter* pWriter;

	NetData* netData = data.popData();

	std::map<int32_t, StreamWriter*>::iterator iter = _downloadDatas.find(id);
	if (iter == _downloadDatas.end())
	{// �����µĽ��ճ�
		pWriter = new StreamWriter(netData->data, netData->size);
		_downloadDatas[id] = pWriter;
	}
	else
	{// ׷�ӵ����еĽ��ճ���
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
				// ������ϣ��Ͽ�����
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
{// ���һ�����ؼ���
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
	{// �ر��̣߳�ע���ͻ���
		iter2->second.client->disconnect();
		SAFE_DELETE(iter2->second.client);
		iter2++;
	}

	std::map<int32_t, StreamWriter*>::iterator iter1 = _downloadDatas.begin();
	while (iter1 != _downloadDatas.end())
	{// �رս�������
		SAFE_DELETE(iter1->second);
		iter1++;
	}

	_downloadDatas.clear();
}