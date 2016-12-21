#pragma once

#include <vector>
#include <map>
#include <string>

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
		void addSymbolDelegate(SymbolDelegate* opeartor);
		// �Ƴ�����
		void removeSymbolDelegate(SymbolDelegate* opeartor);
		// �Ƴ����н���
		void removeAllSymbolDelegates();
		// ���ҽ���
		SymbolDelegate* getSymbolDelegate(const char* name);
		// ƥ�����
		ASTNode* match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
		// ���������ļ�
		bool load(const char* filepath);
	private:
		typedef std::map<std::string, SymbolDelegate*> SymbolDelegates;
		// ���Ŵ���ί��
		SymbolDelegates m_mSymbolDelegates;
	};
}