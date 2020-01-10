#include "View.h"
#include "ext-config.h"

using namespace render;


View::View()
:_camera(nullptr)
{
	_scale = math::Vector3(1,1,1);
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
	_position.set(x, y);
}

const math::Vector2& View::getPosition()
{
	return _position;
}

void View::setFrameSize(float width, float height)
{
	_size.setWidth(width);
	_size.setHeight(height);
}

const math::Size& View::getFrameSize()
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

void View::setScale(float x, float y, float z)
{
	_scale.setX(x);
	_scale.setY(y);
	_scale.setZ(z);

	_camera->setScale(_scale);
}

math::Vector3 View::getScale()
{
	return _scale;
}

void View::initView()
{
	if (isDirty())
	{
		// 定义视窗位置
		glViewport((int)_position.getX(), (int)_position.getY(), (int)_size.getWidth(), (int)_size.getHeight());
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		setDirty(false);
	}
	_viewConfig.apply();
}

void View::updateView()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glClearStencil(0);
	if (_camera)
	{
		_camera->updateCamera();
	}
}
