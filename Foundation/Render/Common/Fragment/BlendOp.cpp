#include "BlendOp.h"
#include "Graphic/import.h"

render::BlendOpBase::BlendOpBase()
{
}

render::BlendOpBase::~BlendOpBase()
{

}

void render::BlendOpBase::setBlendColor(const sys::Color4F& color)
{
	_blendColor = color;
}

void render::BlendOpBase::startTest()
{
	GLState::enable(EnableModel::BLEND);
}

void render::BlendOpBase::test()
{
	GLState::setBlendColor(_blendColor);
}

void render::BlendOpBase::endTest()
{
	GLState::disable(EnableModel::BLEND);
}
//////////////////////////////////////////////////////////////////////////

render::BlendOp::BlendOp()
{

}

render::BlendOp::~BlendOp()
{

}

void render::BlendOp::setBlendFactor(BlendingFactorSrc src, BlendingFactorDest dst)
{
	_src = src;
	_dest = dst;
}

void render::BlendOp::setBlendEquation(BlendEquationMode mode)
{
	_mode = mode;
}

void render::BlendOp::test()
{
	BlendOpBase::test();
	GLState::setBlendEquation(_mode);
	GLState::setBlendFunc(_src, _dest);
}

//////////////////////////////////////////////////////////////////////////
render::BlendSeparateOp::BlendSeparateOp()
{

}

render::BlendSeparateOp::~BlendSeparateOp()
{

}

void render::BlendSeparateOp::setBlendFactor(BlendingFactorSrc srcRGB, BlendingFactorDest dstRGB, BlendingFactorSrc srcAlpha, BlendingFactorDest dstAlpha)
{
	_srcRGB = srcRGB;
	_destRGB = dstRGB;
	_srcAlpha = srcAlpha;
	_destAlpha = dstAlpha;
}

void render::BlendSeparateOp::setBlendEquation(BlendEquationMode rgbMode, BlendEquationMode alphaMode)
{
	_rgbMode = rgbMode;
	_alphaMode = alphaMode;
}

void render::BlendSeparateOp::test()
{
	BlendOpBase::test();
	GLState::setBlendEquationSeparate(_rgbMode, _alphaMode);
	GLState::setBlendFuncSeparate(_srcRGB, _destRGB, _srcAlpha, _destAlpha);
}
//////////////////////////////////////////////////////////////////////////
render::BlendBufferOp::BlendBufferOp()
{

}

render::BlendBufferOp::~BlendBufferOp()
{

}

void render::BlendBufferOp::setBufferID(uint32_t buffer)
{
	_bufferID = buffer;
}

void render::BlendBufferOp::test()
{
	BlendOpBase::test();
	GLState::setBlendEquation(_mode);
	GLState::setBlendFunc(_bufferID, _src, _dest);
}

//////////////////////////////////////////////////////////////////////////
render::BlendSeparateBufferOp::BlendSeparateBufferOp()
{

}

render::BlendSeparateBufferOp::~BlendSeparateBufferOp()
{

}

void render::BlendSeparateBufferOp::setBufferID(uint32_t buffer)
{
	_bufferID = buffer;
}

void render::BlendSeparateBufferOp::test()
{
	BlendOpBase::test();
	GLState::setBlendEquationSeparate(_bufferID, _rgbMode, _alphaMode);
	GLState::setBlendFuncSeparate(_bufferID, _srcRGB, _destRGB, _srcAlpha, _destAlpha);
}

//////////////////////////////////////////////////////////////////////////
