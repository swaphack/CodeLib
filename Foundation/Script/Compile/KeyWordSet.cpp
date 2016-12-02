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

void KeyWordSet::appendKeyWord(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	m_vKeyWords.push_back(name);
}

bool KeyWordSet::containKeyWord(const char* name)
{
	if (name == nullptr)
	{
		return -1;
	}

	for (Words::const_iterator iter = m_vKeyWords.begin(); iter != m_vKeyWords.end(); iter++)
	{
		if ((*iter).compare(name) == 0)
		{
			return true;
		}
	}

	return false;
}

void KeyWordSet::clear()
{
	m_vKeyWords.clear();
}

void KeyWordSet::init()
{
	// 类
	appendKeyWord("class");
	// 函数
	appendKeyWord("function");
	// 变量
	appendKeyWord("var");
	// 返回值
	appendKeyWord("return");

	// +
	appendKeyWord("__add");
	// -
	appendKeyWord("__minus");
	// *
	appendKeyWord("__multiply");
	// /
	appendKeyWord("__divide");
	// =
	appendKeyWord("__equal");
}
