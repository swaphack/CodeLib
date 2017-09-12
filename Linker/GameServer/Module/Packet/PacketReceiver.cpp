#include "PacketReceiver.h"
#include "PacketDispatcher.h"

using namespace gs;

void PacketReceiver::doGet(const char* buffer, int size)
{
	UserPacketHeader* header = (UserPacketHeader*)buffer;

	PRINT("Receive Client :%d Packet : %d\n", header->Mark, header->PacketID);

	PacketDispatcher::getInstance()->dispathPacket(*header);
	/*
	UserPacketHeader* pResponse =
	if (pResponse)
	{
		doPost(*pResponse);
	}
	else
	{
		UserPacketHeader packet;
		packet->Mark = header->Mark;
		doPost(packet);
	}
	*/
}
