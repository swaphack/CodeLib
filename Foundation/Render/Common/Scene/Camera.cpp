#include "Camera.h"

#include "Common/Tool/import.h"
#include "Graphic/import.h"
#include "Camera3D.h"
#include "DebugDraw.h"

using namespace render;

#define USE_CAMERA_VIEW

Camera::Camera()
{
	_position.set(0,0,0);

	_rotation.set(0, 0, 0);

	_scale.set(1.0f, 1.0f, 1.0f);

	this->setDimensions(DimensionsType::THREE);
	this->setViewDistance(0.1f, 1000000);
}

Camera::~Camera()
{

}

bool Camera::init()
{
	if (!Node::init())
	{
		return false;
	}

	_shapeDraw = CREATE_NODE(DebugDraw);
	_shapeDraw->setCamera(this);
	this->addChild(_shapeDraw, INT_MAX);

	_debugDraw = CREATE_NODE(DebugDraw);
	_debugDraw->setPointSize(10);
	_debugDraw->setCamera(this);
	this->addChild(_debugDraw, INT_MAX);

	this->setZDirection(DirectionProtocol::ZDirectionType::INSIDE);

	addNotifyListener(NodeNotifyType::VIEWSIZE, [this](){
		this->updateViewPort();
	});

	addNotifyListener(NodeNotifyType::SPACE, [this]() {
		this->onCameraSpaceChange();
	});

	return true;
}

void Camera::setViewPort(float left, float right, float bottom, float top)
{
	_viewParameter.xLeft = left;
	_viewParameter.xRight = right;
	_viewParameter.yBottom = bottom;
	_viewParameter.yTop = top;

	this->notify(NodeNotifyType::VIEWSIZE);
}

void render::Camera::setViewDistance(float zNear, float zFar)
{
	_viewParameter.zNear = zNear;
	_viewParameter.zFar = zFar;

	this->notify(NodeNotifyType::VIEWSIZE);
}

const ViewParameter& Camera::getViewParameter()const
{
	return _viewParameter;
}

DimensionsType Camera::getDimensions() const
{
	return _dimensions;
}

void Camera::setDimensions(DimensionsType d)
{
	if (_dimensions == d)
		return;

	_dimensions = d;

	this->notify(NodeNotifyType::VIEWSIZE);
}

void render::Camera::drawScene(Node* scene)
{
	this->visit();
	if (scene == nullptr) return;
	scene->visit();
}

void Camera::visit()
{
	this->updateNode();

	this->drawNode();
}

const math::Matrix4x4& render::Camera::getProjectMatrix() const
{
	return _projectMatrix;
}

const math::Matrix4x4& render::Camera::getViewMatrix() const
{
	return _viewMatrix;
}

math::Matrix4x4 render::Camera::lookAt(const math::Vector3& position)
{
	math::Vector3 pos = _worldMatrix.getPosition();
	math::Matrix4x4 mat = math::Matrix4x4::lookAt(pos, position, this->getUp());
	return mat;
}

math::Matrix4x4 render::Camera::lookAtCenter()
{
	return lookAt(getCenterPosition());
}

math::Vector3 render::Camera::getCenterPosition()
{
	return this->getPosition() + this->getFront();
}
render::DebugDraw* render::Camera::getDebugDraw() const
{
	return _debugDraw;
}
DebugDraw* render::Camera::getShapeDraw() const
{
	return _shapeDraw;
}
void render::Camera::setShapeVisible(bool bVisible)
{
	if (_shapeDraw)
	{
		_shapeDraw->setVisible(bVisible);
	}
}
math::Vector3 render::Camera::project(const math::Vector2& worldPoint) const
{
	return _projectMatrix * _viewMatrix * worldPoint;
}
math::Vector3 render::Camera::unproject(const math::Vector2& viewPoint) const
{
	return (_projectMatrix * _viewMatrix).getInverse() * viewPoint;
}

math::Ray render::Camera::convertScreenPointToLocalRay(const math::Vector2& screenPoint) const
{

#ifdef USE_CAMERA_VIEW
	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();
	float d = _viewParameter.getDepth();

	float halfW = 0.5f * w;
	float halfH = 0.5f * h;

	math::Vector3 src;
	math::Vector3 dest = math::Vector3(screenPoint.getX() - halfW, screenPoint.getY() - halfH, -_viewParameter.zNear);
	math::Vector3 dir = dest - src;
	return math::Ray(src, dir);
#else
	math::Matrix4x4 invMat = (getProjectMatrix() * getViewMatrix()).getInverse();

	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();
	float d = _viewParameter.getDepth();

	float halfW = 0.5f * w;
	float halfH = 0.5f * h;

	float k = _viewParameter.zFar / _viewParameter.zNear;

	float pw = (screenPoint.getX() - halfW) / halfW;
	float ph = (screenPoint.getY() - halfH) / halfH;

	math::Vector4 nearVec = math::Vector4(pw, ph, -1, 1.0f);
	math::Vector4 farVec = math::Vector4(pw, ph, 1, 1.0f);


	math::Vector4 nearResult = invMat * nearVec;
	math::Vector4 farResult = invMat * farVec;
	nearResult /= nearResult.getW();
	farResult /= farResult.getW();

	math::Vector3 dir = farResult - nearResult;
	return math::Ray(nearResult, dir);
#endif // USE_CAMERA_VIEW
}

