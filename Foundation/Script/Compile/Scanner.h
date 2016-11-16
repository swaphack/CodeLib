#pragma once

#include <string>
#include <vector>

namespace script
{
	typedef std::vector<std::string> Token;
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
		bool read(const char* ptr, int size);
		// ���ɨ����Ϣ
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
		// ����
		bool parse();
		// ��ȡ����
		void readWord();
	private:
		// ��ǰ�α�ָ��
		char* getPtr();
		// �Ƿ������ʽ
		bool isVariableFormat(const char* text);
		// ��ʼ�Ƿ�����ؼ���
		bool containKeyWord(const char* text, int& offset, int& size);
	private:
		// �ı�����ָ��
		char* m_pContent;
		// ƫ��λ��
		int m_nOffset;
		// �ı���С
		int m_nSize;
		// ����
		Token m_vWords;
	};
}