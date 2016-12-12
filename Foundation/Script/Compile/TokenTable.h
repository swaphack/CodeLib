#pragma once

#include "macros.h"

namespace script
{
	// 符号表
	class TokenTable
	{
	public:
		TokenTable();
		virtual ~TokenTable();
	public:
		// 添加一个符号
		void addToken(const char* token);
		// 移除所有符号
		void removeAllTokens();

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
		// 单词
		Token m_vWords;
	};

	// 变量记录表
	class VariableTable
	{
	public:
	protected:
	private:
	};

	// 字符串记录表
	class StringTable
	{
	public:
	protected:
	private:
	};
	
	// 数值记录表
	class NumberTable
	{
	public:
	protected:
	private:
	};
}