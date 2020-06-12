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

	_viewParameter2D.zNear = 0;
	_viewParameter2D.zFar = 100000;
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

	_notify->addListen(NodeNotifyType::VIEWSIZE, [this](){
		this->updateViewPort();
	});

	return true;
}

void Camera::setViewPort(float left, float right, float bottom, float top)
{
	if (getDimensions() == CameraDimensions::TWO)
	{
		_viewParameter2D.xLeft = left;
		_viewParameter2D.xRight = right;
		_viewParameter2D.yBottom = bottom;
		_viewParameter2D.yTop = top;
	}
	else
	{
		float w = 0.5f * (left + right);
		float h = 0.5f * (bottom + top);

		_viewParameter3D.xLeft = -w;
		_viewParameter3D.xRight = w;
		_viewParameter3D.yBottom = -h;
		_viewParameter3D.yTop = h;
	}

	this->notify(NodeNotifyType::VIEWSIZE);
}

void render::Camera::setViewDistance(float zNear, float zFar)
{
	if (getDimensions() == CameraDimensions::TWO)
	{
		_viewParameter2D.zNear = zNear;
		_viewParameter2D.zFar = zFar;
	}
	else
	{
		_viewParameter3D.zNear = zNear;
		_viewParameter3D.zFar = zFar;
	}
	this->notify(NodeNotifyType::VIEWSIZE);
}

const ViewParameter& Camera::getViewParameter()const
{
	if (getDimensions() == CameraDimensions::TWO)
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

CameraDimensions Camera::getDimensions() const
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

void Camera::setDimensions(CameraDimensions d)
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
	if (getDimensions() == CameraDimensions::TWO)
	{
		GLMatrix::loadOrtho(
			_viewParameter2D.xLeft,
			_viewParameter2D.xRight,
			_viewParameter2D.yBottom,
			_viewParameter2D.yTop,
			_viewParameter2D.zNear,
			_viewParameter2D.zFar);
	}
	else if (getDimensions() == CameraDimensions::THREE)
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

const math::Matrix44& render::Camera::getProjectMatrix() const
{
	return _projectMat;
}

const math::Matrix44& render::Camera::getViewMatrix() const
{
	return _worldMatrix;
}

math::Matrix44 render::Camera::lookAt(const math::Vector3& position)
{
	math::Vector3 pos = _worldMatrix.getPosition();
	math::Vector3 up = _worldMatrix.getEularAngle();
	//up = math::Vector3(0, 1, 0);
	math::Matrix44 mat = math::Matrix44::lookAt(pos, position, up);
	//PRINT("%s\n", mat.toString().c_str());
	//GLMatrix::multMatrix(mat);

	//GLMatrix::multMatrix(_worldMatrix);
	return mat;
}

void render::Camera::updateViewPort()
{
	if (getDimensions() == CameraDimensions::TWO)
	{
		_projectMat = math::Matrix44::ortho(
			_viewParameter2D.xLeft, _viewParameter2D.xRight,
			_viewParameter2D.yBottom, _viewParameter2D.yTop,
			_viewParameter2D.zNear, _viewParameter2D.zFar);
	}
	else if (getDimensions() == CameraDimensions::THREE)
	{
		_projectMat = math::Matrix44::frustum(
			_viewParameter3D.xLeft, _viewParameter3D.xRight,
			_viewParameter3D.yBottom, _viewParameter3D.yTop,
			_viewParameter3D.zNear, _viewParameter3D.zFar);
	}
	GLDebug::showError();
}

