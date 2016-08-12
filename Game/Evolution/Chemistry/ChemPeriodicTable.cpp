#include "ChemPeriodicTable.h"

using namespace nature;

ChemPeriodicTable* ChemPeriodicTable::s_pPeriodicTable = nullptr;


ChemPeriodicTable::ChemPeriodicTable()
{

}

ChemPeriodicTable::~ChemPeriodicTable()
{

}

ChemPeriodicTable* ChemPeriodicTable::getInstance()
{
	if (s_pPeriodicTable == nullptr)
	{
		s_pPeriodicTable = new ChemPeriodicTable();
	}

	return s_pPeriodicTable;
}

void ChemPeriodicTable::addElement(const ChemElementInfo& info)
{
	_elementIDInfos[info.ID] = info;
	_elementSymbolInfos[info.Symbol] = info;
}

const ChemElementInfo* ChemPeriodicTable::getElementByID(int elementID)
{
	std::map<int, ChemElementInfo>::const_iterator iter = _elementIDInfos.find(elementID);
	if (iter == _elementIDInfos.end())
	{
		return &iter->second;
	}

	return nullptr;
}

const ChemElementInfo* ChemPeriodicTable::getElementBySymbol(const char* symbol)
{
	if (symbol == nullptr)
	{
		return nullptr;
	}
	std::map<std::string, ChemElementInfo>::const_iterator iter = _elementSymbolInfos.find(symbol);
	if (iter == _elementSymbolInfos.end())
	{
		return &iter->second;
	}

	return nullptr;
}
