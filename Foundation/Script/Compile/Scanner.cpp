#include "Scanner.h"
#include "KeyWord.h"
using namespace script;

Scanner::Scanner()
:m_pContent(nullptr)
, m_nOffset(0)
, m_nSize(0)
{
}

Scanner::~Scanner()
{
	if (m_pContent != nullptr)
	{
		free(m_pContent);
		m_pContent = nullptr;
	}
}

bool Scanner::read(const char* ptr, int size)
{
	if (ptr == nullptr || size <= 0)
	{
		return false;
	}

	this->clear();

	m_pContent = (char*)malloc(size + 1);
	memcpy(m_pContent, ptr, size);
	m_pContent[size] = '\0';
	m_nSize = size;

	return this->parse();
}

void Scanner::clear()
{
	if (m_pContent != nullptr)
	{
		free(m_pContent);
		m_pContent = nullptr;
	}

	m_nSize = 0; 
	m_nOffset = 0;
	m_vWords.clear();
}
bool Scanner::parse()
{
	do 
	{
		if (strcmp(getPtr(), "\0") == 0)
		{
			break;
		}

		if (m_nOffset >= m_nSize)
		{
			break;
		}

		readWord();

	} while (true);

	return true;
}

void Scanner::readWord()
{
	int offset = 0;
	std::string word = "";
	do 
	{
		char ch = *getPtr();
		if (ch == ' ' || ch == '\r' || ch == '\n')
		{// 排除空格，回车，换行
			m_nOffset++;
			break;
		}

		word.append(1, ch);

		m_nOffset++;
	} while (true);

	if (word.size() > 0)
	{
		m_vWords.push_back(word);
	}
}

char* Scanner::getPtr()
{
	return m_pContent + m_nOffset;
}

bool Scanner::isVariableFormat(const char* text)
{
	if (text == nullptr)
	{
		return false;
	}

	int len = strlen(text);
	if (len	 <= 0)
	{
		return false;
	}

	char ch = *text;
	if (!(ch >= 0x30 && ch <= 0x39))
	{// 数字开头
		return false;
	}

	for (int i = 0; i < len; i++)
	{
		ch = *(text + i);
		// 数字，字母，下划线
		if (!((ch >= 0x30 && ch <= 0x39) || (ch >= 0x41 && ch <= 0x5A) || (ch >= 0x61 && ch <= 0x7A) || (ch == 0x5f)))
		{
			return false;
		}
	}

	return true;
}

bool Scanner::containKeyWord(const char* text, int& offset, int& size)
{
	offset = 0;
	if (text == nullptr)
	{
		return false;
	}

	Words::const_iterator iterBegin = KeyWord::getInstance()->wordBegin();
	Words::const_iterator iterEnd = KeyWord::getInstance()->wordEnd();

	while (iterBegin != iterEnd)
	{
		char* ptr = strstr((char*)text, (*iterBegin).c_str());
		if (ptr	 != nullptr)
		{
			offset = ptr - text;
			size = (*iterBegin).size();
		}
		iterBegin++;
	}

	return false;
}