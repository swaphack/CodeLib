#include "WordFilter.h"

using namespace script;

WordFilter::WordFilter()
{
	
}

WordFilter::~WordFilter()
{
	removeAllFilters();
}

void WordFilter::addFilter(ITextFilter* filter)
{
	if (filter == nullptr)
	{
		return;
	}

	m_vWordFilters.push_back(filter);
}

void WordFilter::removeFilter(ITextFilter* filter)
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

void WordFilter::removeAllFilters()
{
	for (int i = 0; i < m_vWordFilters.size(); i++)
	{
		delete m_vWordFilters[i];
	}

	m_vWordFilters.clear();
}

bool WordFilter::match(const char* text, int& size)
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