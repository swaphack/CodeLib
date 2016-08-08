#include "Target.h"

using namespace slg;

int Target::g_TargetID = 0;

Target::Target()
{
	g_TargetID++;
	this->setID(g_TargetID);
}

Target::~Target()
{

}
