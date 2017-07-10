#pragma once

namespace ll
{
	class Dictionary;
	// 库
	class Library
	{
	public:
		Library();
		~Library();
	public:
		// 加载数据
		virtual void load(const char* content, int size) = 0;
		// 获取字段
		Dictionary* getDictionary();
	private:
		Dictionary* _dictionary;
	};
}