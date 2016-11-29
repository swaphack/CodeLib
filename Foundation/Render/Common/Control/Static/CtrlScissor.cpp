#include "CtrlScissor.h"

using namespace render;


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

	GLboolean isScissorEnable = GL_FALSE;
	isScissorEnable = glIsEnabled(GL_SCISSOR_TEST);

	if (Tool::getDimensions() == ED_2D)
	{
		glScissor(static_cast<int>(_realSpaceVertex.leftDown.x),
			static_cast<int>(_realSpaceVertex.leftDown.y),
			static_cast<int>(_realSpaceVertex.rightDown.x - _realSpaceVertex.leftDown.x),
			static_cast<int>(_realSpaceVertex.leftUp.y - _realSpaceVertex.leftDown.y));

		glEnable(GL_SCISSOR_TEST);
	}

	Node::visit();

	if (isScissorEnable == GL_FALSE)
	{
		glDisable(GL_SCISSOR_TEST);
	}
}
