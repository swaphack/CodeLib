#pragma once

#include "macros.h"
#include "TokenTable.h"

namespace script
{
	class Document;
	/**
	*	文档扫描器
	*	定义关键字和运算符
	*/
	class Scanner
	{
	public:
		Scanner();
		virtual ~Scanner();
	public:
		void setWordSet(WordSet* wordSet);
		// 浏览文本
		bool scan(Document* document);
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
		// 词组表
		WordSet* m_pWordSet;
	};
}