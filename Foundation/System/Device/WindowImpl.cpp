#include "WindowImpl.h"

using namespace sys;

WindowImpl::WindowImpl()
{

}

WindowImpl::~WindowImpl()
{

}

void WindowImpl::initWindow(const std::string& title, float width, float height, float posX, float posY)
{
	_title = title;
	_width = width;
	_height = height;
	_posX = posX;
	_posY = posY;
}

std::string WindowImpl::getTitle()
{
	return _title.c_str();
}

float WindowImpl::getHeight()
{
	return _height;
}

float WindowImpl::getWidth()
{
	return _width;
}

float WindowImpl::getPositionY()
{
	return _posY;
}

float WindowImpl::getPositionX()
{
	return _posX;
}

void WindowImpl::setTile(const std::string& name)
{
	_title = name;
}

void WindowImpl::setPositionX(float posX)
{
	_posX = posX;
}

void WindowImpl::setPositionY(float posY)
{
	_posY = posY;
}

void WindowImpl::setWidth(float width)
{
	_width = width;
}

void WindowImpl::setHeight(float height)
{
	_height = height;
}
