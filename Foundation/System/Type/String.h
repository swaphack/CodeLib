#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace sys
{
	class MemoryData;

	// 字符串，以'\0'结尾
	class String
	{
	public:
		String();
		String(const String& value);
		String(const std::string& value);
		String(const char* value, size_t count);
		String(const char* value, int32_t count);
		~String();
	public:
		// 赋值
		String& operator=(const String& value);
		String& operator=(const std::string& value);

		String operator+(const String& value);
		String operator+(const std::string& value);

		// 获取索引的字符
		char operator[](size_t index);
		char& at(size_t index);

		// 尾部追加字符
		void append(size_t count, char value);
		// 尾部追加字符串
		void append(size_t count, const std::string& value);
		// 替换指定的字符
		String replace(char spot, const std::string& value);
		// 替换指定的字符串
		String replace(const std::string& spot, const std::string& value);

		// 拼接
		String& concat(const std::string& value);
		String& concat(const std::string& value1, const std::string& value2);
		String& concat(const std::string& value1, const std::string& value2, const std::string& value3);

		// 是否包含
		bool contains(const std::string& value);

		// 比较两字符串是否相同
		bool compare(const std::string& value);
		bool compare(size_t offset, const std::string& value);
		bool compare(size_t offset, const std::string& value, size_t count);
		// 以指定字符串结尾
		bool endWith(const std::string& value);
		// 以指定字符串开头
		bool startWith(const std::string& value);
		// 移除从指定位置开始的一段字符串
		String& remove(size_t offset, size_t count);
		// 插入字符串
		String& insert(size_t offset, const std::string& value);
		// 移除从指定位置开始的一段字符串
		String subString(size_t offset, size_t count);

		// 开始位置查找匹配字符的索引位置
		int32_t findFirstOf(char value);
		// 开始位置查找匹配字符串的索引位置
		int32_t findFirstOf(const std::string& value);
		// 结束位置查找匹配字符的索引位置
		int32_t findLastOf(char value);
		// 结束位置查找匹配字符的索引位置
		int32_t findLastOf(const std::string& value);
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
		void split(const std::string& spot, std::vector<String>& dest);
		// 分割
		void split(char spot, std::vector<std::string>& dest);
		// 分割
		void split(const std::string& spot, std::vector<std::string>& dest);
		// 是否数据为空
		bool empty();
		// 反转
		String reverse();

		// 获取字符串数据
		const char* getString() const;

		char* getString();
		// 获取字符串长度
		size_t getSize() const;
	protected:
		void initString(size_t size, const char* value);
		void allocString(size_t size, MemoryData& data);
	private:
		MemoryData* _data = nullptr;
	};
}
