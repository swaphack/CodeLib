#include "DCColor.h"

using namespace render;

DCColor::DCColor()
{

}

DCColor::~DCColor()
{

}

void DCColor::draw()
{
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);
	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	SHOW_OPENGL_ERROR_MESSAGE();

	this->drawDC();

	glDisable(GL_BLEND);
}

void DCColor::initColor(const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	convertColor4BTo4F(color, this->Color);
	this->Color.red *= opacity / COLOR_FLOAT_VALUE;
	this->Color.green *= opacity / COLOR_FLOAT_VALUE;
	this->Color.blue *= opacity / COLOR_FLOAT_VALUE;
	this->Color.alpha *= opacity / COLOR_FLOAT_VALUE;
	this->Blend = blend;
	return;
}

void DCColor::drawDC()
{

}

DCColor* DCColor::create(const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	DCColor* pColor = sys::Instance<DCColor>::getInstance();
	pColor->initColor(color, opacity, blend);
	return pColor;
}


