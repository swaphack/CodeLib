#include "HttpActivityListener.h"

using namespace web;

HttpActivityListener::HttpActivityListener()
{
	_httpReqDoc = new sys::HttpReqDocument();
}

HttpActivityListener::~HttpActivityListener()
{
	delete _httpReqDoc;
}

void HttpActivityListener::addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	HttpRecvHandler singleHandler;
	singleHandler.first = target;
	singleHandler.second = handler;

	_recvHandlers.push_back(singleHandler);
}

void HttpActivityListener::removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	std::vector<HttpRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		if (it->first == target && it->second == handler)
		{
			_recvHandlers.erase(it);
			break;
		}
		it++;
	}
}

bool HttpActivityListener::onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize)
{
	sys::HttpRequest* request = createRequest(sessionID, dataQueue, packetSize);
	if (request == nullptr)
	{
		return false;
	}

	if (request->getDocument()->getStreamSize() == 0)
	{
		return false;
	}

	this->onRecvHander(request);

	delete request;

	return true;
}

void HttpActivityListener::onRecvHander(sys::HttpRequest* data)
{
	std::vector<HttpRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
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
	sys::NetData* netData = dataQueue.top();
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

	if (cursor > netData->size)
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