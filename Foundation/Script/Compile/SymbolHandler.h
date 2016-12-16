#pragma once

#include <vector>

#include "SymbolDelegate.h"

namespace script
{
	// ����������
	class SymbolHandler
	{
	private:
		SymbolHandler();
		~SymbolHandler();
	public:
		static SymbolHandler* getInstance();
		// ��ӽ���
		void addParser(SymbolDelegate* opeartor);
		// �Ƴ�����
		void removeParser(SymbolDelegate* opeartor);
		// �Ƴ����н���
		void removeAllParsers();
		// ƥ�����
		bool match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
	private:
		std::vector<SymbolDelegate*> m_mOperatorParsers;
	};
}