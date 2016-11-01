#include "WebApplication.h"

using namespace web;

static WebApplication* s_pWebApplication = nullptr;
//////////////////////////////////////////////////////////////////////////
WebApplication::WebApplication( const char* ip, int port, int maxWaitCount )
:_ip(ip)
,_port(port)
,_maxWaitCount(maxWaitCount)
,_server(nullptr)
{
	ASSERT(s_pWebApplication == nullptr);

	s_pWebApplication = this;

	sys::Socket::InitSockModule();

	this->init();
}

WebApplication::~WebApplication()
{
	this->disponse();

	sys::Socket::ReleaseSockModule();

	s_pWebApplication = nullptr;
}

WebApplication* WebApplication::getInstance()
{
	return s_pWebApplication;
}

WebServer* WebApplication::getServer()
{
	return _server;
}

WebClient* WebApplication::getClient()
{
	return _client;
}

sys::ResourceMgr* WebApplication::getResourceMgr()
{
	return _resource;
}

HttpActivityListener* WebApplication::getHttpListener()
{
	return static_cast<HttpActivityListener*>(_listenerPool->getListener(_httpListenerID));
}

PacketActivityListener* WebApplication::getPacketListener()
{
	return static_cast<PacketActivityListener*>(_listenerPool->getListener(_packetListenerID));
}

void WebApplication::postResponse(const char* sessionID, sys::NetData* data)
{
	if (sessionID == nullptr || data == nullptr)
	{
		return;
	}

	ClientSession* client = _session->getSession(sessionID);
	if (client == nullptr)
	{
		return;
	}

	_server->postResponse(client->clientID, data);
}

void WebApplication::postResponse(int clientID, sys::NetData* data)
{
	if (data == nullptr)
	{
		return;
	}

// 	ClientSession* client = _session->getSession(clientID);
// 	if (client == nullptr)
// 	{
// 		return;
// 	}

	_server->postResponse(clientID, data);
}

void WebApplication::postBroadcast(sys::NetData* data)
{
	if (data == nullptr)
	{
		return;
	}

	_server->postBroadcast(data);
}

void WebApplication::init()
{
	_resource = new sys::ResourceMgr();

	_listenerPool = new ListenerPool();
	_httpListenerID = _listenerPool->addListener(new HttpActivityListener());
	_packetListenerID = _listenerPool->addListener(new PacketActivityListener());

	
	_server = new WebServer();
	_server->setRecvHandler(this, static_cast<sys::SERVER_RECV_HANDLER>(&WebApplication::parseReceivedData));
	_server->setCloseHandler(this, static_cast<sys::CLIENT_CLOSE_HANDLER>(&WebApplication::closeClient));

	_server->createServer(_ip.c_str(), _port, _maxWaitCount);

	_client = new WebClient();
	_client->setRecvHandler(this, static_cast<sys::CLIENT_RECV_HANDLER>(&WebApplication::parseReceivedData));
	_client->setCloseHandler(this, static_cast<sys::CLIENT_CLOSE_HANDLER>(&WebApplication::closeClient));

	_session = new Sessions();
}

void WebApplication::update()
{
	if (_server)
	{
		_server->update();
	}

	if (_client)
	{
		_client->update();
	}

	checkAutoRealsePool();
}

void WebApplication::dispose()
{
	SAFE_DELETE(_server);
	SAFE_DELETE(_resource);
	SAFE_DELETE(_client);
	SAFE_DELETE(_listenerPool);
	SAFE_DELETE(_session);
}

void WebApplication::parseReceivedData(int id, sys::DataQueue& dataQueue)
{
	std::string sessionID;
	sys::BitConvert::getNumberString(id, sessionID);

	ClientSession client;
	client.sessionID = sessionID;
	client.clientID = id;

	// 服务端session
	_session->addSession(client.sessionID.c_str(), client);

	if (_listenerPool->onDispatch(sessionID.c_str(), dataQueue))
	{
	}
	else
	{ // 错误数据
	}
}

void WebApplication::closeClient(int id)
{
	// 服务端session
	_session->removeClient(id);
}
