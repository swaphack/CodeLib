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
	GLState::getInt(GetTarget::STENCIL_TEST, &value);
	PRINT("STENCIL_TEST %d\n", value);
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
	GLState::getInt(GetTarget::STENCIL_WRITEMASK, &value);
	PRINT("GL_STENCIL_WRITEMASK %d\n", value);
	PRINT("==============================================\n\n");
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

void render::Stencil::startFragmentTest()
{

	this->saveStencilData();

	//

	GLState::enable(EnableModel::STENCIL_TEST);
	GLState::setStencilFunc(StencilFunction::ALWAYS, 0x01, 0xFF);
	GLState::setStencilOp(StencilOpResult::KEEP, StencilOpResult::KEEP, StencilOpResult::REPLACE);
	GLState::setStencilMask(0xff);
	//GLState::setDepthMask(false);

	showStencilInformation();

	if (_stencilNode)
	{
		_stencilNode->visit();
	}

	//GLState::setDepthMask(true);

	GLState::setStencilFunc(StencilFunction::NOTEQUAL, 0x01, 0x0FF);
	GLState::setStencilOp(StencilOpResult::KEEP, StencilOpResult::KEEP, StencilOpResult::REPLACE);
	GLState::setStencilMask(0x00);
	GLState::disable(EnableModel::STENCIL_TEST);

	showStencilInformation();
}

void render::Stencil::endFragmentTest()
{
	this->resetStencilData();

	if (_stencilData.isEnableDepthTest == false)
	{
		GLState::disable(EnableModel::DEPTH_TEST);
	}

	GLDebug::showError();
}

void render::Stencil::saveStencilData()
{
	_stencilData.isEnableDepthTest = GLState::isEnabled(EnableModel::DEPTH_TEST);
	GLState::getInt(GetTarget::STENCIL_FUNC, &_stencilData.nStencilFun);
	GLState::getInt(GetTarget::STENCIL_REF, &_stencilData.nStencilRef);
	GLState::getInt(GetTarget::STENCIL_VALUE_MASK, &_stencilData.nStencilValueMask);
	GLState::getInt(GetTarget::STENCIL_FAIL, &_stencilData.nStencilFail);
	GLState::getInt(GetTarget::STENCIL_PASS_DEPTH_FAIL, &_stencilData.nStencilPassDepthFail);
	GLState::getInt(GetTarget::STENCIL_PASS_DEPTH_PASS, &_stencilData.nStencilPassDepthPass);
}

void render::Stencil::resetStencilData()
{
	GLState::setStencilFunc((StencilFunction)_stencilData.nStencilFun, _stencilData.nStencilRef, _stencilData.nStencilValueMask);
	GLState::setStencilOp((StencilOpResult)_stencilData.nStencilFail, (StencilOpResult)_stencilData.nStencilPassDepthFail, (StencilOpResult)_stencilData.nStencilPassDepthPass);
}
