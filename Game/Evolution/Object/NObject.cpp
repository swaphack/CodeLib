#include "NObject.h"

using namespace nature;

NObject::NObject()
{

}

NObject::~NObject()
{
	
}

bool NObject::init()
{
	return true;
}

void NObject::destory()
{
	delete this;
}