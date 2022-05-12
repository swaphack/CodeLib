#include "RemoteResource.h"
#include "Http/import.h"
#include "Net/import.h"
#include "Type/import.h"
#include "Cache/CacheGroup.h"

using namespace sys;

int32_t RemoteResource::s_Tag = 0;

RemoteResource::RemoteResource()
{
	this->setCacheEnable(true);
}

RemoteResource::~RemoteResource()
{

}

bool RemoteResource::loadFileData(const std::string& filename, GetDataCallback handler)
{
	if (filename.empty())
	{
		return false;
	}

	std::string fullpath = getFullPath(filename);
	if (!fullpath.empty())
	{
		return false;
	}

	std::string data;
	if (getCacheData(fullpath, data))
	{
		if (handler)
		{
			handler(data);
		}
		
		return true;
	}

	s_Tag++;

	DownloadTask task;
	task.tag = s_Tag;
	task.path = fullpath;
	task.handler = handler;

	_downloadTasks.insert(std::make_pair(s_Tag, task));

	HttpDownloadListener downloadHandler(this, (sys::HttpDownloadListener::DownloadedCallback)&RemoteResource::onDownloadCallback);

	HttpDownload download;
	download.startTask(_url, filename, downloadHandler, 1);

	return true;
}

std::string RemoteResource::getFullPath(const std::string& filename)
{
	std::string fullpath = _url + filename;

	return fullpath;
}

bool RemoteResource::getCacheData(const std::string& fullpath, std::string& data)
{
	data = "";
	if (getCache() == nullptr)
	{
		return false;
	}

	if (!getCache()->get(fullpath, data))
	{
		return false;
	}

	return true;
}

void RemoteResource::onDownloadCallback(int32_t tag, const std::string& data)
{
	if (_downloadTasks.find(tag) == _downloadTasks.end()) {
		return;
	}
	DownloadTask task = _downloadTasks[tag];

	getCache()->set(task.path, data);

	if (task.handler)
	{
		task.handler(data);
	}
}