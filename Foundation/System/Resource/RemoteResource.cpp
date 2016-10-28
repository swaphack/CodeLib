#include "RemoteResource.h"
#include "../Http/import.h"
#include "../Net/import.h"
#include "../Type/import.h"

using namespace sys;

int sys::RemoteResource::s_Tag = 0;

RemoteResource::RemoteResource()
{
	this->setCacheEnable(true);
}

RemoteResource::~RemoteResource()
{

}

bool RemoteResource::loadFileData(const char* filename, std::string& data)
{
	data = "";

	if (filename == nullptr)
	{
		return false;
	}

	std::string fullpath = getFullPath(filename);
	if (fullpath.empty())
	{
		return false;
	}

	if (getCacheData(fullpath.c_str(), data))
	{
		return true;
	}

	String temp = _url.c_str();
	String low = temp.toLower();
	if (!low.startWith("http://"))
	{
		return false;
	}
	std::vector<String> params;
	temp = temp.subString(7, temp.getSize() - 7);
	temp.split(':', params);

	std::string ip = params[0].getString();
	int port = atoi(params[1].getString());

	s_Tag++;
	_downloadPath.insert(std::make_pair(s_Tag, fullpath));


	HttpDownload download;
	download.download(ip.c_str(), port, filename, this, (downloadCallback)&RemoteResource::onDownloadCallback, 1);

	return true;
}

std::string RemoteResource::getFullPath(const char* filename)
{
	std::string fullpath = _url + filename;

	return fullpath;
}

bool RemoteResource::getCacheData(const char* fullpath, std::string& data)
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

void RemoteResource::onDownloadCallback(int tag, const char* data, int size)
{
	if (_downloadPath.find(tag) == _downloadPath.end()) {
		return;
	}
	std::string fullpath = _downloadPath[tag];

	getCache()->set(fullpath.c_str(), std::string(data, size));
}