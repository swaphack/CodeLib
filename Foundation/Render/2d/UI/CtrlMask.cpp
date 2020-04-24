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
	GLVertex::beginMode(ShapeMode::QUADS);

	GLVertex::setVertex(_rectVertex.leftDown);
	GLVertex::setVertex(_rectVertex.rightDown);
	GLVertex::setVertex(_rectVertex.rightUp);
	GLVertex::setVertex(_rectVertex.leftUp);

	GLVertex::endMode();;
}
