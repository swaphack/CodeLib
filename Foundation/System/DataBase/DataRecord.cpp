#include "DataRecord.h"

using namespace sys;

DataRecord::DataRecord()
{

}

DataRecord::~DataRecord()
{

}


void DataRecord::setValue(const std::string& key, const std::string& value)
{
	if (key.empty() || value.empty())
	{
		return;
	}

	_values[key] = value;
}

std::string DataRecord::getValue(const std::string& key) const
{
	if (key.empty())
	{
		return "";
	}

	auto iter = _values.find(key);
	if (iter != _values.end())
	{
		return iter->second;
	}

	return "";
}
