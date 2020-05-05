#include "PacketActivity.h"
#include "PacketRecvHandler.h"
#include "WebApp/WebApplication.h"
#include "PacketActivityListener.h"
#include "PacketHeader.h"

#include <cstring>

using namespace web;

#define G_HTTPAPPLICATION WebApplication::getInstance()

PacketActivity::PacketActivity()
{
	G_HTTPAPPLICATION->getPacketListener()->addRecvHandler(this, static_cast<PACKET_RECV_HANDLER>(&PacketActivity::onReceiveRequest));
}

PacketActivity::~PacketActivity()
{
	G_HTTPAPPLICATION->getPacketListener()->removeRecvHandler(this, static_cast<PACKET_RECV_HANDLER>(&PacketActivity::onReceiveRequest));
}

void PacketActivity::onReceiveRequest(const std::string& sessionID, const char* buffer, int size)
{
	if (sessionID.empty() || buffer == nullptr || size == 0)
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
	G_HTTPAPPLICATION->postResponse(_sessionID.c_str(), new sys::NetData(bytes, pPacket->Length));

	free(bytes);
}

void PacketActivity::doPost(int destID, const PacketHeader& packet)
{
	const PacketHeader* pPacket = &packet;
	char* bytes = (char*)malloc(pPacket->Length);
	memset(bytes, 0, pPacket->Length);
	memcpy(bytes, (char*)pPacket, pPacket->Length);

	G_HTTPAPPLICATION->postResponse(destID, new sys::NetData(bytes, pPacket->Length));

	free(bytes);
}

void PacketActivity::doBroadCast(const PacketHeader& packet)
{
	const PacketHeader* pPacket = &packet;
	char* bytes = (char*)malloc(pPacket->Length);
	memset(bytes, 0, pPacket->Length);
	memcpy(bytes, (char*)pPacket, pPacket->Length);

	G_HTTPAPPLICATION->postBroadcast(new sys::NetData(bytes, pPacket->Length));

	free(bytes);
}

