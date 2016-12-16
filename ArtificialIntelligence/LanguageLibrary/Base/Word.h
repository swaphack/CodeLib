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
		typedef std::map<WordNominal, T_Text> WordMeaning;
	public:
		// �ı�
		T_Text Text;
		// ����(ƴ��)
		T_Text Pronunciation;
		// ����
		WordMeaning Meaning;
	public:

	};
}