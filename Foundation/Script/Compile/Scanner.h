#pragma once

#include "macros.h"
#include "TokenTable.h"

namespace script
{
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
		bool scan(const char* ptr, int size);
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
		// �Ƿ���ϱ�����ʽ
		bool isVariableFormat(const char* text, int& size);
		// �Ƿ������ֵ��ʽ
		bool isNumberFormat(const char* text, int& size);
		// �Ƿ�����ַ�����ʽ
		bool isStringFormat(const char* text, int& size);
		// �ַ����Ƿ��Է��ű���Ԫ�ؿ�ͷ
		bool isSingalFormat(const char* text, int& size);
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