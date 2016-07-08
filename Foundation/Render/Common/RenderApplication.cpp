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
	s_application = this;
}

RenderApplication::~RenderApplication()
{
	
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
		// 避免双缓存产生区抖动
		_canvas->draw();
	}

	checkAutoRealsePool();
}

void RenderApplication::dispose()
{
	this->disposeRender();

	this->clearProtocolManagers();
}

Canvas* RenderApplication::getCanvas()
{
	return _canvas;
}

void RenderApplication::setFrameSize( int width, int height )
{
	_frameSize.width = width;
	_frameSize.height = height;
	_canvas->setViewPort(0, 0, width, height);
}

sys::Size& RenderApplication::getFrameSize()
{
	return _frameSize;
}

void RenderApplication::setRefreshInterval( float interval )
{
	_refreshInterval = interval;
}

float RenderApplication::getRefreshInterval()
{
	return _refreshInterval;
}

void RenderApplication::initFilePath()
{
	std::string path;
	sys::Directory::getCurrentDirectory(path);
	std::vector<std::string> allPaths = G_FILEPATH->getSearchPath();
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

void RenderApplication::show()
{

}
