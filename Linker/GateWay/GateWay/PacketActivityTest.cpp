#include "PacketActivityTest.h"

void PacketActivityTest::doGet(const char* buffer, int size)
{
	PacketHeader* header = (PacketHeader*)buffer;

	PRINT("Receive Packet ID : %d\n", header->PacketID);

	// ×ª·¢
	doPost(*header);
}
