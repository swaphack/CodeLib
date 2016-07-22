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

void ColorProtocol::setColor(const sys::Color4B& color)
{
	_color = color;
}

void ColorProtocol::setColor(const sys::Color3B& color)
{
	_color.red = color.red;
	_color.green = color.green;
	_color.blue = color.blue;
	_color.red = 255;
}

const sys::Color4B& ColorProtocol::getColor()
{
	return _color;
}

//////////////////////////////////////////////////////////////////////////
BlendProtocol::BlendProtocol()
{

}

BlendProtocol::~BlendProtocol()
{

}

void BlendProtocol::setBlend(int src, int dest)
{
	_blend.src = src;
	_blend.dest = dest;
}

const BlendParam& BlendProtocol::getBlend()
{
	return _blend;
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

//////////////////////////////////////////////////////////////////////////
SpaceProtocol::SpaceProtocol()
{
	this->setPosition(0, 0, 0);
	this->setScale(1, 1, 1);
	this->setRotation(0, 0, 0);
}

SpaceProtocol::~SpaceProtocol()
{

}

void SpaceProtocol::setPosition(float x, float y)
{
	_position.x = x;
	_position.y = y; 
	onSpaceChange();
}

void SpaceProtocol::setPosition(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	onSpaceChange();
}

void SpaceProtocol::setPosition(const sys::Vector& position)
{
	_position = position;
	onSpaceChange();
}

const sys::Vector& SpaceProtocol::getPosition()
{
	return _position;
}

void SpaceProtocol::setScale(float x, float y, float z)
{
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
	onSpaceChange();
}

void SpaceProtocol::setScale(const sys::Vector& scale)
{
	_scale = scale;
	onSpaceChange();
}

const sys::Vector& SpaceProtocol::getScale()
{
	return _scale;
}

void SpaceProtocol::setRotation(float x, float y, float z)
{
	_rotation.x = x;
	_rotation.y = y;
	_rotation.z = z;
	onSpaceChange();
}

void SpaceProtocol::setRotation(const sys::Vector& rotation)
{
	_rotation = rotation;
	onSpaceChange();
}

const sys::Vector& SpaceProtocol::getRotation()
{
	return _rotation;
}

void SpaceProtocol::setPositionX(float x)
{
	_position.x = x;
	onSpaceChange();
}

void SpaceProtocol::setPositionY(float y)
{
	_position.y = y;
	onSpaceChange();
}

void SpaceProtocol::setPositionZ(float z)
{
	_position.z = z;
	onSpaceChange();
}

float SpaceProtocol::getPositionX()
{
	return _position.x;
}

float SpaceProtocol::getPositionY()
{
	return _position.y;
}

float SpaceProtocol::getPositionZ()
{
	return _position.z;
}

void SpaceProtocol::setScaleX(float x)
{
	_scale.x = x;
	onSpaceChange();
}

void SpaceProtocol::setScaleY(float y)
{
	_scale.y = y;
	onSpaceChange();
}

void SpaceProtocol::setScaleZ(float z)
{
	_scale.z = z;
	onSpaceChange();
}

float SpaceProtocol::getScaleX()
{
	return _scale.x;
}

float SpaceProtocol::getScaleY()
{
	return _scale.y;
}

float SpaceProtocol::getScaleZ()
{
	return _scale.z;
}

void SpaceProtocol::setRotationX(float x)
{
	_rotation.x = x;
	onSpaceChange();
}

void SpaceProtocol::setRotationY(float y)
{
	_rotation.y = y;
	onSpaceChange();
}

void SpaceProtocol::setRotationZ(float z)
{
	_rotation.z = z;
	onSpaceChange();
}

float SpaceProtocol::getRotationX()
{
	return _rotation.x;
}

float SpaceProtocol::getRotationY()
{
	return _rotation.y;
}

float SpaceProtocol::getRotationZ()
{
	return _rotation.z;
}

//////////////////////////////////////////////////////////////////////////
BodyProtocol::BodyProtocol()
{
	this->setAnchorPoint(0.5, 0.5, 0.5);
	this->setVolume(1, 1, 1);
}

BodyProtocol::~BodyProtocol()
{

}

void BodyProtocol::setAnchorPoint(float x, float y, float z)
{
	_anchor.x = x;
	_anchor.y = y;
	_anchor.z = z;
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(const sys::Vector& anchor)
{
	_anchor = anchor;
	onBodyChange();
}

const sys::Vector& BodyProtocol::getAnchorPoint()
{
	return _anchor;
}

void BodyProtocol::setVolume(float w, float h, float d)
{
	_volume.width = w;
	_volume.height = h;
	_volume.deep = d;
	onBodyChange();
}

void BodyProtocol::setVolume(const sys::Volume& volume)
{
	_volume = volume;
	onBodyChange();
}

void BodyProtocol::setSize(const sys::Size& size)
{
	_volume.width = size.width;
	_volume.height = size.height;
	_volume.deep = 0;

	onBodyChange();
}

const sys::Volume& BodyProtocol::getVolume()
{
	return _volume;
}

void BodyProtocol::setWidth(float w)
{
	_volume.width = w;
	onBodyChange();
}

void BodyProtocol::setHeight(float h)
{
	_volume.height = h;
	onBodyChange();
}

void BodyProtocol::setDeep(float d)
{
	_volume.deep = d;
	onBodyChange();
}

float BodyProtocol::getWidth()
{
	return _volume.width;
}

float BodyProtocol::getHeight()
{
	return _volume.height;
}

float BodyProtocol::getDeep()
{
	return _volume.deep;
}

sys::Size BodyProtocol::getSize()
{
	return sys::Size(_volume.width, _volume.height);
}

//////////////////////////////////////////////////////////////////////////
TextProtocol::TextProtocol()
:_textBody("")
{

}

TextProtocol::~TextProtocol()
{

}

void TextProtocol::setString(const char* text)
{
	if (text)
	{
		_textBody = text;
	}
}

const char* TextProtocol::getString()
{
	return _textBody.c_str();
}
