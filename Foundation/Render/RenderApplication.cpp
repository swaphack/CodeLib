#include "RenderApplication.h"
#include <ctime>
#include <direct.h>

using namespace render;

#define INVALID_CLOCK -1
#define REFRESH_INTERVAL (1.0f / 15)

static RenderApplication* s_application = nullptr;

RenderApplication::RenderApplication()
	:_canvas(nullptr)
	,_lastClock(INVALID_CLOCK)
	,_refreshInterval(REFRESH_INTERVAL)
{
	ASSERT(s_application == nullptr);

	s_application = this;
	this->init();
}

RenderApplication::~RenderApplication()
{
	this->dispose();
}

void RenderApplication::init()
{
	this->initProtocolManagers();

	this->initRender();

	this->initFilePath();
}

void RenderApplication::update()
{
	if (_lastClock == INVALID_CLOCK)
	{
		_lastClock = clock();
	}

	long nowClock = clock();

	float interval = (float)(nowClock - _lastClock) / CLOCKS_PER_SEC;

	if (_canvas)
	{
		if (interval >= _refreshInterval)
		{
			_canvas->update(interval);
			_lastClock = nowClock;
		}
		// ����˫�������������
		_canvas->draw();
	}

	G_TOUCHMANAGER->process();

	checkAutoRealsePool();
}

void RenderApplication::dispose()
{
	removeAllWndProtocols();

	this->disposeRender();

	this->clearProtocolManagers();
}

void render::RenderApplication::show()
{
}

Canvas* RenderApplication::getCanvas() const
{
	return _canvas;
}

void RenderApplication::setFrameSize( int width, int height )
{
	_frameSize.setWidth(width);
	_frameSize.setHeight(height);
	_canvas->setViewPort(0, 0, width, height);

	for (auto item : _windowProtocols)
	{
		item->onWindowSizeChange(_frameSize);
	}
}

const math::Size& RenderApplication::getFrameSize() const
{
	return _frameSize;
}

void RenderApplication::setRefreshInterval( float interval )
{
	_refreshInterval = interval;
}

float RenderApplication::getRefreshInterval() const
{
	return _refreshInterval;
}

void RenderApplication::initFilePath()
{
	std::string path;
	sys::Directory::getCurrentDirectory(path);
	std::vector<std::string> allPaths = G_FILEPATH->getSearchPath();
	allPaths.push_back("");
	allPaths.push_back(path);
	G_FILEPATH->setSearchPath(allPaths);
}

void RenderApplication::initRender()
{
	_canvas = new Canvas();
}

void RenderApplication::disposeRender()
{
	SAFE_DELETE(_canvas);
}

void RenderApplication::initProtocolManagers()
{

}

void RenderApplication::addWndProtocol(WindowProtocol* obj)
{
	if (obj == nullptr)
	{
		return;
	}

	_windowProtocols.insert(obj);
}

void RenderApplication::removeWndProtocol(WindowProtocol* obj)
{
	if (obj == nullptr)
	{
		return;
	}

	_windowProtocols.erase(obj);
}

void RenderApplication::removeAllWndProtocols()
{
	_windowProtocols.clear();
}

RenderApplication* render::RenderApplication::getInstance()
{
	return s_application;
}
