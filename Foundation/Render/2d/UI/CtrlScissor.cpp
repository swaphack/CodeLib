#include "CtrlScissor.h"

using namespace render;

int render::CtrlScissor::s_nScissorCount = 0;
sys::Rect CtrlScissor::s_rect = sys::Rect::Zero;

CtrlScissor::CtrlScissor()
{

}

CtrlScissor::~CtrlScissor()
{

}

void CtrlScissor::draw()
{
	Node::draw();
}

void CtrlScissor::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	if (Tool::getDimensions() == ED_2D)
	{
		sys::Rect rect = makeRect();

		if (s_nScissorCount == 0)
		{
			s_rect = rect;
		}
		else
		{
			s_rect = s_rect.intersectRect(rect);
		}

		glScissor((int)s_rect.x, (int)s_rect.y, (int)s_rect.width, (int)s_rect.height);

		s_nScissorCount++;

		if (s_nScissorCount == 1)
		{
			glEnable(GL_SCISSOR_TEST);
		}
	}	

	Node::visit();
	if (Tool::getDimensions() == ED_2D)
	{
		s_nScissorCount--;

		if (s_nScissorCount == 0)
		{
			s_rect = sys::Rect::Zero;
			glDisable(GL_SCISSOR_TEST);
		}
	}
}

sys::Rect CtrlScissor::makeRect()
{
	sys::Rect rect;
	rect.x = _realSpaceVertex.leftDown.x;
	rect.y = _realSpaceVertex.leftDown.y;
	rect.width = _realSpaceVertex.rightDown.x - _realSpaceVertex.leftDown.x;
	rect.height = _realSpaceVertex.leftUp.y - _realSpaceVertex.leftDown.y;

	return rect;
}
