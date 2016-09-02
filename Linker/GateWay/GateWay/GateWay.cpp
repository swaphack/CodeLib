#include "GateWay.h"

using namespace web;
using namespace gw;

GateWay::GateWay(const char* ip, int port)
:WebApplication(ip, port)
{
	this->init();
}

GateWay::~GateWay()
{

}

void GateWay::init()
{
	WebApplication::init();

	
}
