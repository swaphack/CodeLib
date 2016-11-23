#include "Canvas.h"

using namespace render;

Canvas::Canvas()
:_dimensions(ED_NONE)
{
	_root = new Scene();
	_view = new View();
	_root->setView(_view);

	_actionManager = G_ACTIONMANAGER;

	_touchManager = G_TOUCHMANAGER;

	_drawCommander = G_DRAWCOMMANDER;
}

Canvas::~Canvas()
{
	SAFE_DELETE(_root);
	SAFE_DELETE(_view);
}

void Canvas::draw()
{
	_view->initView();
	_view->updateView();

	_root->init();
	//_root->calculate();
	_root->visit();
	//glFlush();

	_drawCommander->flush();
}

void Canvas::update(float interval)
{
	if (_actionManager)
	{
		_actionManager->update(interval);
	}
}

void Canvas::setDimensions(Dimensions d)
{
	if (_dimensions == d)
	{
		return;
	}
	_dimensions = d;

	if (_dimensions == ED_2D)
	{
		_view->setCamera(new Camera2D());
	}
	else if (_dimensions == ED_3D)
	{
		_view->setCamera(new Camera3D());
	}
	else
	{
		_view->setCamera(nullptr);
	}
	_view->setDirty(true);
}

Dimensions Canvas::getDimensions()
{
	return _dimensions;
}

void Canvas::setViewPort(float x, float y, float width, float height)
{
	_view->setPosition(x, y);
	_view->setFrameSize(width, height);
	_view->setDirty(true);
	Tool::setGLViewSize(width, height);
}

Scene* Canvas::getRoot()
{
	return _root;
}

Camera* Canvas::getCamera()
{
	if (_view == nullptr)
	{
		return nullptr;
	}

	return _view->getCamera();
}




