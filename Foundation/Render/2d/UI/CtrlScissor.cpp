#include "CtrlScissor.h"

using namespace render;

int render::CtrlScissor::s_nScissorCount = 0;
math::Rect CtrlScissor::s_rect = math::Rect();

CtrlScissor::CtrlScissor()
{

}

CtrlScissor::~CtrlScissor()
{

}

void CtrlScissor::draw()
{
}

void CtrlScissor::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	if (Camera::getMainCamera()->getDimensions() == ED_2D)
	{
		math::Rect rect = makeRect();

		if (s_nScissorCount == 0)
		{
			s_rect = rect;
		}
		else
		{
			s_rect = s_rect.intersectRect(rect);
		}

		glScissor((int)s_rect.getX(), (int)s_rect.getY(), (int)s_rect.getWidth(), (int)s_rect.getHeight());

		s_nScissorCount++;

		if (s_nScissorCount == 1)
		{
			glEnable(GL_SCISSOR_TEST);
		}
	}	

	Node::visit();
	if (Camera::getMainCamera()->getDimensions() == ED_2D)
	{
		s_nScissorCount--;

		if (s_nScissorCount == 0)
		{
			s_rect = math::Rect();
			glDisable(GL_SCISSOR_TEST);
		}
	}
}

math::Rect CtrlScissor::makeRect()
{
	float x = _realSpaceVertex.leftDown.getX();
	float y = _realSpaceVertex.leftDown.getY();
	float w = _realSpaceVertex.rightDown.getX() - _realSpaceVertex.leftDown.getX();
	float h = _realSpaceVertex.leftUp.getY() - _realSpaceVertex.leftDown.getY();

	return math::Rect(x, y, w, h);
}
