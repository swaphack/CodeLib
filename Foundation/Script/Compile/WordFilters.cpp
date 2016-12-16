#include "WordFilters.h"

using namespace script;

WordFilters::WordFilters()
{

}

WordFilters::~WordFilters()
{
	removeAllFilters();
}

WordFilters* WordFilters::getInstance()
{
	static WordFilters* s_WorldFilters = nullptr;
	if (s_WorldFilters == nullptr)
	{
		s_WorldFilters = new WordFilters();
	}

	return s_WorldFilters;
}

void WordFilters::addFilter(ITextFilter* filter)
{
	if (filter == nullptr)
	{
		return;
	}

	m_vWordFilters.push_back(filter);
}

void WordFilters::removeFilter(ITextFilter* filter)
{
	if (filter == nullptr)
	{
		return;
	}

	for (int i = 0; i < m_vWordFilters.size(); i++)
	{
		if (m_vWordFilters[i] == filter)
		{
			delete filter;
			m_vWordFilters.erase(m_vWordFilters.begin() + i);
			return;
		}
	}
}

void WordFilters::removeAllFilters()
{
	for (int i = 0; i < m_vWordFilters.size(); i++)
	{
		delete m_vWordFilters[i];
	}

	m_vWordFilters.clear();
}

bool WordFilters::match(const char* text, int& size)
{
	for (int i = 0; i < m_vWordFilters.size(); i++)
	{
		if (m_vWordFilters[i]->match(text, size))
		{
			return true;
		}
	}

	return false;
}