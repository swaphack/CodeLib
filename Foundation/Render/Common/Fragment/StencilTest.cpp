#include "StencilTest.h"
#include "Graphic/import.h"

void render::StencilTest::enable()
{
	GLState::enable(EnableModel::STENCIL_TEST);
}

void render::StencilTest::disable()
{
	GLState::disable(EnableModel::STENCIL_TEST);
}

bool render::StencilTest::isEnabled()
{
	return GLState::isEnabled(EnableModel::STENCIL_TEST);
}

void render::StencilTest::setFunc(StencilFunction func, int ref, uint32_t mask)
{
	GLState::setStencilFunc(func, ref, mask);
}

void render::StencilTest::setFuncSeparate(FaceType type, StencilFunction func, int ref, uint32_t mask)
{
	GLState::setStencilFuncSeparate(type, func, ref, mask);
}

void render::StencilTest::setOp(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	GLState::setStencilOp(stencilFail, depthFail, depthPass);
}

void render::StencilTest::setOpSeparate(FaceType type, StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	GLState::setStencilOpSeparate(type, stencilFail, depthFail, depthPass);
}

void render::StencilTest::setMask(uint32_t mask)
{
	GLState::setStencilMask(mask);
}

void render::StencilTest::setMaskSeparate(FaceType type, uint32_t mask)
{
	GLState::setStencilMaskSeparate(type, mask);
}
