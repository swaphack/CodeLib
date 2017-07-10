#pragma once

#include "macros.h"

#include <map>

namespace ll
{
	// �ı���
	class Dictionary
	{
	public:
		Dictionary();
		virtual ~Dictionary();
	public:
		// ���һ������
		void addWord(Word* word);
		// �Ƴ�һ������
		void removeWord(Word* word);
		// �Ƴ����е���
		void removeAllWords();
		// ��ȡһ��������Ϣ
		const Word* getWord(const Text& text);
	private:
		// �ı�
		typedef std::map<Text, Word*> FirstIndex;
	private:
		// �ı�
		FirstIndex m_Texts;
	};
}