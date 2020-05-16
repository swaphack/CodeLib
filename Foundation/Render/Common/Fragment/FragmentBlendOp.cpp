#include "FragmentBlendOp.h"
#include "Graphic/import.h"

render::FragmentBlendOpBase::FragmentBlendOpBase()
{
}

render::FragmentBlendOpBase::~FragmentBlendOpBase()
{

}

void render::FragmentBlendOpBase::setBlendColor(const sys::Color4F& color)
{
	_blendColor = color;
}

void render::FragmentBlendOpBase::begin()
{
	GLState::enable(EnableModel::BLEND);
}

void render::FragmentBlendOpBase::update()
{
	GLState::setBlendColor(_blendColor);
}

void render::FragmentBlendOpBase::end()
{
	GLState::disable(EnableModel::BLEND);
}
//////////////////////////////////////////////////////////////////////////

render::FragmentBlendOp::FragmentBlendOp()
{

}

render::FragmentBlendOp::~FragmentBlendOp()
{

}

void render::FragmentBlendOp::setBlendFactor(BlendingFactorSrc src, BlendingFactorDest dst)
{
	_src = src;
	_dest = dst;
}

void render::FragmentBlendOp::setBlendEquation(BlendEquationMode mode)
{
	_mode = mode;
}

void render::FragmentBlendOp::update()
{
	FragmentBlendOpBase::update();
	GLState::setBlendEquation(_mode);
	GLState::setBlendFunc(_src, _dest);
}

//////////////////////////////////////////////////////////////////////////
render::FragmentBlendSeparateOp::FragmentBlendSeparateOp()
{

}

render::FragmentBlendSeparateOp::~FragmentBlendSeparateOp()
{

}

void render::FragmentBlendSeparateOp::setBlendFactor(BlendingFactorSrc srcRGB, BlendingFactorDest dstRGB, BlendingFactorSrc srcAlpha, BlendingFactorDest dstAlpha)
{
	_srcRGB = srcRGB;
	_destRGB = dstRGB;
	_srcAlpha = srcAlpha;
	_destAlpha = dstAlpha;
}

void render::FragmentBlendSeparateOp::setBlendEquation(BlendEquationMode rgbMode, BlendEquationMode alphaMode)
{
	_rgbMode = rgbMode;
	_alphaMode = alphaMode;
}

void render::FragmentBlendSeparateOp::update()
{
	FragmentBlendOpBase::update();
	GLState::setBlendEquationSeparate(_rgbMode, _alphaMode);
	GLState::setBlendFuncSeparate(_srcRGB, _destRGB, _srcAlpha, _destAlpha);
}
//////////////////////////////////////////////////////////////////////////
render::FragmentBlendBufferOp::FragmentBlendBufferOp()
{

}

render::FragmentBlendBufferOp::~FragmentBlendBufferOp()
{

}

void render::FragmentBlendBufferOp::setBufferID(uint32_t buffer)
{
	_bufferID = buffer;
}

void render::FragmentBlendBufferOp::update()
{
	FragmentBlendOpBase::update();
	GLState::setBlendEquation(_mode);
	GLState::setBlendFunc(_bufferID, _src, _dest);
}

//////////////////////////////////////////////////////////////////////////
render::FragmentBlendSeparateBufferOp::FragmentBlendSeparateBufferOp()
{

}

render::FragmentBlendSeparateBufferOp::~FragmentBlendSeparateBufferOp()
{

}

void render::FragmentBlendSeparateBufferOp::setBufferID(uint32_t buffer)
{
	_bufferID = buffer;
}

void render::FragmentBlendSeparateBufferOp::update()
{
	FragmentBlendOpBase::update();
	GLState::setBlendEquationSeparate(_bufferID, _rgbMode, _alphaMode);
	GLState::setBlendFuncSeparate(_bufferID, _srcRGB, _destRGB, _srcAlpha, _destAlpha);
}

//////////////////////////////////////////////////////////////////////////
