#include "Scanner.h"
#include "macros.h"

using namespace script;

Scanner::Scanner()
:m_pContent(nullptr)
, m_nOffset(0)
, m_nSize(0)
{
	m_pTokenTable = new TokenTable();
}

Scanner::~Scanner()
{
	if (m_pTokenTable != nullptr)
	{
		delete m_pTokenTable;
	}
}

bool Scanner::scan(Document* document)
{
	if (document == nullptr || document->getPtr() == nullptr || document->getSize() <= 0)
	{
		return false;
	}

	this->clear();

	m_pContent = document->getPtr();
	m_nSize = document->getSize();

	return this->parse();
}
void Scanner::clear()
{
	m_pContent = nullptr;
	m_nSize = 0; 
	m_nOffset = 0;
	m_pTokenTable->removeAllTokens();
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
	std::string key;
	int offset = 0;
	do 
	{
		if (m_nOffset >= m_nSize)
		{
			appendWord(key);
			break;
		}

		if (IS_DECORATOR(*getPtr()))
		{
			appendWord(key);
			m_nOffset += 1;
			break;
		}

		if (WordSet::getInstance()->pickWord(getPtr(), offset))
		{
			appendWord(key);

			key = std::string(getPtr(), offset);
			appendWord(key);
			m_nOffset += offset;
			break;
		}
		else
		{
			key.append(1, *getPtr());
			m_nOffset += 1;
		}
	} while (true);
}

char* Scanner::getPtr()
{
	return m_pContent + m_nOffset;
}

void Scanner::appendWord(std::string& word)
{
	if (word.size() > 0)
	{
		m_pTokenTable->addToken(word.c_str());
		word.clear();
	}
}