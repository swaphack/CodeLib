#include "PacketActivityListener.h"
#include "PacketHeader.h"
using namespace web;

PacketActivityListener::PacketActivityListener()
{

}

PacketActivityListener::~PacketActivityListener()
{

}

void PacketActivityListener::addRecvHandler(sys::Object* target, PACKET_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	PacketRecvHandler singleHandler;
	singleHandler.first = target;
	singleHandler.second = handler;

	_recvHandlers.push_back(singleHandler);
}

void PacketActivityListener::removeRecvHandler(sys::Object* target, PACKET_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	std::vector<PacketRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		if (it->first == target && it->second == handler)
		{
			_recvHandlers.erase(it);
			break;
		}
		it++;
	}
}

bool PacketActivityListener::onDispatch(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize)
{
	if (sessionID.empty())
	{
		return false;
	}

	const char* buffer = createRequest(sessionID, dataQueue, packetSize);
	if (buffer == nullptr)
	{
		return false;
	}

	this->onRecvHander(sessionID, buffer, packetSize);

	return true;
}

void PacketActivityListener::onRecvHander(const std::string& sessionID, const char* buffer, int size)
{
	if (sessionID.empty() || buffer == nullptr || size == 0)
	{
		return;
	}

	std::vector<PacketRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		(it->first->*it->second)(sessionID, buffer, size);
		it++;
	}
}

const char* PacketActivityListener::createRequest(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize)
{
	packetSize = 0;

	if (sessionID.empty())
	{
		return nullptr;
	}

	sys::NetData* netData = dataQueue.topData();
	if (netData == nullptr)
	{
		return nullptr;
	}

	int size = sizeof(PacketHeader);
	if (netData->getRemainSize() < size)
	{
		return nullptr;
	}

	PacketHeader* header = (PacketHeader*)netData->getCursorPtr();

	int parseLen = header->Length;
	int cursor = netData->pos + parseLen;
	if (cursor > netData->getSize())
	{
		return nullptr;
	}

	packetSize = parseLen;

	return netData->getCursorPtr();
}