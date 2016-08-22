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
	_elementIDInfos[info.ID] = info;
	_elementSymbolInfos[info.Symbol] = info;
}

const Element* PeriodicTable::getElementByID(int elementID)
{
	std::map<int, Element>::const_iterator iter = _elementIDInfos.find(elementID);
	if (iter == _elementIDInfos.end())
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
	std::map<std::string, Element>::const_iterator iter = _elementSymbolInfos.find(symbol);
	if (iter == _elementSymbolInfos.end())
	{
		return &iter->second;
	}

	return nullptr;
}
