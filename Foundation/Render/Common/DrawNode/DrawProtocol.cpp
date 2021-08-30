#include "DrawProtocol.h"

using namespace render;

ColorProtocol::ColorProtocol()
	: _color(phy::Color4F(1.0f, 1.0f, 1.0f, 1.0f))
{

}

ColorProtocol::~ColorProtocol()
{

}

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;

	onColorChange();
}

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	_color[0] = r / COLOR_FLOAT_VALUE;
	_color[1] = g / COLOR_FLOAT_VALUE;
	_color[2] = b / COLOR_FLOAT_VALUE;
	_color[3] = a / COLOR_FLOAT_VALUE;
	onColorChange();
}

void render::ColorProtocol::setColor(float r, float g, float b)
{
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;

	onColorChange();
}

void render::ColorProtocol::setColor(float r, float g, float b, float a)
{
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
	_color[3] = a;
	onColorChange();
}

void ColorProtocol::setColor(const phy::Color4B& color)
{
	phy::convertColor4BTo4F(color, _color);
	onColorChange();
}

void ColorProtocol::setColor(const phy::Color3B& color)
{
	phy::convertColor4BTo4F(color, _color);
	onColorChange();
}

void render::ColorProtocol::setColor(const phy::Color4F& color)
{
	_color = color;
	onColorChange();
}

void render::ColorProtocol::setColor(const phy::Color3F& color)
{
	this->setColor(color.getRed(), color.getGreen(), color.getBlue());
}

const phy::Color4F& ColorProtocol::getColor() const
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
	this->setBlend(BlendingFactorSrc::SRC_ALPHA, BlendingFactorDest::ONE_MINUS_SRC_ALPHA);
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

void render::BlendProtocol::setBlendColor(const phy::Color3B& color)
{
	this->setBlendColor(phy::Color4B(color));
}

void render::BlendProtocol::setBlendColor(const phy::Color3F& color)
{
	this->setBlendColor(phy::Color4F(color));
}

void render::BlendProtocol::setBlendColor(const phy::Color4B& color)
{
	phy::convertColor4BTo4F(color, _blendColor);
	onBlendChange();
}

void render::BlendProtocol::setBlendColor(const phy::Color4F& color)
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

