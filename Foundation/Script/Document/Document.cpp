#include "Document.h"

#include <cstring>
#include <cstdlib>

using namespace script;


Document::Document()
:m_pContent(nullptr)
,m_nSize(0)
,m_nOffset(0)
{

}

Document::~Document()
{
	free(m_pContent);
}

bool Document::loadString(const char* text)
{
	if (text == nullptr)
	{
		return false;
	}
	m_nSize = strlen(text);
	m_nOffset = 0;

	m_pContent = (char*)malloc(m_nSize + 1);
	memcpy(m_pContent, text, m_nSize);
	m_pContent[m_nSize] = '\0';

	return true;
}

char* Document::getPtr()
{
	return m_pContent + m_nOffset;
}
