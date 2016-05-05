#include "protocol_common.h"

using namespace render;


DirtyProtocol::DirtyProtocol()
:_bDirty(true)
{

}

DirtyProtocol::~DirtyProtocol()
{

}

void DirtyProtocol::setDirty(bool status)
{
	_bDirty = status;
}

bool DirtyProtocol::isDirty()
{
	return _bDirty;
}

//////////////////////////////////////////////////////////////////////////
ColorProtocol::ColorProtocol()
: _color(sys::Color4B(255, 255, 255, 255))
{

}

ColorProtocol::~ColorProtocol()
{

}

void ColorProtocol::setColor(uchar r, uchar g, uchar b)
{
	_color.red = r;
	_color.green = g;
	_color.blue = b;
}

void ColorProtocol::setColor(uchar r, uchar g, uchar b, uchar a)
{
	_color.red = r;
	_color.green = g;
	_color.blue = b;
	_color.alpha = a;
}

void ColorProtocol::setColor(sys::Color4B color)
{
	_color = color;
}

sys::Color4B ColorProtocol::getColor()
{
	return _color;
}

//////////////////////////////////////////////////////////////////////////
SystemProtocol::SystemProtocol()
:_actionStatus(EAS_NONE)
{

}

SystemProtocol::~SystemProtocol()
{

}

void SystemProtocol::pause()
{
	_actionStatus = EAS_PAUSE;
}

void SystemProtocol::resume()
{
	_actionStatus = EAS_RUNNING;
}

void SystemProtocol::start()
{
	_actionStatus = EAS_RUNNING;
}

void SystemProtocol::stop()
{
	_actionStatus = EAS_STOP;
}

bool SystemProtocol::isFinish()
{
	return _actionStatus == EAS_STOP;
}

bool SystemProtocol::isRunning()
{
	return _actionStatus == EAS_RUNNING;
}
