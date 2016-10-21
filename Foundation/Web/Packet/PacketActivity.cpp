#include "PacketActivity.h"
#include "PacketRecvHandler.h"
#include "../WebApp/WebApplication.h"

#include <cstring>

using namespace web;

#define G_HTTPAPPLICATION WebApplication::getInstance()->getServer()

PacketActivity::PacketActivity()
{
	G_HTTPAPPLICATION->getPacketListener()->addRecvHandler(this, static_cast<PACKET_RECV_HANDLER>(&PacketActivity::onReceiveRequest));
}

PacketActivity::~PacketActivity()
{
	G_HTTPAPPLICATION->getPacketListener()->removeRecvHandler(this, static_cast<PACKET_RECV_HANDLER>(&PacketActivity::onReceiveRequest));
}

void PacketActivity::onReceiveRequest(const char* sessionID, const char* buffer, int size)
{
	if (sessionID == nullptr || buffer == nullptr || size == 0)
	{
		return;
	}

	_sessionID = sessionID;

	this->doGet(buffer, size);
}

void PacketActivity::doGet(const char* buffer, int size)
{

}

void PacketActivity::doPost(const PacketHeader& packet)
{
	const PacketHeader* pPacket = &packet;
	char* bytes = (char*)malloc(pPacket->Length);
	memset(bytes, 0, pPacket->Length);
	memcpy(bytes, (char*)pPacket, pPacket->Length);
	this->sendResponse(_sessionID.c_str(), bytes, pPacket->Length);
	free(bytes);
}

void PacketActivity::doBroadCast(const PacketHeader& packet)
{
	this->sendBroadcast(_sessionID.c_str(), (char*)&packet, packet.Length);
}

void PacketActivity::sendResponse(const char* sessionID, const char* bytes, int size)
{
	if (sessionID == nullptr || bytes == nullptr || size <= 0)
	{
		return;
	}

	G_HTTPAPPLICATION->postResponse(sessionID, new sys::NetData(bytes, size));
}

void PacketActivity::sendBroadcast(const char* sessionID, const char* bytes, int size)
{
	if (sessionID == nullptr || bytes == nullptr || size <= 0)
	{
		return;
	}
	G_HTTPAPPLICATION->postBroadcast(new sys::NetData(bytes, size));
}