math::Ray render::Camera::convertScreenPointToWorldRay(const math::Vector2& screenPoint) const
{
	math::Ray ray = convertScreenPointToLocalRay(screenPoint);
	math::Vector3 src = convertLocalToWorldPoint(ray.getSrcPoint());
	math::Vector3 dest = convertLocalToWorldPoint(ray.getDestPoint(1));
	return math::Ray(src, dest - src);
}

math::Vector3 render::Camera::convertScreenToViewPort(const math::Vector2& screenPoint) const
{
	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();

	float x = screenPoint.getX() / w;
	float y = screenPoint.getY() / h;

	return math::Vector3(x,y,0);
}

math::Vector3 render::Camera::convertScreenToWorldPoint(const math::Vector2& screenPoint) const
{
	math::Matrix4x4 invMat = (getProjectMatrix() * getViewMatrix()).getInverse();

	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();
	float d = _viewParameter.getDepth();

	float halfW = 0.5f * w;
	float halfH = 0.5f * h;

	float pw = (screenPoint.getX() - halfW) / halfW;
	float ph = (screenPoint.getY() - halfH) / halfH;

	math::Vector4 nearVec = math::Vector4(pw, ph, -1, 1.0f);

	math::Vector4 nearResult = invMat * nearVec;
	nearResult /= nearResult.getW();

	return nearResult;
}

math::Ray render::Camera::convertViewPortPointToRay(const math::Vector3& viewPortPoint) const
{
	math::Matrix4x4 invMat = (getProjectMatrix() * getViewMatrix()).getInverse();

	float pw = viewPortPoint.getX() * 2 - 1;
	float ph = viewPortPoint.getY() * 2 - 1;

	math::Vector4 nearVec = math::Vector4(pw, ph, -1, 1.0f);
	math::Vector4 farVec = math::Vector4(pw, ph, 1, 1.0f);

	math::Vector4 nearResult = invMat * nearVec;
	math::Vector4 farResult = invMat * farVec;
	nearResult /= nearResult.getW();
	farVec /= farVec.getW();

	math::Vector3 dir = farVec - nearResult;

	return math::Ray(nearResult, dir);
}

math::Vector3 render::Camera::convertViewPortToWorldPoint(const math::Vector3& viewPortPoint) const
{
	math::Matrix4x4 invMat = (getProjectMatrix() * getViewMatrix()).getInverse();

	float pw = viewPortPoint.getX() * 2 - 1;
	float ph = viewPortPoint.getY() * 2 - 1;

	math::Vector4 nearVec = math::Vector4(pw, ph, -1, 1.0f);

	math::Vector4 nearResult = invMat * nearVec;
	nearResult /= nearResult.getW();

	return nearResult;
}

math::Vector3 render::Camera::convertViewPortToScreenPoint(const math::Vector2& viewPortPoint) const
{
	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();
	float d = _viewParameter.getDepth();

	float x = viewPortPoint.getX() * w;
	float y = viewPortPoint.getX() * h;
	float z = viewPortPoint.getX() * d;

	return math::Vector3(x + _viewParameter.xLeft, y + _viewParameter.yBottom, z + _viewParameter.zNear);
}

math::Vector3 render::Camera::convertWorldToViewPort(const math::Vector3& worldPoint) const
{
	math::Vector3 value = project(worldPoint);

	float x = value.getX() * 0.5f + 0.5f;
	float y = value.getY() * 0.5f + 0.5f;
	float z = value.getZ() * 0.5f + 0.5f;

	return math::Vector3(x, y, z);
}

math::Vector3 render::Camera::convertWorldToScreenPoint(const math::Vector2& worldPoint) const
{
	math::Vector3 pos = convertWorldToViewPort(worldPoint);

	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();
	float d = _viewParameter.getDepth();

	return math::Vector3(pos.getX() * w, pos.getY() * h, pos.getZ() * d);
}

void render::Camera::updateViewPort()
{

}

void render::Camera::onCameraSpaceChange()
{
	
	math::Vector3 pos = _worldMatrix.getPosition();

	math::Matrix4x4 matT;
	matT.setRow(3, -1 * pos);

	math::Matrix3x3 rotate = _worldMatrix;
	math::Matrix4x4 matR(rotate.getTranspose());

	_viewMatrix = matT * matR;
}

