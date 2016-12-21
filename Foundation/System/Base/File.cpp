#include "File.h"
#include "../Stream/StreamBase.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace sys;

bool File::write(const char* url, const char* data, long size)
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

	fwrite(data, sizeof(char), size, fptr);
	fclose(fptr);

	return true;
}

char* File::read( const char* url, long& size )
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
	long count = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	char* str = StreamHelper::mallocStream(count * sizeof(char));

	fread(str, sizeof(char), count, fptr);

	fclose(fptr);

	size = count;

	return str;
}

bool File::read(const char* url, std::string& data)
{
	data = "";
	if (url == nullptr)
	{
		return false;
	}

	long size = 0;

	char* temp = read(url, size);
	if (temp == nullptr)
	{
		return false;
	}

	data = std::string(temp, size);

	free(temp);

	return true;
}

bool File::append(const char* url, const char* data, long size)
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

	fwrite(data, sizeof(char), size, fptr);
	fclose(fptr);

	return true;
}

bool File::isFileExists(const char* url)
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