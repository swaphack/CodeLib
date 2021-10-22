#include "Camera2D.h"
#include "Graphic/import.h"
#include "Cameras.h"
#include "DebugDraw.h"
#include "Common/Tool/Tool.h"

render::Camera2D::Camera2D()
{
	this->setDimensions(DimensionsType::TWO);
	this->setViewDistance(-50000, 50000);
}

render::Camera2D::~Camera2D()
{
}

bool render::Camera2D::init()
{
	if (!Camera::init())
	{
		return false;
	}
	this->setCamera(G_CAMERAS->getDesignCamera());
	return true;
}

void render::Camera2D::updateViewPort()
{
	float w = _viewParameter.getWidth();
	float h = _viewParameter.getHeight();

	if (w == 0) w = render::Tool::getViewWidth();
	if (h == 0) h = render::Tool::getViewHeight();

	_projectMatrix = math::Matrix4x4::ortho(
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
	_shapeDraw->drawOrtho(parameter);
}
