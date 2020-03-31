#include "RemoteResource.h"
#include "Http/import.h"
#include "Net/import.h"
#include "Type/import.h"
#include "Cache/CacheGroup.h"

using namespace sys;

int32_t sys::RemoteResource::s_Tag = 0;

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
	if (getCacheData(fullpath.c_str(), data))
	{
		if (handler)
		{
			handler(data);
		}
		
		return true;
	}

	String temp = _url.c_str();
	String low = temp.toLower();
	if (!low.startWith("http://") || !low.startWith("https://"))
	{
		return false;
	}
	std::vector<String> params;
	if (low.startWith("http://"))
	{
		temp = temp.subString(7, temp.getSize() - 7);
	}
	else if (low.startWith("https://"))
	{
		temp = temp.subString(8, temp.getSize() - 8);
	}
	
	temp.split(':', params);

	std::string ip;
	int32_t port = 80;
	if (params.size() >= 1)
	{
		ip = params[0].getString();
	}

	if (params.size() >= 2)
	{
		port = atoi(params[1].getString());
	}

	s_Tag++;

	DownloadTask task;
	task.tag = s_Tag;
	task.path = fullpath;
	task.handler = handler;

	_downloadTasks.insert(std::make_pair(s_Tag, task));

	HttpDownloadCallback downloadHandler = std::make_pair(this, (downloadCallback)&RemoteResource::onDownloadCallback);

	HttpDownload download;
	download.download(ip.c_str(), port, filename, downloadHandler, 1);

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