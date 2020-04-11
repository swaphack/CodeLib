#include "Canvas.h"

using namespace render;

Canvas::Canvas()
:_dimensions(ED_NONE)
{
	_root = CREATE_NODE(Scene);
	_root->retain();

	_view = new View();

	_actionManager = G_ACTIONMANAGER;

	_touchManager = G_TOUCHMANAGER;

	//_drawCommander = G_DRAWCOMMANDER;
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

	Camera* mainCamera = Camera::getMainCamera();
	ASSERT(mainCamera != nullptr);
	mainCamera->visit();

	_root->visit();

	//_drawCommander->flush();
	GLState::flush();
}

void Canvas::update(float interval)
{
	if (_actionManager)
	{
		_actionManager->update(interval);
	}

	G_AUDIO->update();
}

void Canvas::setDimensions(CameraDimensions d)
{
	if (_dimensions == d)
	{
		return;
	}
	_dimensions = d;
	Camera::setMainCamera(d);
}

CameraDimensions Canvas::getDimensions()
{
	return _dimensions;
}

void Canvas::setViewPort(float x, float y, float width, float height)
{
	_view->setPosition(x, y);
	_view->setFrameSize(width, height);

	_root->setVolume(width, height);

	Tool::setGLViewSize(width, height);
}

Scene* Canvas::getRoot()
{
	return _root;
}

View* Canvas::getView()
{
	return _view;
}
