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
	this->setColor(r / COLOR_FLOAT_VALUE, g / COLOR_FLOAT_VALUE, b / COLOR_FLOAT_VALUE);
}

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	this->setColor(r / COLOR_FLOAT_VALUE, g / COLOR_FLOAT_VALUE, b / COLOR_FLOAT_VALUE, a / COLOR_FLOAT_VALUE);
}

void render::ColorProtocol::setColor(float r, float g, float b)
{
	if (_color[0] == r && _color[1] == g && _color[2] == b)
	{
		return;
	}
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
	onColorChange();
}

void render::ColorProtocol::setColor(float r, float g, float b, float a)
{
	if (_color[0] == r && _color[1] == g && _color[2] == b && _color[3] == a)
	{
		return;
	}
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
	_color[3] = a;
	onColorChange();
}

void ColorProtocol::setColor(const phy::Color4B& color)
{
	this->setColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}

void ColorProtocol::setColor(const phy::Color3B& color)
{
	this->setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void render::ColorProtocol::setColor(const phy::Color4F& color)
{
	this->setColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
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
BlendParam::BlendParam()
{

}

BlendParam::BlendParam(BlendingFactorSrc src, BlendingFactorDest dest) :src(src), dest(dest)
{

}

BlendParam& BlendParam::operator=(const BlendParam& blend)
{
	src = blend.src;
	dest = blend.dest;

	return *this;
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
	if (_blendParam.src == src && _blendParam.dest == dest)
	{
		return;
	}
	_blendParam.src = src;
	_blendParam.dest = dest;

	onBlendChange();
}

void BlendProtocol::setBlend(const BlendParam& blend)
{
	setBlend(blend.src, blend.dest);
}

void render::BlendProtocol::setBlendColor(uint8_t r, uint8_t g, uint8_t b)
{
	this->setBlendColor(r / COLOR_FLOAT_VALUE, g / COLOR_FLOAT_VALUE, b / COLOR_FLOAT_VALUE);
}

void render::BlendProtocol::setBlendColor(float r, float g, float b)
{
	if (_blendColor[0] == r && _blendColor[1] == g && _blendColor[2] == b)
	{
		return;
	}

	_blendColor[0] = r;
	_blendColor[1] = g;
	_blendColor[2] = b;
	onBlendChange();
}

void render::BlendProtocol::setBlendColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	this->setBlendColor(r / COLOR_FLOAT_VALUE, g / COLOR_FLOAT_VALUE, b / COLOR_FLOAT_VALUE, a / COLOR_FLOAT_VALUE);
}

void render::BlendProtocol::setBlendColor(float r, float g, float b, float a)
{
	if (_blendColor[0] == r && _blendColor[1] == g && _blendColor[2] == b && _blendColor[3] == a)
	{
		return;
	}

	_blendColor[0] = r;
	_blendColor[1] = g;
	_blendColor[2] = b;
	_blendColor[4] = a;
	onBlendChange();
}

void render::BlendProtocol::setBlendColor(const phy::Color3B& color)
{
	this->setBlendColor(color.getRed(), color.getGreen(), color.getBlue());
}

void render::BlendProtocol::setBlendColor(const phy::Color3F& color)
{
	this->setBlendColor(color.getRed(), color.getGreen(), color.getBlue());
}

void render::BlendProtocol::setBlendColor(const phy::Color4B& color)
{
	this->setBlendColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}

void render::BlendProtocol::setBlendColor(const phy::Color4F& color)
{
	this->setBlendColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}

const BlendParam& BlendProtocol::getBlend()
{
	return _blendParam;
}

