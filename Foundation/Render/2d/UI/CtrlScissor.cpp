#include "CtrlScissor.h"
#include "Graphic/import.h"
#include "Common/View/Camera.h"

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

		GLState::setScissor(s_rect.getX(), s_rect.getY(), s_rect.getWidth(), s_rect.getHeight());

		s_nScissorCount++;

		if (s_nScissorCount == 1)
		{
			GLState::enable(EnableModel::SCISSOR_TEST);
		}
	}	

	Node::visit();
	if (Camera::getMainCamera()->getDimensions() == ED_2D)
	{
		s_nScissorCount--;

		if (s_nScissorCount == 0)
		{
			s_rect = math::Rect();
			GLState::disable(EnableModel::SCISSOR_TEST);
		}
	}
}

math::Rect CtrlScissor::makeRect()
{
	float x = _realRectVertex.leftDown.getX();
	float y = _realRectVertex.leftDown.getY();
	float w = _realRectVertex.rightDown.getX() - _realRectVertex.leftDown.getX();
	float h = _realRectVertex.leftUp.getY() - _realRectVertex.leftDown.getY();

	return math::Rect(x, y, w, h);
}
