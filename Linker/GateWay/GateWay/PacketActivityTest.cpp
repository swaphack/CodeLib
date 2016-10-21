#include "PacketActivityTest.h"

void PacketActivityTest::doGet(const char* buffer, int size)
{
	PacketHeader* header = (PacketHeader*)buffer;

	PRINT("Receive Packet ID : %d\n", header->PacketID);

	if (header->PacketID == PacketID::Login)
	{
		ReqPacketLogin* reqPacket = (ReqPacketLogin*)buffer;
		
		PRINT("Name %s, Pwd %s\n", reqPacket->Name, reqPacket->Password);

		RespPacketPlayerInfo respPacket;
		respPacket.PlayerID = 1;
		respPacket.Level = 1;
		respPacket.Experience = 0;

		doPost(respPacket);
	}
}
