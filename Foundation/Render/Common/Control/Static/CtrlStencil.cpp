#pragma once

#include "CtrlStencil.h"

using namespace render;


CtrlStencil::CtrlStencil()
{
	//_color.alpha = 0;
}

CtrlStencil::~CtrlStencil()
{

}

void CtrlStencil::draw()
{
	ColorNode::draw();

	GLTool::beginBlend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLTool::setColor(_color);
	GLTool::drawRect(&_rectVertex, GL_QUADS);
	GLTool::endBlend();
}

void CtrlStencil::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	glPushMatrix();

	if (isDirty())
	{
		this->initSelf();

		setDirty(false);
	}

	this->updateSelf();

	glEnable(GL_STENCIL_TEST);

	glStencilFunc(GL_NEVER, 0x0, 0x0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	std::vector<Object*>::iterator iter = _children.begin();
	while (iter != _children.end())
	{
		Node* node = dynamic_cast<Node*>(*iter);
		node->visit();
		iter++;
	}

	glStencilFunc(GL_NOTEQUAL, 0x1, 0x3);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	this->draw();

	//glDisable(GL_STENCIL_TEST);

	glPopMatrix();
}


