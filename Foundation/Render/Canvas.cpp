#include "Canvas.h"

using namespace render;

Canvas* render::Canvas::_sCanvas = nullptr;

Canvas::Canvas()
{
	ASSERT(_sCanvas == nullptr);

	_view = new View();

	_sCanvas = this;
}

Canvas::~Canvas()
{
	SAFE_DELETE(_view);

	this->removeAllScenes();
}

void Canvas::draw()
{
	_view->initViewPort();
	_view->applyConfig();
	_view->updateView();

	Camera* mainCamera = Camera::getMainCamera();
	if (mainCamera)
	{
		mainCamera->visit();
	}

	auto pTop = getCurScene();
	if (pTop)
	{
		pTop->visit();
	}

	//GLRender::flush();
}

void Canvas::update(float interval)
{
	if (G_ACTIONMANAGER)
	{
		G_ACTIONMANAGER->update(interval);
	}

	G_AUDIO->update();
}

void Canvas::setViewPort(float x, float y, float width, float height)
{
	_view->setPosition(x, y);
	_view->setFrameSize(width, height);

	auto pTop = getCurScene();
	if (pTop)
	{
		pTop->notifyToAll(NodeNotifyType::SPACE);
	}

	auto pCamera = Camera::getMainCamera();
	if (pCamera)
	{
		pCamera->setViewPort(x, x + width, y, y + height);
	}

	Tool::setGLViewSize(width, height);
}

Scene* Canvas::getCurScene()
{
	if (_scenes.empty())
	{
		return nullptr;
	}
	return _scenes.top();
}

View* Canvas::getView()
{
	return _view;
}

void render::Canvas::pushScene(Scene* scene)
{
	if (scene == nullptr)
	{
		return;
	}

	SAFE_RETAIN(scene);

	_scenes.push(scene);
}

Scene* render::Canvas::popScene()
{
	if (_scenes.empty())
	{
		return nullptr;
	}

	auto pScene = _scenes.top();
	SAFE_RELEASE(pScene);
	_scenes.pop();

	return pScene;
}

void render::Canvas::replaceScene(Scene* scene)
{
	if (scene == nullptr)
	{
		return;
	}

	this->popScene();
	this->pushScene(scene);
}

void render::Canvas::removeAllScenes()
{
	while (!_scenes.empty())
	{
		auto pScene = _scenes.top();
		SAFE_RELEASE(pScene);
		_scenes.pop();
	}
}

bool render::Canvas::hasScene()
{
	return !_scenes.empty();
}

Canvas* render::Canvas::getInstance()
{
	return _sCanvas;
}