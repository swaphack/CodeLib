#include "NMark.h"

using namespace nature;


NMark::NMark()
{
	_ID = 0;
	_name = "";
}

NMark::~NMark()
{

}

void NMark::setID(int ID)
{
	_ID = ID;
}

int NMark::getID()
{
	return _ID;
}

void NMark::setName(const char* name)
{
	if (name)
	{
		_name = name;
	}
}

const char* NMark::getName()
{
	return _name.c_str();
}
