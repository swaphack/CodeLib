#include "Cameras.h"
#include "Camera.h"

render::Cameras::Cameras()
{
}

render::Cameras::~Cameras()
{
	SAFE_RELEASE(_camera3D);
	SAFE_RELEASE(_camera2D);
	SAFE_RELEASE(_designCamera);
}

render::Camera* render::Cameras::getCamera3D()
{
	return _camera3D;
}

void render::Cameras::setCamera3D(Camera* camera)
{
	SAFE_RETAIN(camera);
	SAFE_RELEASE(_camera3D);
	_camera3D = camera;
}

render::Camera* render::Cameras::getCamera2D()
{
	return _camera2D;
}

void render::Cameras::setCamera2D(Camera* camera)
{
	SAFE_RETAIN(camera);
	SAFE_RELEASE(_camera2D);
	_camera2D = camera;
}

void render::Cameras::setDesignCamera(Camera* camera)
{
	SAFE_RETAIN(camera);
	SAFE_RELEASE(_designCamera);
	_designCamera = camera;
}

render::Camera* render::Cameras::getDesignCamera() const
{
	if (_designCamera == nullptr) return nullptr;
	if (!_designCamera->isVisible()) return nullptr;
	return _designCamera;
}

render::Camera* render::Cameras::getRunningCamera3D() const
{
	auto designCamera = getDesignCamera();
	if (designCamera != nullptr) return designCamera;
	return _camera3D;
}

void render::Cameras::setViewPort(float left, float right, float bottom, float top)
{
	if (_camera2D)
	{
		_camera2D->setViewPort(left, right, bottom, top);
	}
	if (_camera3D)
	{
		_camera3D->setViewPort(left, right, bottom, top);
	}
	if (_designCamera)
	{
		_designCamera->setViewPort(left, right, bottom, top);
	}
}

void render::Cameras::drawScene(Node* scene)
{
	if (_designCamera)
	{
		_designCamera->drawScene(scene);
	}
}
