#include "PacketReceiver.h"
#include "PacketDispatcher.h"

using namespace gs;

void PacketReceiver::doGet(const char* buffer, int size)
{
	UserPacketHeader* header = (UserPacketHeader*)buffer;

	PRINT("Receive Client :%d Packet : %d\n", header->Mark, header->PacketID);

	UserPacketHeader* pResponse = PacketDispatcher::getInstance()->dispathPacket(*header);
	if (pResponse)
	{
		doPost(*pResponse);
	}
	else
	{
		UserPacketHeader* packet = new UserPacketHeader();
		packet->Mark = header->Mark;
		doPost(*packet);
		delete packet;
	}
}
