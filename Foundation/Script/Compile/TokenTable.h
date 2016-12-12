#pragma once

#include "macros.h"

namespace script
{
	// ���ű�
	class TokenTable
	{
	public:
		TokenTable();
		virtual ~TokenTable();
	public:
		// ���һ������
		void addToken(const char* token);
		// �Ƴ����з���
		void removeAllTokens();

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
		Token m_vWords;
	};

	// ������¼��
	class VariableTable
	{
	public:
	protected:
	private:
	};

	// �ַ�����¼��
	class StringTable
	{
	public:
	protected:
	private:
	};
	
	// ��ֵ��¼��
	class NumberTable
	{
	public:
	protected:
	private:
	};
}