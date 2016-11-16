#include "TextActivityListener.h"
#include "GateWay.h"
using namespace gw;


TextActivityListener::TextActivityListener()
{

}

TextActivityListener::~TextActivityListener()
{

}

bool TextActivityListener::onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize)
{
	sys::NetData* top = dataQueue.top();
	std::string recvData = std::string(top->data, top->size);
	PRINT("Receive : %s\n", recvData.c_str());
// 	dataQueue.pop();
// 	delete top;

	packetSize = top->size;

	sGateWay->postResponse(sessionID, new sys::NetData(recvData.c_str(), recvData.size()));

	return true;
}
