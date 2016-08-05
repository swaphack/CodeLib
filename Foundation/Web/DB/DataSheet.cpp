#include "DataSheet.h"

#include <map>

namespace web
{
	// 数据记录
	class DataRecord : public IDataRecord
	{
	public:
		DataRecord();
		virtual ~DataRecord();

		virtual const char* getValue(const char* key)
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

		virtual void setValue(const char* key, const char* value)
		{
			if (key == nullptr || value == nullptr)
			{
				return;
			}

			_values[key] = value;
		}
	private:
		// 键值对数据
		std::map<std::string, std::string> _values;
	};
}

using namespace web;

DataSheet::DataSheet()
{
	this->reset();
}

DataSheet::~DataSheet()
{
	this->clear();
}

IDataRecord* DataSheet::create()
{
	IDataRecord* record = new DataRecord();
	if (record)
	{
		_records.push_back(record);
	}

	return record;
}

int DataSheet::count()
{
	return _records.size();
}

void DataSheet::reset()
{
	_cursor = 0;
}

IDataRecord* DataSheet::next()
{
	if (_cursor >= this->count())
	{
		return nullptr;
	}

	IDataRecord* record = _records[_cursor];
	_cursor++;

	return record;
}

void DataSheet::clear()
{
	std::vector<IDataRecord*>::iterator iter = _records.begin();

	while (iter != _records.end())
	{
		delete (*iter);
		iter++;
	}

	_records.clear();
}