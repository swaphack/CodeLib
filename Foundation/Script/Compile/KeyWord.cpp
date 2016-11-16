#include "KeyWord.h"

using namespace script;

static KeyWord* s_KeyWord = nullptr;

KeyWord::KeyWord()
{

}

KeyWord::~KeyWord()
{

}

KeyWord* KeyWord::getInstance()
{
	if (s_KeyWord == nullptr)
	{
		s_KeyWord = new KeyWord();
		s_KeyWord->init();
	}

	return s_KeyWord;
}

void KeyWord::append(const char* keyword)
{
	if (keyword == nullptr)
	{
		return;
	}

	m_sKeyWords.insert(keyword);
}

int KeyWord::contain(const char* keyword)
{
	if (keyword == nullptr)
	{
		return -1;
	}

	return m_sKeyWords.find(keyword) != m_sKeyWords.end();
}

void KeyWord::clear()
{
	m_sKeyWords.clear();
}

void KeyWord::init()
{
	append("+");
	append("-");
	append("*");
	append("/");
	append("=");
	append(".");
	append("{");
	append("}");
}
