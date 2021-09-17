#include "Color4.h"
#include "macros.h"

phy::Color4B::Color4B() 
{
	this->setRed(255);
	this->setGreen(255);
	this->setBlue(255);
	this->setAlpha(255);
}

phy::Color4B::Color4B(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	this->setRed(r);
	this->setGreen(g);
	this->setBlue(b);
	this->setAlpha(a);
}

phy::Color4B::Color4B(const Color3B& color, uint8_t a)
{
	this->setRed(color.getRed());
	this->setGreen(color.getGreen());
	this->setBlue(color.getBlue());
	this->setAlpha(a);
}

phy::Color4B::~Color4B()
{
}

phy::Color4B& phy::Color4B::operator=(const Color4B& value)
{
	this->setRed(value.getRed());
	this->setGreen(value.getGreen());
	this->setBlue(value.getBlue());
	this->setAlpha(value.getAlpha());

	return *this;
}

phy::Color4B::operator phy::Color3B() const
{
	return Color3B(getRed(), getGreen(), getBlue());
}

void phy::Color4B::adjust()
{
	ADJUST_DURATION_VALUE_RANGE(_values[0], 0, COLOR_UCHAR_VALUE_MAX, COLOR_UCHAR_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[1], 0, COLOR_UCHAR_VALUE_MAX, COLOR_UCHAR_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[2], 0, COLOR_UCHAR_VALUE_MAX, COLOR_UCHAR_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[3], 0, COLOR_UCHAR_VALUE_MAX, COLOR_UCHAR_VALUE_MAX);
}

phy::Color4F::Color4F()
{
	this->setRed(1);
	this->setGreen(1);
	this->setBlue(1);
	this->setAlpha(1);
}

phy::Color4F::Color4F(float r, float g, float b, float a)
{
	this->setRed(r);
	this->setGreen(g);
	this->setBlue(b);
	this->setAlpha(a);

	adjust();
}

phy::Color4F::Color4F(float r, float g, float b)
{
	this->setRed(r);
	this->setGreen(g);
	this->setBlue(b);
	this->setAlpha(1);

	adjust();
}

phy::Color4F::Color4F(const Color3F& color, float a)
{
	this->setRed(color.getRed());
	this->setGreen(color.getGreen());
	this->setBlue(color.getBlue());
	this->setAlpha(a);

	adjust();
}

phy::Color4F::~Color4F()
{
}

phy::Color4F& phy::Color4F::operator=(const Color4F& value)
{
	this->setRed(value.getRed());
	this->setGreen(value.getGreen());
	this->setBlue(value.getBlue());
	this->setAlpha(value.getAlpha());

	return *this;
}

void phy::Color4F::adjust()
{
	ADJUST_DURATION_VALUE_RANGE(_values[0], 0, COLOR_FLOAT_VALUE_MAX, COLOR_FLOAT_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[1], 0, COLOR_FLOAT_VALUE_MAX, COLOR_FLOAT_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[2], 0, COLOR_FLOAT_VALUE_MAX, COLOR_FLOAT_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[3], 0, COLOR_FLOAT_VALUE_MAX, COLOR_FLOAT_VALUE_MAX);
}

//////////////////////////////////////////////////////////////////////////

void phy::convertColor4BTo4F(const Color4B& b4, Color4F& f4)
{
	f4[0] = b4[0] / COLOR_FLOAT_VALUE;
	f4[1] = b4[1] / COLOR_FLOAT_VALUE;
	f4[2] = b4[2] / COLOR_FLOAT_VALUE;
	f4[3] = b4[3] / COLOR_FLOAT_VALUE;
}

void phy::convertColor4FTo4B(const Color4F& f4, Color4B& b4)
{
	b4[0] = (uint8_t)(f4[0] * COLOR_FLOAT_VALUE);
	b4[1] = (uint8_t)(f4[1] * COLOR_FLOAT_VALUE);
	b4[2] = (uint8_t)(f4[2] * COLOR_FLOAT_VALUE);
	b4[3] = (uint8_t)(f4[3] * COLOR_FLOAT_VALUE);
}
