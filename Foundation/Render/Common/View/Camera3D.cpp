#include "Camera3D.h"
#include "Graphic/import.h"

render::Camera3D::Camera3D()
{
	this->setDimensions(DimensionsType::THREE);
	this->setViewDistance(0.1f, 1000000);
}

render::Camera3D::~Camera3D()
{
}

void render::Camera3D::updateView()
{
	GLMatrix::loadFrustum(
		_viewParameter.xLeft,
		_viewParameter.xRight,
		_viewParameter.yBottom,
		_viewParameter.yTop,
		_viewParameter.zNear,
		_viewParameter.zFar);
	GLDebug::showError();
}

void render::Camera3D::updateViewPort()
{
	_projectMatrix = math::Matrix4x4::frustum(
		_viewParameter.xLeft, _viewParameter.xRight,
		_viewParameter.yBottom, _viewParameter.yTop,
		_viewParameter.zNear, _viewParameter.zFar);
}
