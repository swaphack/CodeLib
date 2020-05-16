#include "FragmentStencilTest.h"
#include "Graphic/import.h"

render::FragmentStencilOp::FragmentStencilOp()
{

}

render::FragmentStencilOp::~FragmentStencilOp()
{

}

void render::FragmentStencilOp::setFunc(StencilFunction func, int ref, uint32_t mask)
{
	_func = func;
	_ref = ref;
	_mask = mask;
}

void render::FragmentStencilOp::setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	_stencilFail = stencilFail;
	_depthFail = depthFail;
	_depthPass = depthPass;
}

void render::FragmentStencilOp::begin()
{
	GLState::enable(EnableModel::STENCIL_TEST);
}

void render::FragmentStencilOp::update()
{
	GLState::setStencilFunc(_func, _ref, _mask);
	GLState::setStencilOp(_stencilFail, _depthFail, _depthPass);
}

void render::FragmentStencilOp::end()
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

void render::StencilFaceOp::update()
{
	GLState::setStencilFuncSeparate(_faceType, _func, _ref, _mask);
	GLState::setStencilOpSeparate(_faceType, _stencilFail, _depthFail, _depthPass);
}
