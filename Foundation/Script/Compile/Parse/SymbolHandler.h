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
	public:
		SymbolHandler();
		virtual ~SymbolHandler();
	public:
		// ��ӽ���
		void addSymbolDelegate(SymbolDelegate* opeartor);
		// �Ƴ�����
		void removeSymbolDelegate(SymbolDelegate* opeartor);
		// �Ƴ����н���
		void removeAllSymbolDelegates();
		// ���ҽ���
		SymbolDelegate* getSymbolDelegate(const char* name);
		SymbolDelegate* getSymbolDelegate(const std::string& name);
		// ���������ļ�
		bool load(const std::string& filepath);
	private:
		typedef std::map<std::string, SymbolDelegate*> SymbolDelegates;
		// ���Ŵ���ί��
		SymbolDelegates m_mSymbolDelegates;
		// ������ʼ���Ŵ���ί��
		SymbolDelegates m_mEmbedBeginSymbolDelegates;
		// �����������Ŵ���ί��
		SymbolDelegates m_mEmbedEndSymbolDelegates;
	};
}