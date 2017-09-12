#include "PacketProtocol.h"
#include "PacketDispatcher.h"

using namespace gs;

void PacketProtocol::unregisterPacketHandler()
{
	PacketDispatcher::getInstance()->unregisterPacketHandler(this);
}
