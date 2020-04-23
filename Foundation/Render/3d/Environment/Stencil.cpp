#pragma once

#include "Stencil.h"
#include "Graphic/import.h"

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
	GLState::getInt(GetTarget::STENCIL_FUNC, &value);
	PRINT("GL_STENCIL_FUNC %d\n", value);
	GLState::getInt(GetTarget::STENCIL_REF, &value);
	PRINT("GL_STENCIL_REF %d\n", value);
	GLState::getInt(GetTarget::STENCIL_VALUE_MASK, &value);
	PRINT("GL_STENCIL_VALUE_MASK %d\n", value);
	GLState::getInt(GetTarget::STENCIL_FAIL, &value);
	PRINT("GL_STENCIL_FAIL %d\n", value);
	GLState::getInt(GetTarget::STENCIL_PASS_DEPTH_FAIL, &value);
	PRINT("GL_STENCIL_PASS_DEPTH_FAIL %d\n", value);
	GLState::getInt(GetTarget::STENCIL_PASS_DEPTH_PASS, &value);
	PRINT("GL_STENCIL_PASS_DEPTH_PASS %d\n", value);
	PRINT("==============================================\n\n");
}

void Stencil::draw()
{
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

	isEnableDepthTest = GLState::isEnabled(EnableModel::DEPTH_TEST);
	GLState::getInt(GetTarget::STENCIL_FUNC, &nStencilFun);
	GLState::getInt(GetTarget::STENCIL_REF, &nStencilRef);
	GLState::getInt(GetTarget::STENCIL_VALUE_MASK, &nStencilValueMask);
	GLState::getInt(GetTarget::STENCIL_FAIL, &nStencilFail);
	GLState::getInt(GetTarget::STENCIL_PASS_DEPTH_FAIL, &nStencilPassDepthFail);
	GLState::getInt(GetTarget::STENCIL_PASS_DEPTH_PASS, &nStencilPassDepthPass);


	GLState::enable(EnableModel::DEPTH_TEST);

	GLState::setStencilOp(StencilOp::KEEP, StencilOp::KEEP, StencilOp::REPLACE);
	GLState::setStencil(StencilFunction::ALWAYS, 1, 0xff);

	GLState::setStencilMask(0xff);

	//showStencilInformation();

	GLState::setDepthMask(false);
	if (_stencilNode)
	{
		_stencilNode->visit();
	}

	GLState::setDepthMask(true);

	GLState::setStencilOp(StencilOp::KEEP, StencilOp::KEEP, StencilOp::KEEP);
	GLState::setStencil(StencilFunction::EQUAL, 0x1, 0xff);

	//showStencilInformation();

	Node::visit();
	
	GLState::setStencilOp((StencilOp)nStencilFail, (StencilOp)nStencilPassDepthFail, (StencilOp)nStencilPassDepthPass);
	GLState::setStencil((StencilFunction)nStencilFun, nStencilRef, nStencilValueMask);
	
	if (isEnableDepthTest == GL_FALSE)
	{
		glDisable(GL_DEPTH_TEST);
	}

	GLState::disable(EnableModel::DEPTH_TEST);
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
