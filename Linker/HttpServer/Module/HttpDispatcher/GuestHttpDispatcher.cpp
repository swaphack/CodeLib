#include "GuestHttpDispatcher.h"

using namespace hs;


GuestHttpDispatcher::GuestHttpDispatcher()
{

}

GuestHttpDispatcher::~GuestHttpDispatcher()
{

}

bool GuestHttpDispatcher::hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response)
{
	return false;
}
