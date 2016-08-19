#pragma once

#include "DBMacros.h"
#include "system.h"
#include <string>

namespace db
{
	class DBHelper
	{
	public:
		// �����ֶ����ͣ���ȡ���ʾ���ַ���
		static void getTypeString(FieldType type, std::string& value);
		// �����ֶ����ͣ���ȡ��ռ�õĿռ��С
		static int getTypeSize(FieldType type, int defaultSize = 0);
		// ��ȡ�ֶ�ֵ
		static void getFieldValue(const char* ptr, FieldType type, long& offset, long length, std::string& value);
	public:
		template<typename T>
		static void getValueFromPtr(T& t, const char* ptr, long& offset);
	};

	template<typename T>
	void DBHelper::getValueFromPtr(T& t, const char* ptr, long& offset )
	{
		t = *(T*)(ptr + offset);
		offset += sizeof(T);
	}

}