#include "File.h"
#include "Stream/StreamBase.h"
#include "Stream/StreamHelper.h"
#include "Directory.h"
#include "Type/String.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace sys;

bool File::write(const std::string& url, const char* data, size_t size, size_t& writtenSize)
{
	if (url.empty() || data == nullptr)
	{
		return false;
	}
	std::string dir;
	Directory::getDirectory(url, dir);
	Directory::createDirectory(dir);

	FILE* fptr = nullptr;
	fptr = fopen(url.c_str(), "wb+");
	if (fptr == nullptr)
	{
		return false;
	}

	writtenSize = fwrite(data, sizeof(char), size, fptr);
	if (writtenSize != size)
	{
		fclose(fptr);
		return false;
	}

	fclose(fptr);
	return true;
}

bool sys::File::write(const std::string& url, const char* data, size_t size)
{
	size_t writtenSize = 0;

	return write(url, data, size, writtenSize);
}

MemoryData File::read(const std::string& url, size_t& readSize)
{
	readSize = 0;
	MemoryData data;
	if (url.empty())
	{
		return data;
	}

	FILE* fptr = nullptr;
	fptr = fopen(url.c_str(), "rb+");
	if (fptr == nullptr)
	{
		return data;
	}

	fseek(fptr, 0, SEEK_SET);
	fseek(fptr, 0, SEEK_END);
	size_t count = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	data.resize(count);

	char* str = data.getPtr();

	readSize = fread(str, sizeof(char), count, fptr);

	fclose(fptr);

	return data;
}

bool File::read(const std::string& url, std::string& data)
{
	data = "";
	if (url.empty())
	{
		return false;
	}

	size_t size = 0;

	MemoryData memData = read(url, size);
	if (size <= 0)
	{
		return false;
	}

	data = std::string((char*)memData.getValue(), memData.getSize());

	return true;
}

bool File::append(const std::string& url, const char* data, size_t size, size_t& appendSize)
{
	if (url.empty() || data == nullptr)
	{
		return false;
	}

	FILE* fptr = nullptr;
	fptr = fopen(url.c_str(), "ab+");
	if (fptr == nullptr)
	{
		return false;
	}

	appendSize = fwrite(data, sizeof(char), size, fptr);
	if (appendSize != size)
	{
		fclose(fptr);
		return false;
	}

	fclose(fptr);
	return true;
}

bool File::exists(const std::string& url)
{
	if (url.empty())
	{
		return false;
	}

	FILE* fptr = nullptr;
	fptr = fopen(url.c_str(), "rb");
	if (fptr == nullptr)
	{
		return false;
	}

	fclose(fptr);

	return true;
}

std::string File::getFileName(const std::string& fullpath, bool containsFormat)
{
	if (fullpath.empty()) return fullpath;

	sys::String path = fullpath;
	path = path.replace("\\", "/");

	int index = path.findLastOf("/");
	if (index == -1) return fullpath;

	std::string name = fullpath.substr(index + 1,  fullpath.size() - index - 1);

	if (!containsFormat)
	{
		index = name.find_last_of('.');
		if (index != -1) name = fullpath.substr(0, index);
	}
	return name;
}

File::File(const std::string& url)
	:File(url, 0)
{
	
}

File::File(const std::string& url, uint32_t mode)
	: m_pFile(nullptr)
	, m_strUrl(url)
	, m_nModel(mode)
{
	
}

File::~File()
{
	this->close();
}

bool File::write(const char* data, size_t size, size_t& writtenSize)
{
	if (m_pFile == nullptr)
	{
		return false;
	}

	if (m_nModel & eFM_WRITE)
	{
		return false;
	}

	writtenSize = fwrite(data, sizeof(char), size, m_pFile);
	return writtenSize == size;
}

MemoryData File::read(size_t& size)
{
	MemoryData data;
	size = 0;
	if (m_pFile == nullptr)
	{
		return data;
	}

	if (m_nModel & eFM_READ)
	{
		return data;
	}

	fseek(m_pFile, 0, SEEK_SET);
	fseek(m_pFile, 0, SEEK_END);
	size_t count = ftell(m_pFile);
	fseek(m_pFile, 0, SEEK_SET);

	char* str = (char*)malloc(count * sizeof(char));

	size = fread(str, sizeof(char), count, m_pFile);

	return data;
}

bool File::read(std::string& data)
{
	size_t size = 0;

	if (m_nModel & eFM_READ)
	{
		return false;
	}

	MemoryData memData = read(size);
	if (size <= 0)
	{
		return false;
	}

	data = std::string((char*)memData.getValue(), memData.getSize());

	return true;
}

bool File::append(const char* data, size_t size)
{
	if (m_pFile == nullptr || data == nullptr)
	{
		return false;
	}

	if (m_nModel & eFM_APPEND)
	{
		return false;
	}

	size_t writtenSize = fwrite(data, sizeof(char), size, m_pFile);

	return writtenSize != size;
}

bool File::exists()
{
	return m_pFile != nullptr;
}

bool File::close()
{
	if (m_pFile == nullptr)
	{
		return false;
	}

	fclose(m_pFile);
	m_pFile = nullptr;

	return true;
}

bool File::open()
{
	if (m_pFile != nullptr)
	{
		return false;
	}

	std::string strMode;

	if (m_nModel & eFM_READ) strMode.append("r");
	if (m_nModel & eFM_WRITE) strMode.append("w");
	if (m_nModel & eFM_APPEND) strMode.append("a");
	if (m_nModel & eFM_BINARY) strMode.append("+");

	m_pFile = fopen(m_strUrl.c_str(), strMode.c_str());


	return m_pFile != nullptr;
}
