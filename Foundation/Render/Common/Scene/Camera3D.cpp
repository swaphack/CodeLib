#include "Camera3D.h"
#include "Graphic/import.h"
#include "Cameras.h"
#include "DebugDraw.h"


render::Camera3D::Camera3D()
{
	this->setDimensions(DimensionsType::THREE);
	this->setViewDistance(0.1f, 1000);
}

render::Camera3D::~Camera3D()
{
}

bool render::Camera3D::init()
{
	if (!Camera::init())
	{
		return false;
	}
	this->setCamera(G_CAMERAS->getDesignCamera());
	return true;
}

void render::Camera3D::updateViewPort()
{
	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();

	_projectMatrix = math::Matrix4x4::frustum(
		-0.5f * w, 0.5f * w,
		-0.5f * h, 0.5f * h,
		_viewParameter.zNear, _viewParameter.zFar);

	_viewShapeDraw->cleanup();
	_viewShapeDraw->drawFrustum(_viewParameter);
}
