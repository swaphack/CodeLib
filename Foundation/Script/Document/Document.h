#pragma once

namespace script
{
	class Scope;

	class Document
	{
	public:
		Document();
		virtual ~Document();
	public:
		// 加载字符串
		bool loadString(const char* text);
		// 获取当前指针
		char* getPtr();
	private:
		// 文本内容指针
		char* m_pContent;
		// 偏移位置
		int m_nOffset;
		// 文本大小
		int m_nSize;
	};
}