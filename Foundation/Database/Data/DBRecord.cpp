#include "DBRecord.h"

using namespace db;

using namespace sys;

DBRecord::DBRecord()
{

}

DBRecord::~DBRecord()
{
	this->clear();
}

void DBRecord::loadText(const DBTable* table, const char* ptr, long& length)
{
	if (table == nullptr || ptr == nullptr)
	{
		return;
	}

	this->clear();

	const std::vector<DBField*>& fields = table->getMemoryFields();
	std::vector<DBField*>::const_iterator iter = fields.begin();

	int size = 0;
	
	while (iter != fields.end())
	{
		size = *(int*)(ptr + length);
		std::string text = std::string((ptr + sizeof(int) + length), size);

		StreamBase* stream = new StreamBase();
		stream->setData((char*)text.c_str(), text.size());
		_fieldValues[(*iter)->getName()] = stream;
		length += sizeof(int)+size;
		iter++;
	}
}

void DBRecord::makeText(const DBTable* table, std::string& data)
{
	if (table == nullptr)
	{
		return;
	}

	sys::StreamWriter writer;
	std::map<std::string, StreamBase*>::iterator valueIter;
	const std::vector<DBField*>& fields = table->getMemoryFields();

	std::vector<DBField*>::const_iterator iter = fields.begin();
	while (iter != fields.end())
	{
		valueIter = _fieldValues.find((*iter)->getName());
		if (valueIter != _fieldValues.end())
		{
			int len = valueIter->second->getLength();
			writer.writeInt(len);
			writer.writeString((char*)valueIter->second->getData(), len);
		}
		else
		{
			int len = 1;
			std::string value = std::string(len, 0);
			writer.writeInt(value.size());
			writer.writeString((char*)value.c_str(), len);
		}
		iter++;
	}

	data = std::string(writer.getData(), writer.getLength());
}

// 获取字段的值
bool DBRecord::getFieldValue(const char* key, std::string& value)
{
	const StreamBase* ptr = this->getField(key);
	if (ptr == nullptr)
	{
		return false;
	}

	value = std::string(ptr->getData(), ptr->getLength());

	return true;
}
bool DBRecord::getFieldValue(const char* key, char& value)
{
	return this->getFieldValue<char>(key, value);
}
bool DBRecord::getFieldValue(const char* key, uchar& value)
{
	return this->getFieldValue<uchar>(key, value);
}
bool DBRecord::getFieldValue(const char* key, short& value)
{
	return this->getFieldValue<short>(key, value);
}
bool DBRecord::getFieldValue(const char* key, ushort& value)
{
	return this->getFieldValue<ushort>(key, value);
}
bool DBRecord::getFieldValue(const char* key, int& value)
{
	return this->getFieldValue<int>(key, value);
}
bool DBRecord::getFieldValue(const char* key, uint& value)
{
	return this->getFieldValue<uint>(key, value);
}
bool DBRecord::getFieldValue(const char* key, long& value)
{
	return this->getFieldValue<long>(key, value);
}
bool DBRecord::getFieldValue(const char* key, ulong& value)
{
	return this->getFieldValue<ulong>(key, value);
}
bool DBRecord::getFieldValue(const char* key, float& value)
{
	return this->getFieldValue<float>(key, value);
}
bool DBRecord::getFieldValue(const char* key, double& value)
{
	return this->getFieldValue<double>(key, value);
}

// 设置字段的值
void DBRecord::setFieldValue(const char* key, const char* value)
{
	StreamBase* ptr = this->getField(key);
	if (ptr == nullptr)
	{
		return;
	}
	ptr->setData((char*)value, strlen(value));
}
void DBRecord::setFieldValue(const char* key, char value)
{
	this->setFieldValue<char>(key, value);
}
void DBRecord::setFieldValue(const char* key, uchar value)
{
	this->setFieldValue<uchar>(key, value);
}
void DBRecord::setFieldValue(const char* key, short value)
{
	this->setFieldValue<short>(key, value);
}
void DBRecord::setFieldValue(const char* key, ushort value)
{
	this->setFieldValue<ushort>(key, value);
}
void DBRecord::setFieldValue(const char* key, int value)
{
	this->setFieldValue<int>(key, value);
}
void DBRecord::setFieldValue(const char* key, uint value)
{
	this->setFieldValue<uint>(key, value);
}
void DBRecord::setFieldValue(const char* key, long value)
{
	this->setFieldValue<long>(key, value);
}
void DBRecord::setFieldValue(const char* key, ulong value)
{
	this->setFieldValue<ulong>(key, value);
}
void DBRecord::setFieldValue(const char* key, float value)
{
	this->setFieldValue<float>(key, value);
}
void DBRecord::setFieldValue(const char* key, double value)
{
	this->setFieldValue<double>(key, value);
}

void DBRecord::removeField(const char* key)
{
	if (key == nullptr)
	{
		return;
	}

	std::map<std::string, StreamBase*>::iterator iter = _fieldValues.find(key);
	if (iter != _fieldValues.end())
	{
		delete iter->second;
		_fieldValues.erase(iter);
	}
}

void DBRecord::clear()
{
	std::map<std::string, StreamBase*>::iterator iter = _fieldValues.begin();
	if (iter != _fieldValues.end())
	{
		delete iter->second;
		iter++;
	}
}

StreamBase* DBRecord::getField(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, StreamBase*>::iterator iter = _fieldValues.find(key);
	if (iter != _fieldValues.end())
	{
		return iter->second;
	}

	return nullptr;
}