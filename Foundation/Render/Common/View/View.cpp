#include "View.h"

#include "../GL/import.h"

using namespace render;


View::View()
:_camera(nullptr)
{

}

View::~View()
{
	SAFE_DELETE(_camera);
}

const ViewConfig* View::getConfig()
{
	return &_viewConfig;
}

void View::setPosition(float x, float y)
{
	_position.x = x;
	_position.y = y;
}

const sys::Point& View::getPosition()
{
	return _position;
}

void View::setFrameSize(float width, float height)
{
	_size.width = width;
	_size.height = height;
}

const sys::Size& View::getFrameSize()
{
	return _size;
}

void View::setCamera(Camera* camera)
{
	SAFE_DELETE(_camera);

	_camera = camera;
}

Camera* View::getCamera()
{
	return _camera;
}

void View::initView()
{
	if (isDirty())
	{
		// 定义视窗位置
		glViewport(_position.x, _position.y, _size.width, _size.height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		setDirty(false);
	}

	_viewConfig.apply();
}

void View::updateView()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
// 	glClearDepth(1.0f);
	if (_camera)
	{
		_camera->updateCamera();
	}
}