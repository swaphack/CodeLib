#pragma once

#include "macros.h"

#include <map>

namespace ll
{
	// ���Կ�
	class LibLanguage
	{
	public:
		LibLanguage();
		virtual ~LibLanguage();
	public:
		// ���һ������
		void addWord(Word* word);
		// �Ƴ�һ������
		void removeWord(const char* word);
		// �Ƴ����е���
		void removeAllWords();
		// ��ȡһ��������Ϣ
		const Word* getWord(const char* word);
	private:
		// һ������ �ı�
		typedef std::map<Text, Word*> FirstIndex;
		// �������� �ı���ͷ-26����ĸ
		typedef std::map<int, FirstIndex> SecondIndex;
	private:
		// �ı�
		SecondIndex m_iTexts;
	};
}