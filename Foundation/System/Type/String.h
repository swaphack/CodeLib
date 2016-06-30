#pragma once

#include "../Base/import.h"

#include <string>
#include <vector>

namespace sys
{
	// 字符串，以'\0'结尾
	class String
	{
	public:
		String();
		String(const String& value);
		String(const char* value);
		String(const char* value, int count);
		virtual ~String();
	public:
		// 赋值
		virtual String& operator=(const String& value);
		virtual String& operator=(const std::string& value);
		virtual String& operator=(const char* value);
		// 拼接
		virtual String& concat(const char* value);
		virtual String& concat(const char* value1, const char* value2);
		virtual String& concat(const char* value1, const char* value2, const char* value3);

		// 是否包含
		bool contains(const char* value);

		// 比较两字符串是否相同
		bool compare(const char* value);
		bool compare(int offset, const char* value);
		bool compare(int offset, const char* value, int count);
		// 以指定字符串结尾
		bool endWith(const char* value);
		// 以指定字符串开头
		bool startWith(const char* value);
		// 获取索引的字符
		virtual char operator[](uint index);
		// 移除从指定位置开始的一段字符串
		String& remove(int offset, int count);
		// 插入字符串
		String& insert(int offset, const char* value);
		// 移除从指定位置开始的一段字符串
		String subString(int offset, int count);

		// 去掉空格
		String& trim();
		// 去掉左边空格
		String& trimLeft();
		// 去掉右边空格
		String& trimRight();

		// 格式化
		String& make(const char* format, ...);
		// 分割
		void split(char spot, std::vector<String>& dest);
		// 分割
		void split(const char* spot, std::vector<String>& dest);
		// 是否数据为空
		bool empty();

		// 获取字符串数据
		const char* getString() const;
		// 获取字符串长度
		int getSize() const;
	private:
		// 数据
		char* _value;
		// 长度
		int _size;
	};
}