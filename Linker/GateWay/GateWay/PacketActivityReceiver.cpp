#include "PacketActivityReceiver.h"
#include "GateWay.h"

using namespace gw;

int nPacketHeaderSize = sizeof(PacketHeader);
int nUserPacketHeaderSize = sizeof(UserPacketHeader);

void PacketActivityReceiver::doGet(const char* buffer, int size)
{
	if (isGameServer())
	{// ���Է�������������ת���ͻ��� UserPacketHeaderתPacketHeader
		UserPacketHeader* userHeader = (UserPacketHeader*)buffer;
		int sockID = userHeader->Mark;

		PRINT("Receive Packet From Server, Dest ID : %d\n", userHeader->PacketID);

		int nNewPacketSize = size + nPacketHeaderSize - nUserPacketHeaderSize;
		char* stream = (char*)malloc(nNewPacketSize);
		// ����ͷ
		memcpy(stream, buffer, nPacketHeaderSize);
		// ������Ϣ��
		memcpy(stream + nPacketHeaderSize, buffer + nUserPacketHeaderSize, size - nUserPacketHeaderSize);
		// ���ó���
		PacketHeader* header = (PacketHeader*)stream;
		header->Length = nNewPacketSize;

		postToClient(sockID, *header);

		free(stream);
	}
	else
	{// ���Կͻ��ˣ�ת�������� PacketHeaderתUserPacketHeader
		PacketHeader* header = (PacketHeader*)buffer;

		PRINT("Receive Packet From Client ID : %d\n", header->PacketID);

		int sockID = sGateWay->getSocketID(_sessionID.c_str());
		int nNewPacketSize = size + nUserPacketHeaderSize - nPacketHeaderSize;
		char* stream = (char*)malloc(nNewPacketSize);
		// ����ͷ
		memcpy(stream, buffer, nPacketHeaderSize);
		// ������Ϣ��
		memcpy(stream + nUserPacketHeaderSize, buffer + nPacketHeaderSize, size - nPacketHeaderSize);
		// ���ó���
		UserPacketHeader* userHeader = (UserPacketHeader*)stream;
		userHeader->Mark = sockID;
		userHeader->Length = nNewPacketSize;

		// ת����������
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