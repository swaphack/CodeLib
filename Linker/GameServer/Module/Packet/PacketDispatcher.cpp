#include "PacketDispatcher.h"
#include "web.h"
using namespace web;
using namespace gs;

PacketDispatcher::PacketDispatcher()
{

}

PacketDispatcher::~PacketDispatcher()
{

}

PacketDispatcher* PacketDispatcher::getInstance()
{
	static PacketDispatcher* s_PacketDispatcher = nullptr;
	if (s_PacketDispatcher == nullptr)
	{
		s_PacketDispatcher = new PacketDispatcher();
	}

	return s_PacketDispatcher;
}

void PacketDispatcher::setPacketHandler(PacketHandler handler)
{
	m_PacketHandler = handler;
}

web::UserPacketHeader* PacketDispatcher::dispathPacket(const web::UserPacketHeader& header)
{
	return nullptr;
}
