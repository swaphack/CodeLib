#include "DataRecord.h"

using namespace sys;

DataRecord::DataRecord()
{

}

DataRecord::~DataRecord()
{

}


void DataRecord::setValue(const char* key, const char* value)
{
	if (key == nullptr || value == nullptr)
	{
		return;
	}

	_values[key] = value;
}

const char* DataRecord::getValue(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, std::string>::const_iterator iter = _values.find(key);
	if (iter != _values.end())
	{
		return iter->second.c_str();
	}

	return nullptr;
}
