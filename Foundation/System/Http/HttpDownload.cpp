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
{// ���ͼ�����������
	std::map<int, StreamWriter*>::iterator iter1 = _downloadDatas.find(id);
	if (iter1 == _downloadDatas.end())
	{// �޻�������
		return;
	}

	DownloadCallback::iterator iter2 = _downloadCallbacks.find(id);
	if (iter2 == _downloadCallbacks.end())
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
		(iter2->second.t2.first->*iter2->second.t2.second)(iter2->second.t1, pDoc->getBody(), pDoc->getBodySize());
	}
	delete pDoc;

	// ɾ���ͻ���
	SAFE_DELETE(iter2->second.t3);
	_downloadCallbacks.erase(iter2);
	
	// ɾ������
	SAFE_DELETE(iter1->second);
	_downloadDatas.erase(iter1);
}

void HttpDownload::onRecvHandle(int id, DataQueue& data)
{// �������ݻص�
	if (data.empty())
	{
		return;
	}

	StreamWriter* pWriter;

	NetData* netData = data.pop();

	std::map<int, StreamWriter*>::iterator iter = _downloadDatas.find(id);
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
		int len = 0;
		if (pDoc->getIntegerHeader(HttpResponeField::CONTENT_LENGTH, len))
		{
			if (len == pDoc->getBodySize())
			{
				// ������ϣ��Ͽ�����
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
{// ���һ�����ؼ���
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
	{// �ر��̣߳�ע���ͻ���
		iter2->second.t3->disconnect();
		SAFE_DELETE(iter2->second.t3);
		iter2++;
	}

	std::map<int, StreamWriter*>::iterator iter1 = _downloadDatas.begin();
	while (iter1 != _downloadDatas.end())
	{// �رս�������
		SAFE_DELETE(iter1->second);
		iter1++;
	}

	_downloadDatas.clear();
}