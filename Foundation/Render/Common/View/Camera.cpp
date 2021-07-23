#include "Camera.h"

#include "Common/Tool/import.h"
#include "Graphic/import.h"

using namespace render;

//////////////////////////////////////////////////////////////////////////
Camera* Camera::_mainCamera = nullptr;

Camera::Camera()
{
	_position.set(0,0,0);

	_rotation.set(0, 0, 0);

	_scale.set(1.0f, 1.0f, 1.0f);

	_viewParameter2D.zNear = -50000;
	_viewParameter2D.zFar = 50000;

	_viewParameter3D.zNear = 0.1f;
	_viewParameter2D.zFar = 1000000;
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

	//if (getDimensions() == CameraDimensions::TWO)
	{
		_viewParameter2D.xLeft = -w;
		_viewParameter2D.xRight = w;
		_viewParameter2D.yBottom = -h;
		_viewParameter2D.yTop = h;
	}
	//else
	{
		_viewParameter3D.xLeft = -w;
		_viewParameter3D.xRight = w;
		_viewParameter3D.yBottom = -h;
		_viewParameter3D.yTop = h;
	}

	this->notify(NodeNotifyType::VIEWSIZE);
}

void render::Camera::setViewDistance(float zNear, float zFar)
{
	//if (getDimensions() == CameraDimensions::TWO)
	{
		_viewParameter2D.zNear = zNear;
		_viewParameter2D.zFar = zFar;
	}
	//else
	{
		_viewParameter3D.zNear = zNear;
		_viewParameter3D.zFar = zFar;
	}
	this->notify(NodeNotifyType::VIEWSIZE);
}

const render::ViewParameter& render::Camera::get2DViewParameter() const
{
	return _viewParameter2D;
}

const render::ViewParameter& render::Camera::get3DViewParameter() const
{
	return _viewParameter3D;
}

const ViewParameter& Camera::getViewParameter()const
{
	if (getDimensions() == DimensionsType::TWO)
	{
		return _viewParameter2D;
	}
	else
	{
		return _viewParameter3D;
	}
}

Camera* Camera::getMainCamera()
{
	if (_mainCamera == nullptr)
	{
		_mainCamera = CREATE_NODE(Camera);
		SAFE_RETAIN(_mainCamera);
	}
	return _mainCamera;
}

void Camera::setMainCamera(Camera* camera)
{
	SAFE_RELEASE(_mainCamera);
	SAFE_RETAIN(camera);
	_mainCamera = camera;
}

DimensionsType Camera::getDimensions() const
{
	return _dimensions;
}

void render::Camera::drawNode()
{
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
	_dimensions = d;
}

void Camera::visit()
{
	this->updateNode();

	GLMatrix::applyProjection();
	
	this->drawNode();
}

void Camera::updateView()
{
	if (getDimensions() == DimensionsType::TWO)
	{
		GLMatrix::loadOrtho(
			_viewParameter2D.xLeft,
			_viewParameter2D.xRight,
			_viewParameter2D.yBottom,
			_viewParameter2D.yTop,
			_viewParameter2D.zNear,
			_viewParameter2D.zFar);
	}
	else if (getDimensions() == DimensionsType::THREE)
	{
		GLMatrix::loadFrustum(
			_viewParameter3D.xLeft,
			_viewParameter3D.xRight,
			_viewParameter3D.yBottom,
			_viewParameter3D.yTop,
			_viewParameter3D.zNear,
			_viewParameter3D.zFar);
	}

	GLDebug::showError();
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
	if (getDimensions() == DimensionsType::TWO)
	{
		return _projectMatrix2D;
	}
	else
	{
		return _projectMatrix3D;
	}
}

const math::Matrix4x4& render::Camera::getProjectMatrix2D() const
{
	return _projectMatrix2D;
}

const math::Matrix4x4& render::Camera::getProjectMatrix3D() const
{
	return _projectMatrix3D;
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
			_viewParameter2D.xLeft, _viewParameter2D.xRight,
			_viewParameter2D.yBottom, _viewParameter2D.yTop,
			znear, zfar);
	}
	else if (getDimensions() == DimensionsType::THREE)
	{
		matrix = math::Matrix4x4::frustum(
			_viewParameter3D.xLeft, _viewParameter3D.xRight,
			_viewParameter3D.yBottom, _viewParameter3D.yTop,
			znear, zfar);
	}

	return matrix;
}

math::Matrix4x4 render::Camera::lookAt(const math::Vector3& position)
{
	math::Vector3 pos = _worldMatrix.getPosition();
	math::Matrix4x4 mat = math::Matrix4x4::lookAt(pos, position, math::Vector3(0, 1, 0));
	return mat;
}

math::Matrix4x4 render::Camera::lookAtCenter()
{
	return lookAt(getCenterPosition());
}

math::Vector3 render::Camera::getCenterPosition()
{
	math::Vector3 center;
	if (getDimensions() == DimensionsType::TWO)
	{
		center.setX(0.5f * (_viewParameter2D.xLeft + _viewParameter2D.xRight));
		center.setY(0.5f * (_viewParameter2D.yBottom + _viewParameter2D.yTop));
	}
	else
	{
		center.setX(0.5f * (_viewParameter3D.xLeft + _viewParameter3D.xRight));
		center.setY(0.5f * (_viewParameter3D.yBottom + _viewParameter3D.yTop));
	}

	return center;
}

math::Ray render::Camera::getRayFromScreenPoint(const math::Vector2& screenPoint) const
{
	math::Matrix4x4 invMat = (getProjectMatrix() * getViewMatrix()).getInverse();
	math::Vector3 pos = this->convertLocalPostitionToWorld(this->getPosition());
	math::Vector3 dir;
	float w;
	float h;
	if (getDimensions() == DimensionsType::TWO)
	{
		w = _viewParameter2D.xRight - _viewParameter2D.xLeft;
		h = _viewParameter2D.yTop - _viewParameter2D.yBottom;
	}
	else if (getDimensions() == DimensionsType::THREE)
	{
		w = 0.5f * (_viewParameter3D.xRight - _viewParameter3D.xLeft);
		h = 0.5f * (_viewParameter3D.yTop - _viewParameter3D.yBottom);
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
	//if (getDimensions() == DimensionsType::TWO)
	{
		_projectMatrix2D = math::Matrix4x4::ortho(
			_viewParameter2D.xLeft, _viewParameter2D.xRight,
			_viewParameter2D.yBottom, _viewParameter2D.yTop,
			_viewParameter2D.zNear, _viewParameter2D.zFar);
	}
	//else if (getDimensions() == DimensionsType::THREE)
	{
		_projectMatrix3D = math::Matrix4x4::frustum(
			_viewParameter3D.xLeft, _viewParameter3D.xRight,
			_viewParameter3D.yBottom, _viewParameter3D.yTop,
			_viewParameter3D.zNear, _viewParameter3D.zFar);
	}
	GLDebug::showError();
}

void render::Camera::onCameraSpaceChange()
{
	math::Matrix4x4 mat;
	math::Vector3 pos = _position * -1;
	math::Matrix4x4::getRST(_obRotation, _scale, pos, mat);
	if (this->getParent() == nullptr || !this->isRelativeWithParent())
	{
		_viewMatrix = mat;
	}
	else
	{
		_viewMatrix = mat * this->getParent()->getWorldMatrix();
	}
}

