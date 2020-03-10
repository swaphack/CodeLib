#include "View.h"
#include "ext-config.h"

using namespace render;


View::View()
{
}

View::~View()
{
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

void View::initView()
{
	if (isDirty())
	{
		// 定义视窗位置
		glViewport((int)_position.getX(), (int)_position.getY(), (int)_size.getWidth(), (int)_size.getHeight());

		setDirty(false);
	}

	this->applyConfig();

	SHOW_OPENGL_ERROR_MESSAGE();
}

void View::updateView()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glClearStencil(0);

	SHOW_OPENGL_ERROR_MESSAGE();
}

void View::applyConfig()
{
	SHOW_OPENGL_ERROR_MESSAGE();

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClearStencil(0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	SHOW_OPENGL_ERROR_MESSAGE();

	/*
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH, GL_DONT_CARE);

	SHOW_OPENGL_ERROR_MESSAGE();

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH, GL_DONT_CARE);

	SHOW_OPENGL_ERROR_MESSAGE();

	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH, GL_DONT_CARE);

	SHOW_OPENGL_ERROR_MESSAGE();
	*/

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	SHOW_OPENGL_ERROR_MESSAGE();
}
