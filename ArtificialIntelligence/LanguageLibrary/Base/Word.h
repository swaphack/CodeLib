#pragma once

#include "T_Text.h"
#include "Enumerator.h"

#include <map>

namespace ll
{
	// ����
	class Word
	{
	public:
		// ������˼ {���ԣ�˵��}
		typedef std::map<WordNominal, Text> WordMeaning;
	public:
		// �ı�
		Text Value;
		// ����(ƴ��)
		Text Pronunciation;
		// ����
		WordMeaning Meaning;
	};
}