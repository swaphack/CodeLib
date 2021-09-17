#include "Camera2D.h"
#include "Graphic/import.h"
#include "Cameras.h"
#include "DebugDraw.h"

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

void render::Camera2D::updateView()
{
	GLMatrix::loadOrtho(
		_viewParameter.xLeft,
		_viewParameter.xRight,
		_viewParameter.yBottom,
		_viewParameter.yTop,
		_viewParameter.zNear,
		_viewParameter.zFar);

	GLDebug::showError();
}

void render::Camera2D::updateViewPort()
{
	_projectMatrix = math::Matrix4x4::ortho(
		_viewParameter.xLeft, _viewParameter.xRight,
		_viewParameter.yBottom, _viewParameter.yTop,
		_viewParameter.zNear, _viewParameter.zFar);

	_viewShapeDraw->cleanup();
	_viewShapeDraw->drawOrtho(_viewParameter);
}
