#pragma once

#include "macros.h"
#include "TokenTable.h"

namespace script
{
	/**
	*	文档扫描器
	*	定义关键字和运算符
	*/
	class Scanner
	{
	public:
		Scanner();
		~Scanner();
	public:
		// 浏览文本
		bool scan(const char* ptr, int size);
		// 清空扫描信息
		void clear();
		// 符号表
		inline TokenTable* getTokenTable() { return m_pTokenTable; }
	protected:
		// 解析
		bool parse();
		// 读取文字
		void readWord();
	private:
		// 当前游标指针
		char* getPtr();
		// 是否符合变量格式
		bool isVariableFormat(const char* text, int& size);
		// 是否符合数值格式
		bool isNumberFormat(const char* text, int& size);
		// 是否符合字符串格式
		bool isStringFormat(const char* text, int& size);
		// 字符串是否以符号表中元素开头
		bool isSingalFormat(const char* text, int& size);
		// 追加文字
		void appendWord(std::string& word);
	private:
		// 文本内容指针
		char* m_pContent;
		// 偏移位置
		int m_nOffset;
		// 文本大小
		int m_nSize;
		// 符号表
		TokenTable* m_pTokenTable;
	};
}