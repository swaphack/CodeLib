#include "GLFragment.h"
using namespace render;

void GLFragment::testScissor(float x, float y, float width, float height)
{
	glScissor(x, y, width, height);
}

void GLFragment::testAlpha(AlphaFunction func, float value)
{
	glAlphaFunc((GLenum)func, value);
}

void GLFragment::testStencil(StencilFunction func, int ref, int mask)
{
	glStencilFunc((GLenum)func, ref, mask);
}

void GLFragment::setStencilOp(StencilOp stencilFail, StencilOp depthFail, StencilOp pass)
{
	glStencilOp((GLenum)stencilFail, (GLenum)depthFail, (GLenum)pass);
}

void GLFragment::testDepth(DepthFunction func)
{
	glDepthFunc((GLenum)func);
}

void GLFragment::setBlend(BlendingFactorSrc src, BlendingFactorDest dest)
{
	glBlendFunc((GLenum)src, (GLenum)dest);
}

void GLFragment::setLogicOp(LogicOp op)
{
	glLogicOp((GLenum)op);
}

void GLFragment::setAccumOp(AccumOp op, float value)
{
	glAccum((GLenum)op, value);
}
