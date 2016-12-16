#pragma once

#include <string>

#include "macros.h"

namespace script
{
	// ���Ž���
	class SymbolDelegate
	{
	public:
		SymbolDelegate();
		virtual ~SymbolDelegate();
	public:
		// ��ȡ����
		const char* getSymbol();
		// ���÷���
		void setSymbol(const char* symbol);
		// ��ȡ���ʽ
		const char* getExpression();
		// ���ñ��ʽ
		void setExpression(const char* text);
		// ���ȼ�
		int getPriorityLevel();
		// ���ȼ�
		void setPriorityLevel(int level);
		/**
		*	ƥ�����
		*	@param expression ������ʽ
		*	@param offset �����ɹ����ƫ��ֵ
		*	@reurn bool �Ƿ�����ɹ�
		*/
		virtual bool match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset) = 0;
	protected:
		// ����
		std::string m_strSymbol;
		// ���ʽ
		std::string m_strExpression;
		// ���ȼ�
		int m_nPriorityLevel;
	};
}