#include "UIProtocol.h"

using namespace ui;

//////////////////////////////////////////////////////////////////////////
UIBoxProtocol::UIBoxProtocol()
:_bBoxVisible(false)
{

}

UIBoxProtocol::~UIBoxProtocol()
{

}

void UIBoxProtocol::setBoxVisible(bool status)
{
	_bBoxVisible = status;
}

bool UIBoxProtocol::isBoxVisible()
{
	return _bBoxVisible;
}

void UIBoxProtocol::setBoxColor(const sys::Color4B& color)
{
	_rectColor = color;
}

const sys::Color4B& UIBoxProtocol::getBoxColor()
{
	return _rectColor;
}