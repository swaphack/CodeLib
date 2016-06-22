#pragma once

#include "CtrlStencil.h"

using namespace render;

int CtrlStencil::g_mask = 1;


CtrlStencil::CtrlStencil()
:_stencilNode(nullptr)
, _mask(1)
{
	//_color.alpha = 0;
}

CtrlStencil::~CtrlStencil()
{
	SAFE_RELEASE(_stencilNode);
}

void CtrlStencil::draw()
{
	ColorNode::draw();
}

void CtrlStencil::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	if (isDirty())
	{
		this->initSelf();

		setDirty(false);
	}

	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_NEVER, 0x0, 0xFF);
	glStencilOp(GL_INCR, GL_INCR, GL_INCR);

	glPushMatrix();
	this->updateSelf();
	if (_children.count() == 0)
	{
		this->draw();
	}
	else
	{
		bool show = false;
		std::vector<Object*>::iterator iter = _children.begin();
		while (iter != _children.end())
		{
			Node* node = dynamic_cast<Node*>(*iter);
			if (show == false && node->getZOrder() >= 0)
			{
				this->draw();
				show = true;
			}
			node->visit();
			iter++;
		}
	}

	glStencilFunc(GL_NOTEQUAL, 0x01, 0xFF);
	glStencilOp(GL_INCR, GL_INCR, GL_INCR);
	if (_stencilNode)
	{
		_stencilNode->visit();
		
	}

	glPopMatrix();
}

void CtrlStencil::setStencilNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	SAFE_RETAIN(node);
	SAFE_RELEASE(_stencilNode);
	_stencilNode = node;
}


