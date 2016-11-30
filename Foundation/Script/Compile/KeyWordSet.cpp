#include "KeyWordSet.h"

using namespace script;

static KeyWordSet* s_KeyWord = nullptr;

KeyWordSet::KeyWordSet()
{

}

KeyWordSet::~KeyWordSet()
{

}

KeyWordSet* KeyWordSet::getInstance()
{
	if (s_KeyWord == nullptr)
	{
		s_KeyWord = new KeyWordSet();
		s_KeyWord->init();
	}

	return s_KeyWord;
}

void KeyWordSet::append(const char* keyword)
{
	if (keyword == nullptr)
	{
		return;
	}

	m_vKeyWords.push_back(keyword);
}

int KeyWordSet::contain(const char* keyword)
{
	if (keyword == nullptr)
	{
		return -1;
	}

	for (Words::const_iterator iter = m_vKeyWords.begin(); iter != m_vKeyWords.end(); iter++)
	{
		char* ptr = (char*)strstr(keyword, (*iter).c_str());
		if (ptr != nullptr && (ptr - keyword) == 0)
		{
			return (*iter).size();
		}
	}

	return -1;
}

void KeyWordSet::clear()
{
	m_vKeyWords.clear();
}

void KeyWordSet::init()
{
	append("import");
}
