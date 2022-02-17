#include "NodeProtocol.h"

#include "Common/Scene/Camera.h"
#include "Common/Scene/Cameras.h"
#include "Common/Scene/Scene.h"

using namespace render;

//////////////////////////////////////////////////////////////////////////
SpaceProtocol::SpaceProtocol()
{
	this->setPosition(0, 0, 0);
	this->setScale(1, 1, 1);
	this->setRotation(0, 0, 0);
	onSpaceChange();
}

SpaceProtocol::~SpaceProtocol()
{

}

void SpaceProtocol::setPosition(float x, float y)
{
	if (_position.getX() == x && _position.getY() == y)
	{
		return;
	}
	_position.set(x, y);
	onSpaceChange();
}

void SpaceProtocol::setPosition(float x, float y, float z)
{
	if (_position.getX() == x && _position.getY() == y && _position.getZ() == z)
	{
		return;
	}
	_position.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setPosition(const math::Vector3& position)
{
	if (_position == position)
	{
		return;
	}
	_position = position;
	onSpaceChange();
}

void SpaceProtocol::setPosition(const math::Vector2& position)
{
	if (_position.getX() == position.getX() && _position.getY() == position.getY())
	{
		return;
	}
	_position = position;

	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getPosition() const
{
	return _position;
}

void SpaceProtocol::setScale(float x, float y, float z)
{
	if (_scale.getX() == x && _scale.getY() == y && _scale.getZ() == z)
	{
		return;
	}
	_scale.set(x, y, z);
	onSpaceChange();
}

void render::SpaceProtocol::setScale(const math::Vector2& scale)
{
	if (_scale.getX() == scale.getX() && _scale.getY() == scale.getY())
	{
		return;
	}
	_scale = scale;
	onSpaceChange();
}

void SpaceProtocol::setScale(const math::Vector3& scale)
{
	if (_scale == scale)
	{
		return;
	}
	_scale = scale;
	onSpaceChange();
}

void SpaceProtocol::setScale(float scale)
{
	if (_scale.getX() == scale && _scale.getY() == scale && _scale.getZ() == scale)
	{
		return;
	}
	_scale.set(scale, scale, scale);
	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getScale() const
{
	return _scale;
}

void SpaceProtocol::setRotation(float x, float y, float z)
{
	if (_rotation.getX() == x && _rotation.getY() == y && _rotation.getZ() == z)
	{
		return;
	}
	_rotation.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setRotation(const math::Vector3& rotation)
{
	if (_rotation == rotation)
	{
		return;
	}
	_rotation = rotation;
	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getRotation() const
{
	return _rotation;
}

void SpaceProtocol::setPositionX(float x)
{
	if (_position.getX() == x)
	{
		return;
	}
	_position.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setPositionY(float y)
{
	if (_position.getY() == y)
	{
		return;
	}
	_position.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setPositionZ(float z)
{
	if (_position.getZ() == z)
	{
		return;
	}
	_position.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getPositionX() const
{
	return _position.getX();
}

float SpaceProtocol::getPositionY() const
{
	return _position.getY();
}

float SpaceProtocol::getPositionZ() const
{
	return _position.getZ();
}

void SpaceProtocol::setScaleX(float x)
{
	if (_scale.getX() == x)
	{
		return;
	}
	_scale.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setScaleY(float y)
{
	if (_scale.getY() == y)
	{
		return;
	}
	_scale.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setScaleZ(float z)
{
	if (_scale.getZ() == z)
	{
		return;
	}
	_scale.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getScaleX() const
{
	return _scale.getX();
}

float SpaceProtocol::getScaleY() const
{
	return _scale.getY();
}

float SpaceProtocol::getScaleZ() const
{
	return _scale.getZ();
}

void SpaceProtocol::setRotationX(float x)
{
	if (_rotation.getX() == x)
	{
		return;
	}
	_rotation.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setRotationY(float y)
{
	if (_rotation.getY() == y)
	{
		return;
	}
	_rotation.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setRotationZ(float z)
{
	if (_rotation.getZ() == z)
	{
		return;
	}
	_rotation.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getRotationX() const
{
	return _rotation.getX();
}

float SpaceProtocol::getRotationY() const
{
	return _rotation.getY();
}

float SpaceProtocol::getRotationZ() const
{
	return _rotation.getZ();
}

//////////////////////////////////////////////////////////////////////////
BodyProtocol::BodyProtocol()
{
	this->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->setVolume(0, 0, 0);
	onBodyChange();
}

BodyProtocol::~BodyProtocol()
{

}

void BodyProtocol::setAnchorPoint(float x, float y, float z)
{
	if (_anchor.getX() == x && _anchor.getY() == y && _anchor.getZ() == z)
	{
		return;
	}
	_anchor.set(x, y, z);
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(float x, float y)
{
	if (_anchor.getX() == x && _anchor.getY() == y)
	{
		return;
	}
	_anchor.set(x, y);
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(const math::Vector3& anchor)
{
	if (_anchor == anchor)
	{
		return;
	}
	_anchor = anchor;
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(const math::Vector2& anchor)
{
	if (_anchor.getX() == anchor.getX() && _anchor.getY() == anchor.getY())
	{
		return;
	}
	_anchor = anchor;
	onBodyChange();
}

const math::Vector3& BodyProtocol::getAnchorPoint() const
{
	return _anchor;
}

void BodyProtocol::setVolume(float w, float h, float d)
{
	if (_volume.getWidth() == w && _volume.getHeight() == h && _volume.getDepth() == d)
	{
		return;
	}
	_volume.set(w, h, d);
	onBodyChange();
}

void BodyProtocol::setVolume(float w, float h)
{
	if (_volume.getWidth() == w && _volume.getHeight() == h)
	{
		return;
	}
	_volume.set(w, h);
	onBodyChange();
}

void BodyProtocol::setVolume(const math::Volume& volume)
{
	if (_volume == volume)
	{
		return;
	}
	_volume = volume;
	onBodyChange();
}

void BodyProtocol::setVolume(const math::Size& size)
{
	if (_volume.getWidth() == size.getWidth() && _volume.getHeight() == size.getHeight())
	{
		return;
	}
	_volume.set(size.getWidth(), size.getHeight());
	onBodyChange();
}

const math::Volume& BodyProtocol::getVolume() const
{
	return _volume;
}

void BodyProtocol::setWidth(float w)
{
	if (_volume.getWidth() == w)
	{
		return;
	}
	_volume.setWidth(w);
	onBodyChange();
}

void BodyProtocol::setHeight(float h)
{
	if (_volume.getHeight() == h)
	{
		return;
	}
	_volume.setHeight(h);
	onBodyChange();
}

void BodyProtocol::setDepth(float d)
{
	if (_volume.getDepth() == d)
	{
		return;
	}
	_volume.setDepth(d);
	onBodyChange();
}

float BodyProtocol::getWidth() const
{
	return _volume.getWidth();
}

float BodyProtocol::getHeight() const
{
	return _volume.getHeight();
}

float BodyProtocol::getDepth() const
{
	return _volume.getDepth();
}

math::Size BodyProtocol::getSize()
{
	return math::Size(_volume.getWidth(), _volume.getHeight());
}

float render::BodyProtocol::getAnchorPointX() const
{
	return _anchor.getX();
}

void render::BodyProtocol::setAnchorPointX(float value)
{
	if (_anchor.getX() == value)
	{
		return;
	}
	_anchor.setX(value);

	onBodyChange();
}

float render::BodyProtocol::getAnchorPointY() const
{
	return _anchor.getY();
}

void render::BodyProtocol::setAnchorPointY(float value)
{
	if (_anchor.getY() == value)
	{
		return;
	}
	_anchor.setY(value);

	onBodyChange();
}

float render::BodyProtocol::getAnchorPointZ() const
{
	return _anchor.getZ();
}

void render::BodyProtocol::setAnchorPointZ(float value)
{
	if (_anchor.getZ() == value)
	{
		return;
	}
	_anchor.setZ(value);

	onBodyChange();
}

//////////////////////////////////////////////////////////////////////////
render::DirectionProtocol::DirectionProtocol()
{
	_up = math::Vector3(0, 1, 0);
	_right = math::Vector3(1, 0, 0);
	_front = math::Vector3(0, 0, 1);

	_defaultUp = math::Vector3(0, 1, 0);
	_defaultRight = math::Vector3(1, 0, 0);
	_defaultFront = math::Vector3(0, 0, 1);

	_zDirection = ZDirectionType::OUTSIDE;
}

render::DirectionProtocol::~DirectionProtocol()
{

}

const math::Vector3& render::DirectionProtocol::getUp() const
{
	return _up;
}

const math::Vector3& render::DirectionProtocol::getRight() const
{
	return _right;
}

const math::Vector3& render::DirectionProtocol::getFront() const
{
	return _front;
}

void render::DirectionProtocol::setZDirection(ZDirectionType type)
{
	_zDirection = type;

	if (type == ZDirectionType::INSIDE)
	{
		_defaultFront = math::Vector3(0, 0, -1);
	}
	else
	{
		_defaultFront = math::Vector3(0, 0, 1);
	}
}

render::DirectionProtocol::ZDirectionType render::DirectionProtocol::getZDirection() const
{
	return _zDirection;
}

const math::Vector3& render::DirectionProtocol::getDefaultUp() const
{
	return _defaultUp;
}

const math::Vector3& render::DirectionProtocol::getDefaultRight() const
{
	return _defaultRight;
}

const math::Vector3& render::DirectionProtocol::getDefaultFront() const
{
	return _defaultFront;
}

void render::DirectionProtocol::setUp(const math::Vector3& up)
{
	_up = up;
}

void render::DirectionProtocol::setRight(const math::Vector3& right)
{
	_right = right;
}

void render::DirectionProtocol::setFront(const math::Vector3& front)
{
	_front = front;
}


//////////////////////////////////////////////////////////////////////////
render::DrawNodeProtocol::DrawNodeProtocol()
{
}

render::DrawNodeProtocol::~DrawNodeProtocol()
{

}

void render::DrawNodeProtocol::setCamera(const Camera* camera)
{
	_camera = (Camera*)camera;
}

Camera* render::DrawNodeProtocol::getCamera() const
{
	if (_bUsedDesignCamera)
	{
		if (G_CAMERAS->getDesignCamera() 
			&& G_CAMERAS->getDesignCamera()->isVisible())
		{
			return G_CAMERAS->getDesignCamera();
		}
	}
	return _camera;
}

Camera* render::DrawNodeProtocol::getRealCamera() const
{
	return _camera;
}

void render::DrawNodeProtocol::setUseDesignCamera(bool bUsed)
{
	_bUsedDesignCamera = bUsed;
}

bool render::DrawNodeProtocol::isUsedDesignCamera() const
{
	return _bUsedDesignCamera;
}

void render::DrawNodeProtocol::setScene(Scene* scene)
{
	_scene = scene;
}

Scene* render::DrawNodeProtocol::getScene() const
{
	return _scene;
}

void render::DrawNodeProtocol::setDrawOrder(int order)
{
	_drawOrder = order;
}

int render::DrawNodeProtocol::getDrawOrder() const
{
	return _drawOrder;
}
