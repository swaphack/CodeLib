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

	_dimensions = CameraDimensions::NONE;
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

void render::Camera::drawNode()
{
	this->startUpdateTranform();

	this->updateView();

	this->endUpdateTranform();
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

void Camera::setMainCamera(CameraDimensions d)
{
	SAFE_RELEASE(_mainCamera);

	if (d == CameraDimensions::TWO)
	{
		_mainCamera = CREATE_NODE(Camera2D);
	}
	else if (d == CameraDimensions::THREE)
	{
		_mainCamera = CREATE_NODE(Camera3D);
	}
	SAFE_RETAIN(_mainCamera);
}

void Camera::updateView()
{

}

void Camera::startUpdateTranform()
{
	//PRINT("%s\n", _worldMatrix.toString().c_str());
	GLMatrix::loadIdentity();

	//GLMatrix::multMatrix(_worldMatrix);

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
	math::Vector3 pos = this->getPosition();
	math::Matrix44 mat = math::Matrix44::lookAt(pos, position, math::Vector3(0, 1, 0));
	//PRINT("%s\n", mat.toString().c_str());
	//GLMatrix::multMatrix(mat);
	return mat;
}

void render::Camera::updateViewPort()
{

}

//////////////////////////////////////////////////////////////////////////

Camera2D::Camera2D()
{
	this->setDimensions(CameraDimensions::TWO);
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
	float x = size.getWidth();
	float y = size.getHeight();
	float z = size.getDepth();
	//float zh = z * 0.5f;
	this->setViewPortParams(0, x, 0, y, 0, 2 * z);

	const CameraParams& params = getViewPortParams();
	_projectMat = math::Matrix44::ortho(params.xLeft, params.xRight, params.yBottom, params.yTop, params.zNear, params.zFar);
}

//////////////////////////////////////////////////////////////////////////

Camera3D::Camera3D()
{
	this->setDimensions(CameraDimensions::THREE);
	updateViewPort();
}

Camera3D::~Camera3D()
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
	float x = size.getWidth() ;
	float y = size.getHeight();
	float z = size.getDepth() ;
	float xh = x * 0.5f;
	float yh = y * 0.5f;
	float zh = z * 0.5f;
	this->setViewPortParams(-xh, xh, -yh, yh, 0.1f, z * 100);
	//this->setViewPortParams(0, x, 0, y, 0.1f, z * 100);

	const CameraParams& params = getViewPortParams();
	_projectMat = math::Matrix44::frustum(params.xLeft, params.xRight, params.yBottom, params.yTop, params.zNear, params.zFar);
}

