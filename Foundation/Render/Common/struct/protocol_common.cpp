#include "protocol_common.h"
#include "Common/struct/shape_common.h"
#include "Graphic/GLAPI/macros.h"

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

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	_color.red = r;
	_color.green = g;
	_color.blue = b;
}

void ColorProtocol::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
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
}

const sys::Color4B& ColorProtocol::getColor()
{
	return _color;
}

//////////////////////////////////////////////////////////////////////////
OpacityProtocol::OpacityProtocol()
:_opacity(255)
{

}

OpacityProtocol::~OpacityProtocol()
{

}

void OpacityProtocol::setOpacity(uint8_t opacity)
{
	_opacity = opacity;
}

uint8_t OpacityProtocol::getOpacity()
{
	return _opacity;
}

//////////////////////////////////////////////////////////////////////////
BlendProtocol::BlendProtocol()
{
}

BlendProtocol::~BlendProtocol()
{

}

void BlendProtocol::setBlend(BlendingFactorSrc src, BlendingFactorDest dest)
{
	_blend.src = src;
	_blend.dest = dest;
}

void BlendProtocol::setBlend(const BlendParam& blend)
{
	_blend.src = blend.src;
	_blend.dest = blend.dest;
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
	_position.set(x, y);
	onSpaceChange();
}

void SpaceProtocol::setPosition(float x, float y, float z)
{
	_position.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setPosition(const math::Vector3& position)
{
	_position = position;
	onSpaceChange();
}

void SpaceProtocol::setPosition(const math::Vector2& position)
{
	_position = position;

	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getPosition()
{
	return _position;
}

void SpaceProtocol::setScale(float x, float y, float z)
{
	_scale.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setScale(const math::Vector3& scale)
{
	_scale = scale;
	onSpaceChange();
}

void SpaceProtocol::setScale(float scale)
{
	_scale.set(scale, scale, scale);
	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getScale()
{
	return _scale;
}

void SpaceProtocol::setRotation(float x, float y, float z)
{
	_rotation.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setRotation(const math::Vector3& rotation)
{
	_rotation = rotation;
	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getRotation()
{
	return _rotation;
}

void SpaceProtocol::setPositionX(float x)
{
	_position.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setPositionY(float y)
{
	_position.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setPositionZ(float z)
{
	_position.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getPositionX()
{
	return _position.getX();
}

float SpaceProtocol::getPositionY()
{
	return _position.getY();
}

float SpaceProtocol::getPositionZ()
{
	return _position.getZ();
}

void SpaceProtocol::setScaleX(float x)
{
	_scale.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setScaleY(float y)
{
	_scale.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setScaleZ(float z)
{
	_scale.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getScaleX()
{
	return _scale.getX();
}

float SpaceProtocol::getScaleY()
{
	return _scale.getY();
}

float SpaceProtocol::getScaleZ()
{
	return _scale.getZ();
}

void SpaceProtocol::setRotationX(float x)
{
	_rotation.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setRotationY(float y)
{
	_rotation.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setRotationZ(float z)
{
	_rotation.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getRotationX()
{
	return _rotation.getX();
}

float SpaceProtocol::getRotationY()
{
	return _rotation.getY();
}

float SpaceProtocol::getRotationZ()
{
	return _rotation.getZ();
}

//////////////////////////////////////////////////////////////////////////
BodyProtocol::BodyProtocol()
{
	this->setAnchorPoint(0.5, 0.5, 0.5);
	this->setVolume(0, 0, 0);
}

BodyProtocol::~BodyProtocol()
{

}

void BodyProtocol::setAnchorPoint(float x, float y, float z)
{
	_anchor.set(x, y, z);
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(float x, float y)
{
	_anchor.set(x, y);
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(const math::Vector3& anchor)
{
	_anchor = anchor;
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(const math::Vector2& anchor)
{
	_anchor = anchor;
	onBodyChange();

}

const math::Vector3& BodyProtocol::getAnchorPoint()
{
	return _anchor;
}

void BodyProtocol::setVolume(float w, float h, float d)
{
	_volume.set(w, h, d);
	onBodyChange();
}

void BodyProtocol::setVolume(float w, float h)
{
	_volume.set(w, h);
	onBodyChange();
}

void BodyProtocol::setVolume(const math::Volume& volume)
{
	_volume = volume;
	onBodyChange();
}

void BodyProtocol::setVolume(const math::Size& size)
{
	_volume.set(size.getWidth(), size.getHeight());
	onBodyChange();
}

const math::Volume& BodyProtocol::getVolume()
{
	return _volume;
}

void BodyProtocol::setWidth(float w)
{
	_volume.setWidth(w);
	onBodyChange();
}

void BodyProtocol::setHeight(float h)
{
	_volume.setHeight(h);
	onBodyChange();
}

void BodyProtocol::setDepth(float d)
{
	_volume.setDepth(d);
	onBodyChange();
}

float BodyProtocol::getWidth()
{
	return _volume.getWidth();
}

float BodyProtocol::getHeight()
{
	return _volume.getHeight();
}

float BodyProtocol::getDepth()
{
	return _volume.getDepth();
}

math::Size BodyProtocol::getSize()
{
	return math::Size(_volume.getWidth(), _volume.getWidth());
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