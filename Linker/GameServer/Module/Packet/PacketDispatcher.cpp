#include "PacketDispatcher.h"
#include "PacketProtocol.h"
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

void PacketDispatcher::registerPacketHandler(PacketProtocol* protocol, int packetID, PacketHandler handler)
{
	if (protocol == nullptr || handler == nullptr)
	{
		return;
	}

	if (_packetHandlers.find(packetID) == _packetHandlers.end())
	{
		_packetHandlers[packetID] = std::map<PacketProtocol*, PacketHandler>();
	}

	_packetHandlers[packetID][protocol] = handler;

	_protocolHandlers[protocol][packetID] = handler;
}

void PacketDispatcher::unregisterPacketHandler(PacketProtocol* protocol, int packetID)
{
	if (protocol == nullptr)
	{
		return;
	}

	if (_packetHandlers.find(packetID) == _packetHandlers.end())
	{
		return;
	}

	_packetHandlers[packetID].erase(protocol);
	_protocolHandlers[protocol].erase(packetID);
}

void gs::PacketDispatcher::unregisterPacketHandler(PacketProtocol* protocol)
{
	if (protocol == nullptr)
	{
		return;
	}

	for (std::map<int, PacketHandler>::const_iterator cit = _protocolHandlers[protocol].begin();
		cit != _protocolHandlers[protocol].end();
		cit++)
	{
		_packetHandlers[cit->first].erase(protocol);
	}

	_protocolHandlers.erase(protocol);
}

void PacketDispatcher::clearPacketHandler()
{
	_packetHandlers.clear();
	_protocolHandlers.clear();
}

void PacketDispatcher::dispathPacket(const web::UserPacketHeader& header)
{
	if (_packetHandlers.find(header.PacketID) == _packetHandlers.end())
	{
		return;
	}

	for (std::map<PacketProtocol*, PacketHandler>::const_iterator cit = _packetHandlers[header.PacketID].begin();
		cit != _packetHandlers[header.PacketID].end();
		cit++)
	{
		((cit->first)->*cit->second)(header);
	}
}
