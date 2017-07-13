#pragma once

#include "macros.h"
#include "TokenTable.h"
#include "IStep.h"

namespace script
{
	class Document;
	/**
	*	�ĵ�ɨ����
	*	����ؼ��ֺ������
	*/
	class Scanner
	{
	public:
		Scanner();
		~Scanner();
	public:
		// ����ı�
		bool scan(Document* document);
		// ���ɨ����Ϣ
		void clear();
		// ���ű�
		inline TokenTable* getTokenTable() { return m_pTokenTable; }
	protected:
		// ����
		bool parse();
		// ��ȡ����
		void readWord();
	private:
		// ��ǰ�α�ָ��
		char* getPtr();
		// ׷������
		void appendWord(std::string& word);
	private:
		// �ı�����ָ��
		char* m_pContent;
		// ƫ��λ��
		int m_nOffset;
		// �ı���С
		int m_nSize;
		// ���ű�
		TokenTable* m_pTokenTable;
	};
}