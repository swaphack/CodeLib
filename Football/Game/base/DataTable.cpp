#include "DataTable.h"

using namespace game;

DataRecord::DataRecord()
{

}

DataRecord::~DataRecord()
{

}

void DataRecord::onChangedHandler(float newValue)
{
	auto pFunc = getValueChangedHand();
	if (pFunc)
	{
		pFunc(getType(), newValue, getValue());
	}
}

void DataRecord::addValue(float value)
{
	float totalValue = getValue() + value;
	onChangedHandler(totalValue);
	setValue(totalValue);
}

void DataTable::destoryValue(DataRecord* value)
{
	if (value)
	{
		delete value;
	}
}

