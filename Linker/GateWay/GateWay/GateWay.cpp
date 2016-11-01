#include "GateWay.h"

using namespace web;
using namespace gw;

GateWay::GateWay(const char* ip, int port, int maxWaitCount)
:WebApplication(ip, port, maxWaitCount)
{
}

GateWay::~GateWay()
{

}

void GateWay::init()
{
	WebApplication::init();
}
