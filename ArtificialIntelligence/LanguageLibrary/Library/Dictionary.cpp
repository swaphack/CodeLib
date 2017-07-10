#include "Dictionary.h"

using namespace ll;

Dictionary::Dictionary()
{

}

Dictionary::~Dictionary()
{

}

void Dictionary::addWord(Word* word)
{
	if (word == nullptr || word->empty())
	{
		return;
	}

	FirstIndex::iterator iter = m_Texts.find(word->value());

	if (iter != m_Texts.end())
	{
		iter->second->release();
	}

	m_Texts[word->value()] = word;

}

void Dictionary::removeWord(Word* word)
{
	if (word == nullptr || word->empty())
	{
		return;
	}

	if (m_Texts.find(word->value()) == m_Texts.end())
	{
		return;
	}

	m_Texts.erase(word->value());
}

void Dictionary::removeAllWords()
{
	m_Texts.clear();
}

const Word* Dictionary::getWord(const Text& text)
{
	FirstIndex::iterator iter = m_Texts.find(text);

	if (iter == m_Texts.end())
	{
		return nullptr;
	}

	return iter->second;
}

