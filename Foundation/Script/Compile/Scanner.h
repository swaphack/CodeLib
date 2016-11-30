#pragma once

#include <string>
#include <vector>

namespace script
{
	typedef std::vector<std::string> Token;

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
		bool read(const char* ptr, int size);
		// 清空扫描信息
		void clear();
		// 单词起始位置
		inline Token::const_iterator tokenBegin()
		{
			return m_vWords.begin();
		}
		// 单词结束位置
		inline Token::const_iterator tokenEnd()
		{
			return m_vWords.end();
		}
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
		// 单词
		Token m_vWords;
	};
}