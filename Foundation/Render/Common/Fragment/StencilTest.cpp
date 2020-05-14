#include "StencilTest.h"
#include "Graphic/import.h"

render::StencilOp::StencilOp()
{

}

render::StencilOp::~StencilOp()
{

}

void render::StencilOp::setFunc(StencilFunction func, int ref, uint32_t mask)
{
	_func = func;
	_ref = ref;
	_mask = mask;
}

void render::StencilOp::setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	_stencilFail = stencilFail;
	_depthFail = depthFail;
	_depthPass = depthPass;
}

void render::StencilOp::startTest()
{
	GLState::enable(EnableModel::STENCIL_TEST);
}

void render::StencilOp::test()
{
	GLState::setStencilFunc(_func, _ref, _mask);
	GLState::setStencilOp(_stencilFail, _depthFail, _depthPass);
}

void render::StencilOp::endTest()
{
	GLState::disable(EnableModel::STENCIL_TEST);
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

void render::StencilFaceOp::test()
{
	GLState::setStencilFuncSeparate(_faceType, _func, _ref, _mask);
	GLState::setStencilOpSeparate(_faceType, _stencilFail, _depthFail, _depthPass);
}
