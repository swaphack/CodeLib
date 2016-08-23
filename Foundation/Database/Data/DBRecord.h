#pragma once

#include "../Struct/import.h"
#include "system.h"
#include <map>
#include <string>

using namespace sys;

namespace db
{
	// ���¼
	class DBRecord
	{
	public:
		DBRecord();
		virtual ~DBRecord();
	public:
		// ���ؼ�¼
		void loadText(const DBTable* table, const char* ptr, long& length);
		// ���ɼ�¼
		void makeText(const DBTable* table, std::string& data);

		// ��ȡ�ֶε�ֵ
		void getFieldValue(const char* key, std::string& value);
		void getFieldValue(const char* key, char& value);
		void getFieldValue(const char* key, uchar& value);
		void getFieldValue(const char* key, short& value);
		void getFieldValue(const char* key, ushort& value);
		void getFieldValue(const char* key, int& value);
		void getFieldValue(const char* key, uint& value);
		void getFieldValue(const char* key, long& value);
		void getFieldValue(const char* key, ulong& value);
		void getFieldValue(const char* key, float& value);
		void getFieldValue(const char* key, double& value);

		// �����ֶε�ֵ
		void setFieldValue(const char* key, const char* value);
		void setFieldValue(const char* key, char value);
		void setFieldValue(const char* key, uchar value);
		void setFieldValue(const char* key, short value);
		void setFieldValue(const char* key, ushort value);
		void setFieldValue(const char* key, int value);
		void setFieldValue(const char* key, uint value);
		void setFieldValue(const char* key, long value);
		void setFieldValue(const char* key, ulong value);
		void setFieldValue(const char* key, float value);
		void setFieldValue(const char* key, double value);

		// �Ƴ�һ���ֶ�
		void removeField(const char* key);
		// �������
		void clear();
	protected:
		StreamBase* getField(const char* key);
	private:
		// ʹ��ģ���ȡ�ֶε�ֵ
		template<typename T>
		void getFieldValue(const char* key, T& t);
		// ʹ��ģ�������ֶε�ֵ
		template<typename T>
		void setFieldValue(const char* key, T t);
		// ʹ��ģ�����һ�����ֶβ�����ֵ
		template<typename T>
		void addField(const char* key, T t);
	private:
		// �ֶ�ֵ
		std::map<std::string, StreamBase*> _fieldValues;
	};	

	template<typename T>
	void DBRecord::getFieldValue( const char* key, T& t )
	{
		const StreamBase* value = this->getField(key);
		if (value == nullptr)
		{
			return;
		}

		t = *(T*)value->getData();
	}

	template<typename T>
	void DBRecord::setFieldValue( const char* key, T t )
	{
		StreamBase* ptr = this->getField(key);
		if (ptr == nullptr)
		{
			addField(key, t);
		}
		else
		{
			ptr->setData((char*)&t, sizeof(t));
		}
	}

	template<typename T>
	void DBRecord::addField( const char* key, T t )
	{
		ASSERT(_fieldValues[key] == nullptr);

		StreamBase* value = new StreamBase();
		value->setData((char*)&t, sizeof(t));

		_fieldValues[key] = value;
	}
}