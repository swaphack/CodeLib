#include "Script.h"
#include "Document/import.h"
#include <cstdio>
#include <cstdlib>

using namespace script;

Script* Script::s_script = nullptr;

Script::Script()
{
	_document = new Document();
}

Script::~Script()
{
	delete _document;
}

Script* Script::getInstance()
{
	if (s_script == nullptr)
	{
		s_script = new Script();
	}

	return s_script;

}

bool Script::load(const char* filepath)
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
	
	bool bRet = loadString(text);
	free(text);

	return bRet;
}

bool Script::loadString(const char* text)
{
	if (text == nullptr)
	{
		return false;
	}

	return _document->loadString(text);
}

void Script::run()
{

}
