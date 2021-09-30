#include "Cameras.h"
#include "Camera.h"

render::Cameras::Cameras()
{
}

render::Cameras::~Cameras()
{	
	for (auto item : _cameras)
	{
		SAFE_RELEASE(item.second);
	}
}

render::Camera* render::Cameras::getCamera3D() const
{
	return getCamera(CameraType::THREE);
}

void render::Cameras::setCamera3D(Camera* camera)
{
	setCamera(CameraType::THREE, camera);
}

render::Camera* render::Cameras::getCamera2D() const
{
	return getCamera(CameraType::TWO);
}

void render::Cameras::setCamera2D(Camera* camera)
{
	setCamera(CameraType::TWO, camera);
}

void render::Cameras::setDesignCamera(Camera* camera)
{
	setCamera(CameraType::DESIGN, camera);
}

render::Camera* render::Cameras::getDesignCamera() const
{
	auto camera = getCamera(CameraType::DESIGN);
	if (camera == nullptr) return nullptr;
	if (!camera->isVisible()) return nullptr;
	return camera;
}

render::Camera* render::Cameras::getRunningCamera3D() const
{
	auto designCamera = getDesignCamera();
	if (designCamera != nullptr) return designCamera;
	return getCamera3D();
}

void render::Cameras::setViewPort(float left, float right, float bottom, float top)
{
	_viewPort.setX(left);
	_viewPort.setY(right);
	_viewPort.setZ(bottom);
	_viewPort.setW(top);

	updateViewSize();
}

void render::Cameras::drawScene(Node* scene)
{
	auto designCamera = getRunningCamera3D();
	if (designCamera)
	{
		designCamera->drawScene(scene);
	}
}

void render::Cameras::updateViewSize()
{
	for (auto item : _cameras)
	{
		item.second->setViewPort(_viewPort.getX(), _viewPort.getY(), _viewPort.getZ(), _viewPort.getW());
	}
}

void render::Cameras::setCamera(CameraType eType, Camera* camera)
{
	SAFE_RETAIN(camera);
	auto it = _cameras.find(eType);
	if (it != _cameras.end()) 
		SAFE_RELEASE(it->second);
	_cameras[eType] = camera;
	updateViewSize();
}

render::Camera* render::Cameras::getCamera(CameraType eType) const
{
	auto it = _cameras.find(eType);
	if (it == _cameras.end()) return nullptr;
	return it->second;
}
