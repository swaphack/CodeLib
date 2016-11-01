#include "Document.h"
#include "Block.h"
#include "Scanner.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace script;


Document::Document()
{
	m_pBlock = new Block();
	m_pScanner = new Scanner();
	m_pScanner->setBlock(m_pBlock);
}

Document::~Document()
{
	delete m_pBlock;
	delete m_pScanner;
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

	bool bRet = this->parse(text, size);

	free(text);

	return bRet;
}

bool Document::parse(const char* text, int size)
{
	if (text == nullptr)
	{
		return false;
	}

	return m_pScanner->read(text, size);
}
