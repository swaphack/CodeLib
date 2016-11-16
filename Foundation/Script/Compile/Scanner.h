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

		inline Token::const_iterator tokenBegin()
		{
			return m_vWords.begin();
		}
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
		// 是否变量格式
		bool isVariableFormat(const char* text);
		// 开始是否包含关键字
		bool containKeyWord(const char* text, int& offset, int& size);
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