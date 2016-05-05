#include "File.h"
#include "../Stream/StreamBase.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace sys;

void File::write( const char* url, const char* data, long size)
{
	if (url == nullptr || data == nullptr)
	{
		return;
	}

	FILE* fptr = fopen(url, "wb+");
	if (fptr == nullptr)
	{
		return;
	}

	fwrite(data, sizeof(char), size, fptr);

	fclose(fptr);
}

char* File::read( const char* url, long& size )
{
	if (url == nullptr)
	{
		return nullptr;
	}

	FILE* fptr = fopen(url, "rb");
	if (fptr == nullptr)
	{
		return nullptr;
	}
	fseek(fptr, 0, SEEK_SET);
	fseek(fptr, 0, SEEK_END);
	long count = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

// 	char* str = (char*)malloc(count * sizeof(char));
// 	memset(str, 0, count);

	char* str = StreamHelper::mallocStream(count * sizeof(char));

	fread(str, sizeof(char), count, fptr);

	fclose(fptr);

	size = count;

	return str;
}

bool File::isExistsFile(const char* url)
{
	if (url == nullptr)
	{
		return false;
	}

	FILE* fptr = fopen(url, "rb");
	if (fptr == nullptr)
	{
		return false;
	}

	fclose(fptr);

	return true;
}
