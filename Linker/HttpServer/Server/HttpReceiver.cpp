#include "HttpReceiver.h"
#include "HttpHandler.h"

using namespace hs;

#define G_RESOURCE WebApplication::getInstance()->getResourceMgr()->getResource(ERT_LOCAL)
#define G_HANDLER HttpHandler::getInstance()

HttpReceiver::HttpReceiver()
{
	G_HANDLER->addDispatcher();
}

void HttpReceiver::doGetRequest(sys::HttpRequest* request)
{
	HttpResponse response;
	response.getDocument()->setHeader("ClientID", request->getDocument()->getHeader("ClientID"));
	response.getDocument()->setResource(G_RESOURCE);

	// HTTP�ɷ�����
	G_HANDLER->dispatch(request, response);
	// ���͸��ͻ���
	this->doPostResponse(&response);
}
