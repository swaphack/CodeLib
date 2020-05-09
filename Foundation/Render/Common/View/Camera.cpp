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

	_dimensions = ED_NONE;
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

	_notify->addListen(ENP_VIEWSIZE, [this](){
		this->updateViewPort();
	});

	return true;
}

void Camera::setViewPortParams(float left, float right, float bottom, float top, float zNear, float zFar)
{
	_cameraParams.xLeft = left;
	_cameraParams.xRight = right;
	_cameraParams.yBottom = bottom;
	_cameraParams.yTop = top;
	_cameraParams.zNear = zNear;
	_cameraParams.zFar = zFar;
}

const CameraParams& Camera::getViewPortParams()const
{
	return _cameraParams;
}

Camera* Camera::getMainCamera()
{
	return _mainCamera;
}

CameraDimensions Camera::getDimensions()
{
	return _dimensions;
}

void Camera::setDimensions(CameraDimensions d)
{
	_dimensions = d;
}

void Camera::visit()
{
	this->notifyEvents();

	GLMatrix::applyProjection();
	
	this->updateTranform();

	this->updateView();

	//GLMatrix::popMatrix();

	this->inverseTranform();
}

void Camera::setMainCamera(CameraDimensions d)
{
	SAFE_RELEASE(_mainCamera);

	if (d == ED_2D)
	{
		_mainCamera = CREATE_NODE(Camera2D);
	}
	else if (d == ED_3D)
	{
		_mainCamera = CREATE_NODE(Camera3D);
	}
	SAFE_RETAIN(_mainCamera);
}

void Camera::updateView()
{

}

void Camera::updateTranform()
{
	GLMatrix::loadIdentity();

	GLMatrix::multMatrix(_localMat);

	GLDebug::showError();
}

void Camera::inverseTranform()
{

}

const math::Matrix44& render::Camera::getProjectMatrix() const
{
	return _projectMat;
}

const math::Matrix44& render::Camera::getViewMatrix() const
{
	return _localMat;
}

void render::Camera::updateViewPort()
{

}

//////////////////////////////////////////////////////////////////////////

Camera2D::Camera2D()
{
	this->setDimensions(ED_2D);
	updateViewPort();
}

Camera2D::~Camera2D()
{

}

void Camera2D::updateView()
{
	

	GLMatrix::loadOrtho(_cameraParams.xLeft,
		_cameraParams.xRight,
		_cameraParams.yBottom,
		_cameraParams.yTop,
		_cameraParams.zNear,
		_cameraParams.zFar);
}

void render::Camera2D::updateViewPort()
{
	const math::Volume& size = Tool::getGLViewSize();
	float x = size.getWidth() / size.getDepth();
	float y = size.getHeight() / size.getDepth();
	float z = size.getDepth() / size.getDepth();
	float zh = z * 0.5f;
	this->setViewPortParams(0, x, 0, y, -zh, zh);

	const CameraParams& params = getViewPortParams();
	_projectMat = math::Matrix44::ortho(params.xLeft, params.xRight, params.yBottom, params.yTop, params.zNear, params.zFar);
}

//////////////////////////////////////////////////////////////////////////

Camera3D::Camera3D()
{
	this->setDimensions(ED_3D);
	updateViewPort();
}

Camera3D::~Camera3D()
{

}

void Camera3D::lookAt(const math::Vector3& position)
{

}

void Camera3D::updateView()
{
	GLMatrix::loadFrustum(_cameraParams.xLeft,
		_cameraParams.xRight,
		_cameraParams.yBottom,
		_cameraParams.yTop,
		_cameraParams.zNear,
		_cameraParams.zFar);
}

void render::Camera3D::updateViewPort()
{
	const math::Volume& size = Tool::getGLViewSize();
	float x = size.getWidth() / size.getDepth();
	float y = size.getHeight() / size.getDepth();
	float z = size.getDepth() / size.getDepth();
	float xh = x * 0.5f;
	float yh = y * 0.5f;
	float zh = z * 0.5f;
	this->setViewPortParams(-xh, xh, -yh, yh, 0.1f, 1.1f);

	const CameraParams& params = getViewPortParams();
	_projectMat = math::Matrix44::perspective(params.xLeft, params.xRight, params.yBottom, params.yTop, params.zNear, params.zFar);
}

