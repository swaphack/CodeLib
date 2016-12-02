#include "Scanner.h"
#include "SingalSet.h"
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

bool Scanner::scan(const char* ptr, int size)
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
		if (strcmp(getPtr(), "\0") == 0 || m_nOffset >= m_nSize)
		{
			break;
		}

		readWord();

	} while (true);

	return true;
}

void Scanner::readWord()
{
	int size = 0;
	std::string word = "";
	std::string key = "";
	do 
	{
		char ch = *getPtr();
		if (ch == ' ' || ch == '\r' || ch == '\n')
		{// 排除空格，回车，换行
			m_nOffset+=1;
			break;
		}

		// 变量
		if (isVariableFormat(getPtr(), size))
		{
			key = std::string(getPtr(), size);
			m_nOffset += size;
			break;
		}

		// 字符串
		if (isStringFormat(getPtr(), size))
		{
			key = std::string(getPtr(), size);
			m_nOffset += size;
			break;
		}

		// 数值
		if (isNumberFormat(getPtr(), size))
		{
			key = std::string(getPtr(), size);
			m_nOffset += size;
			break;
		}

		// 关键字
		if (isSingalFormat(getPtr(), size))
		{
			key = std::string(getPtr(), size);
			m_nOffset += size;
			break;
		}

		word.append(1, ch);

		m_nOffset++;
	} while (true);

	appendWord(word);
	appendWord(key);
}

char* Scanner::getPtr()
{
	return m_pContent + m_nOffset;
}

bool Scanner::isVariableFormat(const char* text, int& size)
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
	if (ch >= 0x30 && ch <= 0x39)
	{// 数字开头
		return false;
	}

	int i;
	for (i = 0; i < len; i++)
	{
		ch = *(text + i);
		// 数字，字母，下划线
		if (!((ch >= 0x30 && ch <= 0x39) || (ch >= 0x41 && ch <= 0x5A) || (ch >= 0x61 && ch <= 0x7A) || (ch == 0x5f)))
		{
			size = i;
			return i > 0;
		}
	}

	if (i == len)
	{
		size = i;
		return true;
	}

	return false;
}

bool Scanner::isNumberFormat(const char* text, int& size)
{
	if (text == nullptr)
	{
		return false;
	}

	int len = strlen(text);
	if (len <= 0)
	{
		return false;
	}

	char ch;
	int i;
	for (i = 0; i < len; i++)
	{
		ch = *(text + i);
		// 非数字和.
		if (!((ch >= 0x30 && ch <= 0x39) || (ch == 0x2E)))
		{
			size = i;
			return i > 0;
		}
	}

	if (i == len)
	{
		size = i;
		return true;
	}

	return false;
}

bool Scanner::isStringFormat(const char* text, int& size)
{
	if (text == nullptr)
	{
		return false;
	}


	int len = strlen(text);
	if (len <= 0)
	{
		return false;
	}

	if (*text != 0x22)
	{
		return false;
	}
	char ch;
	int i;
	for (i = 1; i < len; i++)
	{
		ch = *(text + i);
		if (ch == 0x22)
		{
			size = i + 1;
			return true;
		}
	}

	if (i == len)
	{
		size = i;
		return true;
	}

	return false;
}

bool Scanner::isSingalFormat(const char* text, int& size)
{
	if (text == nullptr)
	{
		return false;
	}
	size = SingalSet::getInstance()->containOperator(text);

	return size != -1;
}

void Scanner::appendWord(std::string& word)
{
	if (word.size() > 0)
	{
		m_vWords.push_back(word);
		word.clear();
	}
}
