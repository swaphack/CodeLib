#include "DrawBoxProtocol.h"

render::DrawBoxProtocol::DrawBoxProtocol()
{
}

render::DrawBoxProtocol::~DrawBoxProtocol()
{
}

void render::DrawBoxProtocol::setBoxVisible(bool bVisible)
{
	_bBoxVisible = bVisible;
}

bool render::DrawBoxProtocol::isBoxVisible() const
{
	return _bBoxVisible;
}

void render::DrawBoxProtocol::setBoxColor(const phy::Color4B& color)
{
	_boxColor = color;
}

const phy::Color4B& render::DrawBoxProtocol::getBoxColor() const
{
	return _boxColor;
}

float render::DrawBoxProtocol::getBoxLineWidth() const
{
	return _boxLineWidth;
}

void render::DrawBoxProtocol::setBoxLineWidth(float width)
{
	_boxLineWidth = width;
}