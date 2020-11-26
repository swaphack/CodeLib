#include "FragmentBlend.h"
#include "Graphic/import.h"

render::FragmentBlendBase::FragmentBlendBase()
	:FragmentHandle(FragmentType::BLEND, EnableMode::BLEND)
{
}

render::FragmentBlendBase::~FragmentBlendBase()
{

}

void render::FragmentBlendBase::setBlendColor(const phy::Color4F& color)
{
	_blendColor = color;
}

void render::FragmentBlendBase::setBlendColor(const phy::Color4B& color)
{
	phy::convertColor4BTo4F(color, _blendColor);
}

void render::FragmentBlendBase::update()
{
	GLState::setBlendColor(_blendColor);
}

//////////////////////////////////////////////////////////////////////////

render::FragmentBlend::FragmentBlend()
{

}

render::FragmentBlend::~FragmentBlend()
{

}

void render::FragmentBlend::setBlendFactor(BlendingFactorSrc src, BlendingFactorDest dst)
{
	_src = src;
	_dest = dst;
}

void render::FragmentBlend::setBlendEquation(BlendEquationMode mode)
{
	_mode = mode;
}

void render::FragmentBlend::update()
{
	FragmentBlendBase::update();
	GLState::setBlendEquation(_mode);
	GLState::setBlendFunc(_src, _dest);
}

//////////////////////////////////////////////////////////////////////////
render::FragmentBlendSeparate::FragmentBlendSeparate()
{

}

render::FragmentBlendSeparate::~FragmentBlendSeparate()
{

}

void render::FragmentBlendSeparate::setBlendFactor(BlendingFactorSrc srcRGB, BlendingFactorDest dstRGB, BlendingFactorSrc srcAlpha, BlendingFactorDest dstAlpha)
{
	_srcRGB = srcRGB;
	_destRGB = dstRGB;
	_srcAlpha = srcAlpha;
	_destAlpha = dstAlpha;
}

void render::FragmentBlendSeparate::setBlendEquation(BlendEquationMode rgbMode, BlendEquationMode alphaMode)
{
	_rgbMode = rgbMode;
	_alphaMode = alphaMode;
}

void render::FragmentBlendSeparate::update()
{
	FragmentBlendBase::update();
	GLState::setBlendEquationSeparate(_rgbMode, _alphaMode);
	GLState::setBlendFuncSeparate(_srcRGB, _destRGB, _srcAlpha, _destAlpha);
}
//////////////////////////////////////////////////////////////////////////
render::FragmentBlendBuffer::FragmentBlendBuffer()
{

}

render::FragmentBlendBuffer::~FragmentBlendBuffer()
{

}

void render::FragmentBlendBuffer::setBufferID(uint32_t buffer)
{
	_bufferID = buffer;
}

void render::FragmentBlendBuffer::update()
{
	FragmentBlendBase::update();
	GLState::setBlendEquation(_mode);
	GLState::setBlendFunc(_bufferID, _src, _dest);
}

//////////////////////////////////////////////////////////////////////////
render::FragmentBlendSeparateBuffer::FragmentBlendSeparateBuffer()
{

}

render::FragmentBlendSeparateBuffer::~FragmentBlendSeparateBuffer()
{

}

void render::FragmentBlendSeparateBuffer::setBufferID(uint32_t buffer)
{
	_bufferID = buffer;
}

void render::FragmentBlendSeparateBuffer::update()
{
	FragmentBlendBase::update();
	GLState::setBlendEquationSeparate(_bufferID, _rgbMode, _alphaMode);
	GLState::setBlendFuncSeparate(_bufferID, _srcRGB, _destRGB, _srcAlpha, _destAlpha);
}

//////////////////////////////////////////////////////////////////////////
