#pragma once

#include "Base/import.h"

namespace sys
{
	// 字符串，以'\0'结尾
	class String
	{
	public:
		String();
		String(const String& value);
		String(const std::string& value);
		String(const char* value);
		String(const char* value, int32_t count);
		~String();
	public:
		// 赋值
		String& operator=(const String& value);
		String& operator=(const std::string& value);
		String& operator=(const char* value);

		String operator+(const String& value);
		String operator+(const std::string& value);
		String operator+(const char* value);

		// 获取索引的字符
		char operator[](int32_t index);
		char& at(int32_t index);

		// 尾部追加字符
		void append(int32_t count, char value);
		// 尾部追加字符串
		void append(int32_t count, char* value);
		// 替换指定的字符
		String replace(char spot, char* value);
		// 替换指定的字符串
		String replace(char* spot, char* value);

		// 拼接
		String& concat(const char* value);
		String& concat(const char* value1, const char* value2);
		String& concat(const char* value1, const char* value2, const char* value3);

		// 是否包含
		bool contains(const char* value);

		// 比较两字符串是否相同
		bool compare(const char* value);
		bool compare(int32_t offset, const char* value);
		bool compare(int32_t offset, const char* value, int32_t count);
		// 以指定字符串结尾
		bool endWith(const char* value);
		// 以指定字符串开头
		bool startWith(const char* value);
		// 移除从指定位置开始的一段字符串
		String& remove(int32_t offset, int32_t count);
		// 插入字符串
		String& insert(int32_t offset, const char* value);
		// 移除从指定位置开始的一段字符串
		String subString(int32_t offset, int32_t count);

		// 开始位置查找匹配字符的索引位置
		int32_t findFirstOf(char value);
		// 开始位置查找匹配字符串的索引位置
		int32_t findFirstOf(const char* value);
		// 结束位置查找匹配字符的索引位置
		int32_t findLastOf(char value);
		// 结束位置查找匹配字符的索引位置
		int32_t findLastOf(const char* value);
		// 是否是句子
		bool isLine();

		// 去掉所有空格
		String trim();
		// 去掉左边空格
		String trimLeft();
		// 去掉右边空格
		String trimRight();

		// 转小写
		String toLower();
		// 转大写
		String toUpper();

		// 格式化
		String& make(const char* format, ...);
		// 分割
		void split(char spot, std::vector<String>& dest);
		// 分割
		void split(const char* spot, std::vector<String>& dest);
		// 分割
		void split(char spot, std::vector<std::string>& dest);
		// 分割
		void split(const char* spot, std::vector<std::string>& dest);
		// 是否数据为空
		bool empty();
		// 反转
		String reverse();

		// 获取字符串数据
		const char* getString() const;
		// 获取字符串长度
		int32_t getSize() const;
	private:
		// 数据
		char* _value;
		// 长度
		int32_t _size;
	};
}