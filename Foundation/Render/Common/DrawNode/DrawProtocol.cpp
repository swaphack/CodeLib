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
}

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	_color.red = r;
	_color.green = g;
	_color.blue = b;
	_color.alpha = a;
}

void ColorProtocol::setColor(const sys::Color4B& color)
{
	_color = color;
}

void ColorProtocol::setColor(const sys::Color3B& color)
{
	_color.red = color.red;
	_color.green = color.green;
	_color.blue = color.blue;
}

const sys::Color4B& ColorProtocol::getColor()
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
	_blend.src = src;
	_blend.dest = dest;
}

void BlendProtocol::setBlend(const BlendParam& blend)
{
	_blend.src = blend.src;
	_blend.dest = blend.dest;
}

const BlendParam& BlendProtocol::getBlend()
{
	return _blend;
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
