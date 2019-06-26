#include "PeriodicTable.h"

using namespace chem;

PeriodicTable* PeriodicTable::s_pPeriodicTable = nullptr;


PeriodicTable::PeriodicTable()
{

}

PeriodicTable::~PeriodicTable()
{

}

PeriodicTable* PeriodicTable::getInstance()
{
	if (s_pPeriodicTable == nullptr)
	{
		s_pPeriodicTable = new PeriodicTable();
	}

	return s_pPeriodicTable;
}

void PeriodicTable::addElement(const Element& info)
{
	_elementInfos[info.ID] = info;
	_elementSymbols[info.Symbol] = info.ID;
}

const Element* PeriodicTable::getElementByID(int elementID)
{
	std::map<int, Element>::const_iterator iter = _elementInfos.find(elementID);
	if (iter == _elementInfos.end())
	{
		return &iter->second;
	}

	return nullptr;
}

const Element* PeriodicTable::getElementBySymbol(const char* symbol)
{
	if (symbol == nullptr)
	{
		return nullptr;
	}
	std::map<std::string, int>::const_iterator iter = _elementSymbols.find(symbol);
	if (iter != _elementSymbols.end())
	{
		std::map<int, Element>::const_iterator iter2 = _elementInfos.find(iter->second);
		if (iter2 != _elementInfos.end())
		{
			return &iter2->second;
		}
	}

	return nullptr;
}
