#include "WordSet.h"

using namespace script;

static WordSet* s_KeyWord = nullptr;

WordSet::WordSet()
{

}

WordSet::~WordSet()
{

}

WordSet* WordSet::getInstance()
{
	if (s_KeyWord == nullptr)
	{
		s_KeyWord = new WordSet();
	}

	return s_KeyWord;
}

void WordSet::appendWord(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	int len = strlen(name);
	if (m_mWords.find(len) == m_mWords.end())
	{
		m_mWords[len] = std::vector<std::string>();
	}

	m_mWords[len].push_back(name);
}

bool WordSet::containWord(const char* name)
{
	if (name == nullptr)
	{
		return false;
	}

	int len = strlen(name);
	if (len <= 0)
	{
		return false;
	}

	if (m_mWords.find(len) == m_mWords.end())
	{
		return false;
	}

	for (std::vector<std::string>::const_iterator iter = m_mWords[len].begin();
		iter != m_mWords[len].end();
		iter++)
	{
		if ((*iter).compare(name) == 0)
		{
			return false;
		}
	}

	return true;
}

bool WordSet::pickWord(const char* name, int& offset)
{
	if (name == nullptr)
	{
		return false;
	}

	int len = strlen(name);
	if (len <= 0)
	{
		return false;
	}

	std::string target = name;

	for (int i = len; i > 0 ; i--)
	{
		if (m_mWords.find(i) == m_mWords.end())
		{
			continue;
		}

		std::vector<std::string>* ptr = &m_mWords[i];

		std::vector<std::string>::const_iterator iter = ptr->begin();
		while (iter != ptr->end())
		{
			if (target.compare(0, i, (*iter).c_str()) == 0)
			{
				offset = i;
				return true;
			}
			iter++;
		}
	}

	return false;
}

void WordSet::clear()
{
	m_mWords.clear();
}