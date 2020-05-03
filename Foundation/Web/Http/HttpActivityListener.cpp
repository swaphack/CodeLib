#include "HttpActivityListener.h"

using namespace web;

HttpActivityListener::HttpActivityListener()
{
	_httpReqDoc = new sys::HttpReqDocument();
	_httpRespDoc = new sys::HttpRespDocument();
}

HttpActivityListener::~HttpActivityListener()
{
	delete _httpReqDoc;
	delete _httpRespDoc;
}

void HttpActivityListener::addRecvHandler(sys::Object* target, HTTP_RECV_REQUEST_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	HttpRecvRequestHandler singleHandler;
	singleHandler.first = target;
	singleHandler.second = handler;

	_recvRequestHandlers.push_back(singleHandler);
}

void HttpActivityListener::removeRecvHandler(sys::Object* target, HTTP_RECV_REQUEST_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	std::vector<HttpRecvRequestHandler>::iterator it = _recvRequestHandlers.begin();
	while (it != _recvRequestHandlers.end())
	{
		if (it->first == target && it->second == handler)
		{
			_recvRequestHandlers.erase(it);
			break;
		}
		it++;
	}
}

void HttpActivityListener::addRecvHandler(sys::Object* target, HTTP_RECV_RESPONE_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	HttpRecvResponseHandler singleHandler;
	singleHandler.first = target;
	singleHandler.second = handler;

	_recvResponseHandlers.push_back(singleHandler);
}

void HttpActivityListener::removeRecvHandler(sys::Object* target, HTTP_RECV_RESPONE_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	std::vector<HttpRecvResponseHandler>::iterator it = _recvResponseHandlers.begin();
	while (it != _recvResponseHandlers.end())
	{
		if (it->first == target && it->second == handler)
		{
			_recvResponseHandlers.erase(it);
			break;
		}
		it++;
	}
}

bool HttpActivityListener::onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize)
{
	sys::HttpRequest* request = createRequest(sessionID, dataQueue, packetSize);
	if (request 
		&& request->getDocument()->getStreamSize() > 0)
	{
		this->onRecvHander(request);
		delete request;
		return true;
	}

	sys::HttpResponse* response = createResponse(sessionID, dataQueue, packetSize);
	if (response
		&& response->getDocument()->getStreamSize() > 0)
	{
		this->onRecvHander(response);
		delete response;
		return true;
	}

	return false;
}

void HttpActivityListener::onRecvHander(sys::HttpRequest* data)
{
	std::vector<HttpRecvRequestHandler>::iterator it = _recvRequestHandlers.begin();
	while (it != _recvRequestHandlers.end())
	{
		(it->first->*it->second)(data->getSessionID(), data);
		it++;
	}
}

void HttpActivityListener::onRecvHander(sys::HttpResponse* data)
{
	std::vector<HttpRecvResponseHandler>::iterator it = _recvResponseHandlers.begin();
	while (it != _recvResponseHandlers.end())
	{
		(it->first->*it->second)(data->getSessionID(), data);
		it++;
	}
}

sys::HttpRequest* HttpActivityListener::createRequest(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize)
{
	packetSize = 0;

	if (sessionID == nullptr)
	{
		return nullptr;
	}
	sys::NetData* netData = dataQueue.topData();
	if (netData == nullptr)
	{
		return nullptr;
	}
	if (!_httpReqDoc->parseRequest(netData->getCursorPtr(), netData->getRemainSize()))
	{
		return nullptr;
	}

	sys::HttpReqDocument* pDoc = new sys::HttpReqDocument();
	pDoc->parseRequest(netData->getCursorPtr(), netData->getRemainSize());

	int parseLen = pDoc->getStreamSize();
	int cursor = parseLen + netData->pos;

	if (cursor > netData->getSize())
	{
		delete pDoc;
		return nullptr;
	}

	sys::HttpRequest* pReq = new sys::HttpRequest();
	pReq->setDocument(pDoc);
	pReq->setSessionID(sessionID);

	packetSize = parseLen;

	return pReq;
}

sys::HttpResponse* HttpActivityListener::createResponse(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize)
{
	packetSize = 0;

	if (sessionID == nullptr)
	{
		return nullptr;
	}
	sys::NetData* netData = dataQueue.topData();
	if (netData == nullptr)
	{
		return nullptr;
	}
	if (!_httpRespDoc->parseResponse(netData->getCursorPtr(), netData->getRemainSize()))
	{
		return nullptr;
	}

	sys::HttpRespDocument* pDoc = new sys::HttpRespDocument();
	pDoc->parseResponse(netData->getCursorPtr(), netData->getRemainSize());

	int parseLen = pDoc->getStreamSize();
	int cursor = parseLen + netData->pos;

	if (cursor > netData->getSize())
	{
		delete pDoc;
		return nullptr;
	}

	sys::HttpResponse* pReq = new sys::HttpResponse();
	pReq->setDocument(pDoc);
	pReq->setSessionID(sessionID);

	packetSize = parseLen;

	return pReq;
}