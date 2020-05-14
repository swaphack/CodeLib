#include "Canvas.h"

using namespace render;

Canvas* render::Canvas::_sCanvas = nullptr;

Canvas::Canvas()
{
	ASSERT(_sCanvas == nullptr);

	_view = new View();

	_actionManager = G_ACTIONMANAGER;

	_touchManager = G_TOUCHMANAGER;

	_sCanvas = this;
}

Canvas::~Canvas()
{
	SAFE_DELETE(_view);

	this->removeAllScenes();
}

void Canvas::draw()
{
	_view->initView();
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

	GLRender::flush();
}

void Canvas::update(float interval)
{
	if (_actionManager)
	{
		_actionManager->update(interval);
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
		pCamera->notify(NodeNotifyType::VIEWSIZE);
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

const TouchManager* render::Canvas::getTouchManager()
{
	return _touchManager;
}

const ActionManager* render::Canvas::getActionManager()
{
	return _actionManager;
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


