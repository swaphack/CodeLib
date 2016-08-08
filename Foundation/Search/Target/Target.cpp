#include "Target.h"

using namespace search;


Target::Target()
{

}

Target::~Target()
{

}

const char* Target::getString()
{
	return "";
}

void Target::dispose()
{
	delete this;
}
