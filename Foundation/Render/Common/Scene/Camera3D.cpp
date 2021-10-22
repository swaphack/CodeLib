#include "Camera3D.h"
#include "Graphic/import.h"
#include "Cameras.h"
#include "DebugDraw.h"
#include "Common/Tool/Tool.h"

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

	if (w == 0) w = render::Tool::getViewWidth();
	if (h == 0) h = render::Tool::getViewHeight();

	_projectMatrix = math::Matrix4x4::frustum(
		-0.5f * w, 0.5f * w,
		-0.5f * h, 0.5f * h,
		_viewParameter.zNear, _viewParameter.zFar);

	ViewParameter parameter;
	parameter.xLeft = -0.5f * w;
	parameter.xRight = 0.5f * w;
	parameter.yBottom = -0.5f * h;
	parameter.yTop = 0.5f * h;
	parameter.zNear = -_viewParameter.zNear;
	parameter.zFar = -_viewParameter.zFar;

	_shapeDraw->removeAllPoints();
	_shapeDraw->drawFrustum(parameter);
}
