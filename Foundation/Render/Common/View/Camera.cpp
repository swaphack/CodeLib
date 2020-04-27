#include "Camera.h"

#include "Common/Tool/import.h"
#include "Graphic/import.h"

using namespace render;

//--------------------------------------------------------------------------------
// set a perspective frustum (right hand)
// (left, right, bottom, top, near, far)
//--------------------------------------------------------------------------------
math::Matrix44 perspective(float l, float r, float b, float t, float n, float f)
{
	math::Matrix44 mat;

	mat[0] = 2.0f * n / (r - l);
	mat[2] = (r + l) / (r - l);
	mat[5] = 2.0f * n / (t - b);
	mat[6] = (t + b) / (t - b);
	mat[10] = -(f + n) / (f - n);
	mat[11] = -(2.0f * f * n) / (f - n);
	mat[14] = -1.0f;
	mat[15] = 0.0f;

	return mat;
}

//--------------------------------------------------------------------------------
// set a symmetric perspective frustum
// ((vertical, degrees) field of view, (width/height) aspect ratio, near, far)
//--------------------------------------------------------------------------------
math::Matrix44 perspective_vertical(float fov, float aspect, float front, float back)
{
	fov = ANGLE_TO_RADIAN(fov);                      // transform fov from degrees to radians

	float tangent = tanf(fov / 2.0f);               // tangent of half vertical fov
	float height = front * tangent;                 // half height of near plane
	float width = height * aspect;                  // half width of near plane

	return perspective(-width, width, -height, height, front, back);
}

//--------------------------------------------------------------------------------
// set a symmetric perspective frustum
// ((horizontal, degrees) field of view, (width/height) aspect ratio, near, far)
//--------------------------------------------------------------------------------
math::Matrix44 perspective_horizontal(float fov, float aspect, float front, float back)
{
	fov = ANGLE_TO_RADIAN(fov);                      // transform fov from degrees to radians
	fov = 2.0f * atanf(tanf(fov * 0.5f) / aspect);  // transform from horizontal fov to vertical fov

	float tangent = tanf(fov / 2.0f);               // tangent of half vertical fov
	float height = front * tangent;                 // half height of near plane
	float width = height * aspect;                  // half width of near plane

	return perspective(-width, width, -height, height, front, back);
}

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

const CameraParams& Camera::getViewPortParams()
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

	if (_bUseMatrix)
	{
		//PRINT("%s\n", _mat44.toString().c_str());
		GLMatrix::multMatrix(_mat44);
	}
	else
	{
		GLMatrix::translate(_obPosition);
		GLMatrix::scale(_scale);
		GLMatrix::rotate(_rotation);
	}

	GLDebug::showError();
}

void Camera::inverseTranform()
{

}

//////////////////////////////////////////////////////////////////////////

Camera2D::Camera2D()
{
	this->setDimensions(ED_2D);
	this->setViewPortParams(0, 1, 0, 1, -1, 1);
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

//////////////////////////////////////////////////////////////////////////

Camera3D::Camera3D()
{
	this->setDimensions(ED_3D);
	this->setViewPortParams(-0.5f, 0.5f, -0.5f, 0.5f, 0.1f, 100);
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

