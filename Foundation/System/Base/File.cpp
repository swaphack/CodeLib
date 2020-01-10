#include "File.h"
#include "Stream/StreamBase.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace sys;

bool File::write(const char* url, const char* data, int64_t size, int64_t& writtenSize)
{
	if (url == nullptr || data == nullptr)
	{
		return false;
	}

	FILE* fptr = nullptr;
	fptr = fopen(url, "wb+");
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

char* File::read(const char* url, int64_t& readSize)
{
	if (url == nullptr)
	{
		return nullptr;
	}

	FILE* fptr = nullptr;
	fptr = fopen(url, "rb+");
	if (fptr == nullptr)
	{
		return nullptr;
	}

	fseek(fptr, 0, SEEK_SET);
	fseek(fptr, 0, SEEK_END);
	int64_t count = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	char* str = StreamHelper::mallocStream(count * sizeof(char));

	readSize = fread(str, sizeof(char), count, fptr);

	fclose(fptr);

	return str;
}

bool File::read(const char* url, std::string& data)
{
	data = "";
	if (url == nullptr)
	{
		return false;
	}

	int64_t size = 0;

	char* temp = read(url, size);
	if (temp == nullptr)
	{
		return false;
	}

	data = std::string(temp, size);

	StreamHelper::freeStream(temp);

	return true;
}

bool File::append(const char* url, const char* data, int64_t size, int64_t& appendSize)
{
	if (url == nullptr || data == nullptr)
	{
		return false;
	}

	FILE* fptr = nullptr;
	fptr = fopen(url, "ab+");
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

bool File::exists(const char* url)
{
	if (url == nullptr)
	{
		return false;
	}

	FILE* fptr = nullptr;
	fptr = fopen(url, "rb");
	if (fptr == nullptr)
	{
		return false;
	}

	fclose(fptr);

	return true;
}

File::File(const char* url)
	:File(url, 0)
{
	
}

File::File(const char* url, int32_t mode)
	: m_pFile(nullptr)
	, m_strUrl(url)
	, m_nModel(mode)
{
	
}

File::~File()
{
	this->close();
}

bool File::write(const char* data, int64_t size, int64_t& writtenSize)
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

char* File::read(int64_t& size)
{
	if (m_pFile == nullptr)
	{
		return nullptr;
	}

	if (m_nModel & eFM_READ)
	{
		return nullptr;
	}

	fseek(m_pFile, 0, SEEK_SET);
	fseek(m_pFile, 0, SEEK_END);
	int64_t count = ftell(m_pFile);
	fseek(m_pFile, 0, SEEK_SET);

	char* str = StreamHelper::mallocStream(count * sizeof(char));

	size = fread(str, sizeof(char), count, m_pFile);

	return str;
}

bool File::read(std::string& data)
{
	int64_t size = 0;

	if (m_nModel & eFM_READ)
	{
		return false;
	}

	char* temp = read(size);
	if (temp == nullptr)
	{
		return false;
	}

	data = std::string(temp, size);

	StreamHelper::freeStream(temp);

	return true;
}

bool File::append(const char* data, int64_t size)
{
	if (m_pFile == nullptr || data == nullptr)
	{
		return false;
	}

	if (m_nModel & eFM_APPEND)
	{
		return false;
	}

	int64_t writtenSize = fwrite(data, sizeof(char), size, m_pFile);

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
