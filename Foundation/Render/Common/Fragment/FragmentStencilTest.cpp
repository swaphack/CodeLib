#include "FragmentStencilTest.h"
#include "Graphic/import.h"

render::FragmentStencilTest::FragmentStencilTest()
	:FragmentHandle(FragmentType::STENCIL_TEST, EnableMode::STENCIL_TEST)
{

}

render::FragmentStencilTest::~FragmentStencilTest()
{

}

void render::FragmentStencilTest::setFunc(StencilFunction func, int ref, uint32_t mask)
{
	_stencilData.nStencilFun = (int)func;
	_stencilData.nStencilRef = ref;
	_stencilData.nStencilValueMask = mask;
}

void render::FragmentStencilTest::setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	_stencilData.nStencilFail = (int)stencilFail;
	_stencilData.nStencilPassDepthFail = (int)depthFail;
	_stencilData.nStencilPassDepthPass = (int)depthPass;
}

void render::FragmentStencilTest::update()
{
	GLState::setStencilFunc((StencilFunction)_stencilData.nStencilFun, _stencilData.nStencilRef, _stencilData.nStencilValueMask);
	GLState::setStencilOp((StencilOpResult)_stencilData.nStencilFail, (StencilOpResult)_stencilData.nStencilPassDepthFail, (StencilOpResult)_stencilData.nStencilPassDepthPass);
}

void render::FragmentStencilTest::saveData()
{
	GLState::getInteger(GetTarget::STENCIL_FUNC, &_lastStencilData.nStencilFun);
	GLState::getInteger(GetTarget::STENCIL_REF, &_lastStencilData.nStencilRef);
	GLState::getInteger(GetTarget::STENCIL_VALUE_MASK, &_lastStencilData.nStencilValueMask);
	GLState::getInteger(GetTarget::STENCIL_FAIL, &_lastStencilData.nStencilFail);
	GLState::getInteger(GetTarget::STENCIL_PASS_DEPTH_FAIL, &_lastStencilData.nStencilPassDepthFail);
	GLState::getInteger(GetTarget::STENCIL_PASS_DEPTH_PASS, &_lastStencilData.nStencilPassDepthPass);
}

void render::FragmentStencilTest::reloadData()
{
	GLState::setStencilFunc((StencilFunction)_lastStencilData.nStencilFun, _lastStencilData.nStencilRef, _lastStencilData.nStencilValueMask);
	GLState::setStencilOp((StencilOpResult)_lastStencilData.nStencilFail, (StencilOpResult)_lastStencilData.nStencilPassDepthFail, (StencilOpResult)_lastStencilData.nStencilPassDepthPass);
}

//////////////////////////////////////////////////////////////////////////
render::StencilFaceOp::StencilFaceOp()
{

}

render::StencilFaceOp::~StencilFaceOp()
{

}

void render::StencilFaceOp::setFaceType(FaceType faceType)
{
	_faceType = faceType;
}

void render::StencilFaceOp::update()
{
	GLState::setStencilFuncSeparate(_faceType, (StencilFunction)_stencilData.nStencilFun, _stencilData.nStencilRef, _stencilData.nStencilValueMask);
	GLState::setStencilOpSeparate(_faceType, (StencilOpResult)_stencilData.nStencilFail, (StencilOpResult)_stencilData.nStencilPassDepthFail, (StencilOpResult)_stencilData.nStencilPassDepthPass);
}
