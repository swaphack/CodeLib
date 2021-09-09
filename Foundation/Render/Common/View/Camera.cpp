#include "Camera.h"

#include "Common/Tool/import.h"
#include "Graphic/import.h"
#include "Camera3D.h"

using namespace render;

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
	float w = 0.5f * (left + right);
	float h = 0.5f * (bottom + top);

	_viewParameter.xLeft = -w;
	_viewParameter.xRight = w;
	_viewParameter.yBottom = -h;
	_viewParameter.yTop = h;

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
void render::Camera::updateCameraView()
{
	GLMatrix::applyProjection();

	GLDebug::showError();
	this->startUpdateTranform();
	GLDebug::showError();
	this->updateView();
	GLDebug::showError();
	this->endUpdateTranform();
	GLDebug::showError();
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
	
	this->updateCameraView();

	this->drawNode();
}

void Camera::updateView()
{
}

void Camera::startUpdateTranform()
{
	//PRINT("%s\n", _worldMatrix.toString().c_str());
	GLMatrix::loadIdentity();
	
	GLMatrix::multMatrix(_worldMatrix);

	GLDebug::showError();
}

void Camera::endUpdateTranform()
{

}

const math::Matrix4x4& render::Camera::getProjectMatrix() const
{
	return _projectMatrix;
}

const math::Matrix4x4& render::Camera::getViewMatrix() const
{
	return _viewMatrix;
}

math::Matrix4x4 render::Camera::getProjectMatrix(float znear, float zfar)
{
	math::Matrix4x4 matrix;

	if (getDimensions() == DimensionsType::TWO)
	{
		matrix = math::Matrix4x4::ortho(
			_viewParameter.xLeft, _viewParameter.xRight,
			_viewParameter.yBottom, _viewParameter.yTop,
			znear, zfar);
	}
	else if (getDimensions() == DimensionsType::THREE)
	{
		matrix = math::Matrix4x4::frustum(
			_viewParameter.xLeft, _viewParameter.xRight,
			_viewParameter.yBottom, _viewParameter.yTop,
			znear, zfar);
	}

	return matrix;
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
	math::Vector3 center;
	center.setX(0.5f * (_viewParameter.xLeft + _viewParameter.xRight));
	center.setY(0.5f * (_viewParameter.yBottom + _viewParameter.yTop));

	return center;
}

math::Ray render::Camera::getRayFromScreenPoint(const math::Vector2& screenPoint) const
{
	math::Matrix4x4 invMat = (getProjectMatrix() * getViewMatrix()).getInverse();
	math::Vector3 pos = this->convertLocalPostitionToWorld(this->getPosition());
	math::Vector3 dir;
	float w = 1;
	float h = 1;
	if (getDimensions() == DimensionsType::TWO)
	{
		w = _viewParameter.xRight - _viewParameter.xLeft;
		h = _viewParameter.yTop - _viewParameter.yBottom;
	}
	else if (getDimensions() == DimensionsType::THREE)
	{
		w = 0.5f * (_viewParameter.xRight - _viewParameter.xLeft);
		h = 0.5f * (_viewParameter.yTop - _viewParameter.yBottom);
	}

	math::Vector4 nearVec = math::Vector4((screenPoint.getX() - w) / w, (screenPoint.getY() - h) / h, -1, 1.0f);
	math::Vector4 farVec = math::Vector4((screenPoint.getX() - w) / w, (screenPoint.getY() - h) / h, 1, 1.0f);

	math::Vector4 nearResult = invMat * nearVec;
	math::Vector4 farResult = invMat * farVec;
	nearResult /= nearResult.getW();
	farResult /= farResult.getW();

	dir = farResult - nearResult;
	
	return math::Ray(pos, dir);
}

void render::Camera::updateViewPort()
{
}

void render::Camera::onCameraSpaceChange()
{
	math::Matrix4x4 mat;
	math::Vector3 pos = _worldMatrix.getPosition();
	math::Vector3 rotate = _worldMatrix.getEularRadian();
	pos *= -1.0f;
	math::Matrix4x4::getRST(rotate, math::Vector3(1,1,1), pos, mat);
	_viewMatrix = mat;
}

