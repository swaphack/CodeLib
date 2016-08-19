#pragma once

#include "DBMacros.h"
#include "system.h"
#include <string>

namespace db
{
	class DBHelper
	{
	public:
		// 根据字段类型，获取其表示的字符串
		static void getTypeString(FieldType type, std::string& value);
		// 根据字段类型，获取其占用的空间大小
		static int getTypeSize(FieldType type, int defaultSize = 0);
		// 获取字段值
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