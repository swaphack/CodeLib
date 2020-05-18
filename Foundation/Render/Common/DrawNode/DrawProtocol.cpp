#include "DrawProtocol.h"

using namespace render;

ColorProtocol::ColorProtocol()
	: _color(sys::Color4B(255, 255, 255, 255))
{

}

ColorProtocol::~ColorProtocol()
{

}

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	_color.red = r;
	_color.green = g;
	_color.blue = b;

	onColorChange();
}

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	_color.red = r;
	_color.green = g;
	_color.blue = b;
	_color.alpha = a;
	onColorChange();
}

void render::ColorProtocol::setColor(float r, float g, float b)
{
	_color.red = r * COLOR_FLOAT_VALUE;
	_color.green = g * COLOR_FLOAT_VALUE;
	_color.blue = b * COLOR_FLOAT_VALUE;

	onColorChange();
}

void render::ColorProtocol::setColor(float r, float g, float b, float a)
{
	_color.red = r * COLOR_FLOAT_VALUE;
	_color.green = g * COLOR_FLOAT_VALUE;
	_color.blue = b * COLOR_FLOAT_VALUE;
	_color.alpha = a * COLOR_FLOAT_VALUE;
	onColorChange();
}

void ColorProtocol::setColor(const sys::Color4B& color)
{
	_color = color;

	onColorChange();
}

void ColorProtocol::setColor(const sys::Color3B& color)
{
	_color = color;

	onColorChange();
}

void render::ColorProtocol::setColor(const sys::Color4F& color)
{
	sys::Color4B c;
	sys::convertColor4FTo4B(color, c);
	this->setColor(c);
}

void render::ColorProtocol::setColor(const sys::Color3F& color)
{
	sys::Color3B c;
	sys::convertColor3FTo3B(color, c);
	this->setColor(c);
}

const sys::Color4B& ColorProtocol::getColor() const
{
	return _color;
}

//////////////////////////////////////////////////////////////////////////
OpacityProtocol::OpacityProtocol()
	:_opacity(255)
{

}

OpacityProtocol::~OpacityProtocol()
{

}

void OpacityProtocol::setOpacity(uint8_t opacity)
{
	_opacity = opacity;
}

uint8_t OpacityProtocol::getOpacity()
{
	return _opacity;
}

//////////////////////////////////////////////////////////////////////////
BlendProtocol::BlendProtocol()
{
}

BlendProtocol::~BlendProtocol()
{

}

void BlendProtocol::setBlend(BlendingFactorSrc src, BlendingFactorDest dest)
{
	_blendParam.src = src;
	_blendParam.dest = dest;

	onBlendChange();
}

void BlendProtocol::setBlend(const BlendParam& blend)
{
	_blendParam.src = blend.src;
	_blendParam.dest = blend.dest;
	onBlendChange();
}

void render::BlendProtocol::setBlendColor(const sys::Color3B& color)
{
	this->setBlendColor(sys::Color4B(color));
}

void render::BlendProtocol::setBlendColor(const sys::Color3F& color)
{
	this->setBlendColor(sys::Color4F(color));
}

void render::BlendProtocol::setBlendColor(const sys::Color4B& color)
{
	sys::convertColor4BTo4F(color, _blendColor);
	onBlendChange();
}

void render::BlendProtocol::setBlendColor(const sys::Color4F& color)
{
	_blendColor = color;
	onBlendChange();
}

const BlendParam& BlendProtocol::getBlend()
{
	return _blendParam;
}
//////////////////////////////////////////////////////////////////////////
BlendParam& BlendParam::operator=(const BlendParam& blend)
{
	src = blend.src;
	dest = blend.dest;

	return *this;
}

BlendParam::BlendParam(BlendingFactorSrc src, BlendingFactorDest dest) :src(src), dest(dest)
{

}

BlendParam::BlendParam()
{

}
