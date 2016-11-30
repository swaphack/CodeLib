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
		// ������ʼλ��
		inline Token::const_iterator tokenBegin()
		{
			return m_vWords.begin();
		}
		// ���ʽ���λ��
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
		// ����
		Token m_vWords;
	};
}