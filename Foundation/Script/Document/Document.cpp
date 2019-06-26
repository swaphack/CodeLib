#include "Document.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace script;

Document::Document()
:_buffer(nullptr)
, _size(0)
{
}

Document::~Document()
{
	if (_buffer)
	{
		free(_buffer);
		_buffer = nullptr;
	}
}

bool Document::loadFile(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	FILE* fptr = fopen(filepath, "rb");
	if (fptr == NULL)
	{
		return false;
	}

	fseek(fptr, 0, SEEK_END);
	int size = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	char* text = (char*)malloc(size + 1);
	fread(text, size, 1, fptr);
	fclose(fptr);

	text[size] = '\0';

	if (_buffer)
	{
		free(_buffer);
	}
	_buffer = text;
	_size = size + 1;

	return convertToDocumentStruct();
}

bool Document::saveFile(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	if (!convertToTextStruct()) 
	{ 
		return false;
	}

	FILE* fptr = fopen(filepath, "wb");
	if (fptr == NULL)
	{
		return false;
	}

	fwrite(_buffer, sizeof(char), _size, fptr);
	fclose(fptr);

	return true;
}

char* Document::getPtr()
{
	return _buffer;
}

int Document::getSize()
{
	return _size;
}


