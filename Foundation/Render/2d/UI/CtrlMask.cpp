#include "CtrlMask.h"
#include "Graphic/import.h"
using namespace render;

CtrlMask::CtrlMask()
{
}

CtrlMask::~CtrlMask()
{

}

void CtrlMask::drawSample()
{
	GLVertex::drawRect(_rectVertex);
}
