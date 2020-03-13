#include "CtrlMask.h"

using namespace render;

CtrlMask::CtrlMask()
{
	_blend = { EBFS_DST_COLOR, EBFD_ZERO };
}

CtrlMask::~CtrlMask()
{

}

void CtrlMask::draw()
{
	G_DRAWCOMMANDER->addCommand(DCMask::create(&_rectVertex, getColor(), _opacity, _blend));
}
