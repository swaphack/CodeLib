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

const std::string& WindowImpl::getTitle() const
{
	return _title;
}

float WindowImpl::getHeight() const
{
	return _height;
}

float WindowImpl::getWidth() const
{
	return _width;
}

float WindowImpl::getPositionY() const
{
	return _posY;
}

float WindowImpl::getPositionX() const
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
