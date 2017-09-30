#pragma once

#include "Stencil.h"

using namespace render;

static int s_ref = 0;


Stencil::Stencil()
:_stencilNode(nullptr)
{
	_ref = s_ref++;
}

Stencil::~Stencil()
{
	SAFE_RELEASE(_stencilNode);
}

void showStencilInformation()
{
	int value = 0;
	glGetIntegerv(GL_STENCIL_FUNC, &value);
	PRINT("GL_STENCIL_FUNC %d\n", value);
	glGetIntegerv(GL_STENCIL_REF, &value);
	PRINT("GL_STENCIL_REF %d\n", value);
	glGetIntegerv(GL_STENCIL_VALUE_MASK, &value);
	PRINT("GL_STENCIL_VALUE_MASK %d\n", value);
	glGetIntegerv(GL_STENCIL_FAIL, &value);
	PRINT("GL_STENCIL_FAIL %d\n", value);
	glGetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, &value);
	PRINT("GL_STENCIL_PASS_DEPTH_FAIL %d\n", value);
	glGetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, &value);
	PRINT("GL_STENCIL_PASS_DEPTH_PASS %d\n", value);
	PRINT("==============================================\n\n");
}

void Stencil::draw()
{
	Node::draw();
}

void Stencil::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	GLboolean isEnableDepthTest = GL_FALSE;

	int nStencilFun = 0;
	int nStencilRef = 0;
	int nStencilValueMask = 0;
	int nStencilFail = 0;
	int nStencilPassDepthFail = 0;
	int nStencilPassDepthPass = 0;

	isEnableDepthTest = glIsEnabled(GL_DEPTH_TEST);
	glGetIntegerv(GL_STENCIL_FUNC, &nStencilFun);
	glGetIntegerv(GL_STENCIL_REF, &nStencilRef);
	glGetIntegerv(GL_STENCIL_VALUE_MASK, &nStencilValueMask);
	glGetIntegerv(GL_STENCIL_FAIL, &nStencilFail);
	glGetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, &nStencilPassDepthFail);
	glGetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, &nStencilPassDepthPass);

	
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);

	//showStencilInformation();

	glEnable(GL_STENCIL_TEST);

	glDepthMask(GL_FALSE);
	if (_stencilNode)
	{
		_stencilNode->visit();
	}

	glDepthMask(GL_TRUE);

	glStencilFunc(GL_EQUAL, 0x1, 0xff);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	//showStencilInformation();

	Node::visit();
	/*
	glStencilFunc(nStencilFun, nStencilRef, nStencilValueMask);
	glStencilOp(nStencilFail, nStencilPassDepthFail, nStencilPassDepthPass);
	if (isEnableDepthTest == GL_FALSE)
	{
		glDisable(GL_DEPTH_TEST);
	}
	*/
	glDisable(GL_STENCIL_TEST);
}

void Stencil::setStencilNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	SAFE_RELEASE(_stencilNode);
	SAFE_RETAIN(node);
	_stencilNode = node;
}

Node* Stencil::getStencilNode()
{
	return _stencilNode;
}
