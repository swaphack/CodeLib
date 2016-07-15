#include "UIProtocol.h"

using namespace render;


UINameProtocol::UINameProtocol()
:_name("")
{

}

UINameProtocol::~UINameProtocol()
{

}

void UINameProtocol::setName(const char* name)
{
	if (name)
	{
		_name = name;
	}
}

const char* UINameProtocol::getName()
{
	return _name.c_str();
}

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