#include "Color3.h"
#include "macros.h"
phy::Color3B::Color3B()
{
	this->setRed(255);
	this->setGreen(255);
	this->setBlue(255);
}

phy::Color3B::Color3B(uint8_t r, uint8_t g, uint8_t b)
{
	this->setRed(r);
	this->setGreen(g);
	this->setBlue(b);
}

phy::Color3B::~Color3B() 
{
}

phy::Color3B& phy::Color3B::operator=(const Color3B& value)
{
	this->setRed(value.getRed());
	this->setGreen(value.getGreen());
	this->setBlue(value.getBlue());

	return *this;
}

void phy::Color3B::adjust()
{
	ADJUST_DURATION_VALUE_RANGE(_values[0], 0, COLOR_UCHAR_VALUE_MAX, COLOR_UCHAR_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[1], 0, COLOR_UCHAR_VALUE_MAX, COLOR_UCHAR_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[2], 0, COLOR_UCHAR_VALUE_MAX, COLOR_UCHAR_VALUE_MAX);
}

phy::Color3F::Color3F() 
{}

phy::Color3F::Color3F(float r, float g, float b)
{
}

phy::Color3F::~Color3F() 
{
}

phy::Color3F& phy::Color3F::operator=(const Color3F& value)
{
	this->setRed(value.getRed());
	this->setGreen(value.getGreen());
	this->setBlue(value.getBlue());

	return *this;
}

void phy::Color3F::adjust()
{
	ADJUST_DURATION_VALUE_RANGE(_values[0], 0, COLOR_FLOAT_VALUE_MAX, COLOR_FLOAT_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[1], 0, COLOR_FLOAT_VALUE_MAX, COLOR_FLOAT_VALUE_MAX);
	ADJUST_DURATION_VALUE_RANGE(_values[2], 0, COLOR_FLOAT_VALUE_MAX, COLOR_FLOAT_VALUE_MAX);
}

//////////////////////////////////////////////////////////////////////////
void phy::convertColor3BTo3F(const Color3B& b3, Color3F& f3)
{
	f3[0] = b3[0] / COLOR_FLOAT_VALUE;
	f3[1] = b3[1] / COLOR_FLOAT_VALUE;
	f3[2] = b3[2] / COLOR_FLOAT_VALUE;
}

void phy::convertColor3FTo3B(const Color3F& f3, Color3B& b3)
{
	b3[0] = (uint8_t)(f3[0] * COLOR_FLOAT_VALUE);
	b3[1] = (uint8_t)(f3[1] * COLOR_FLOAT_VALUE);
	b3[2] = (uint8_t)(f3[2] * COLOR_FLOAT_VALUE);
}
