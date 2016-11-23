#include "GUID.h"

using namespace render;

int GUID::s_nID = 0;

GUID::GUID()
{

}

GUID::~GUID()
{

}

int GUID::getID()
{
	return ++s_nID;
}

void GUID::reset()
{
	s_nID = 0;
}
