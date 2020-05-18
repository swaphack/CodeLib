#include "FragmentStencilTest.h"
#include "Graphic/import.h"

render::FragmentStencilTest::FragmentStencilTest()
{
	_fragmentType = FragmentType::STENCIL_TEST;
}

render::FragmentStencilTest::~FragmentStencilTest()
{

}

void render::FragmentStencilTest::setFunc(StencilFunction func, int ref, uint32_t mask)
{
	_func = func;
	_ref = ref;
	_mask = mask;
}

void render::FragmentStencilTest::setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	_stencilFail = stencilFail;
	_depthFail = depthFail;
	_depthPass = depthPass;
}

void render::FragmentStencilTest::begin()
{
	GLState::enable(EnableModel::STENCIL_TEST);
}

void render::FragmentStencilTest::update()
{
	GLState::setStencilFunc(_func, _ref, _mask);
	GLState::setStencilOp(_stencilFail, _depthFail, _depthPass);
}

void render::FragmentStencilTest::end()
{
	GLState::disable(EnableModel::STENCIL_TEST);
}

void render::FragmentStencilTest::saveStencilData()
{
	_stencilData.isEnableDepthTest = GLState::isEnabled(EnableModel::DEPTH_TEST);
	GLState::getInteger(GetTarget::STENCIL_FUNC, &_stencilData.nStencilFun);
	GLState::getInteger(GetTarget::STENCIL_REF, &_stencilData.nStencilRef);
	GLState::getInteger(GetTarget::STENCIL_VALUE_MASK, &_stencilData.nStencilValueMask);
	GLState::getInteger(GetTarget::STENCIL_FAIL, &_stencilData.nStencilFail);
	GLState::getInteger(GetTarget::STENCIL_PASS_DEPTH_FAIL, &_stencilData.nStencilPassDepthFail);
	GLState::getInteger(GetTarget::STENCIL_PASS_DEPTH_PASS, &_stencilData.nStencilPassDepthPass);
}

void render::FragmentStencilTest::resetStencilData()
{
	GLState::setStencilFunc((StencilFunction)_stencilData.nStencilFun, _stencilData.nStencilRef, _stencilData.nStencilValueMask);
	GLState::setStencilOp((StencilOpResult)_stencilData.nStencilFail, (StencilOpResult)_stencilData.nStencilPassDepthFail, (StencilOpResult)_stencilData.nStencilPassDepthPass);
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
	GLState::setStencilFuncSeparate(_faceType, _func, _ref, _mask);
	GLState::setStencilOpSeparate(_faceType, _stencilFail, _depthFail, _depthPass);
}
