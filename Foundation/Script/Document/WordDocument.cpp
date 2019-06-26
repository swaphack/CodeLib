#include "WordDocument.h"
#include "../macros.h"
#include "WordSet.h"

using namespace script;


WordDocument::WordDocument()
{
	m_pWordSet = new WordSet;
}

WordDocument::~WordDocument()
{
	if (m_pWordSet)
	{
		delete m_pWordSet;
	}
}

void WordDocument::setWordSet(WordSet* pWordSet)
{
	if (pWordSet == nullptr)
	{
		return;
	}

	if (m_pWordSet)
	{
		delete m_pWordSet;
	}

	m_pWordSet = pWordSet;
}

WordSet* WordDocument::getWordSet()
{
	return m_pWordSet;
}

bool WordDocument::convertToDocumentStruct()
{
	int offset = 0;
	char spot = 0;
	std::string word;
	while (true)
	{
		if (offset >= getSize())
		{
			m_pWordSet->appendWord(word.c_str());
			word.clear();
			break;
		}

		spot = *(getPtr() + offset);
		if (IS_DECORATOR(spot))
		{
			m_pWordSet->appendWord(word.c_str());
			word.clear();
		}
		else
		{
			word.append(1, spot);
		}
		offset++;
	}

	return true;
}

bool WordDocument::convertToTextStruct()
{

}
