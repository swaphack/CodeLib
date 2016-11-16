#include "PacketActivityReceiver.h"
#include "GateWay.h"

using namespace gw;

int nPacketHeaderSize = sizeof(PacketHeader);
int nUserPacketHeaderSize = sizeof(UserPacketHeader);

void PacketActivityReceiver::doGet(const char* buffer, int size)
{
	if (isGameServer())
	{// 来自服务器服务器，转给客户端 UserPacketHeader转PacketHeader
		UserPacketHeader* userHeader = (UserPacketHeader*)buffer;
		int sockID = userHeader->Mark;

		PRINT("Receive Packet From Server, Dest ID : %d\n", userHeader->PacketID);

		int nNewPacketSize = size + nPacketHeaderSize - nUserPacketHeaderSize;
		char* stream = (char*)malloc(nNewPacketSize);
		// 复制头
		memcpy(stream, buffer, nPacketHeaderSize);
		// 复制消息体
		memcpy(stream + nPacketHeaderSize, buffer + nUserPacketHeaderSize, size - nUserPacketHeaderSize);
		// 设置长度
		PacketHeader* header = (PacketHeader*)stream;
		header->Length = nNewPacketSize;

		postToClient(sockID, *header);

		free(stream);
	}
	else
	{// 来自客户端，转给服务器 PacketHeader转UserPacketHeader
		PacketHeader* header = (PacketHeader*)buffer;

		PRINT("Receive Packet From Client ID : %d\n", header->PacketID);

		int sockID = sGateWay->getSocketID(_sessionID.c_str());
		int nNewPacketSize = size + nUserPacketHeaderSize - nPacketHeaderSize;
		char* stream = (char*)malloc(nNewPacketSize);
		// 复制头
		memcpy(stream, buffer, nPacketHeaderSize);
		// 复制消息体
		memcpy(stream + nUserPacketHeaderSize, buffer + nPacketHeaderSize, size - nPacketHeaderSize);
		// 设置长度
		UserPacketHeader* userHeader = (UserPacketHeader*)stream;
		userHeader->Mark = sockID;
		userHeader->Length = nNewPacketSize;

		// 转发给服务器
		postToGameServer(*userHeader);

		free(stream);
	}
}

void PacketActivityReceiver::postToGameServer(const PacketHeader& packet)
{
	doPost(sGateWay->getGameServerListenerID(), packet);
}

void PacketActivityReceiver::postToClient(int socketID, const PacketHeader& packet)
{
	doPost(socketID, packet);
}

bool PacketActivityReceiver::isGameServer()
{
	int socketID = sGateWay->getSocketID(_sessionID.c_str());
	return socketID == sGateWay->getGameServerListenerID();
}