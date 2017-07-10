#pragma once

#include "T_Text.h"
#include "Enumerator.h"

#include <map>

namespace ll
{
	// �ı��ṹ
	typedef std::string Text;

	// ������˼ {���ԣ�˵��}
	typedef std::map<WordNominal, Text> WordMeaning;

	// ����
	struct Word
	{		
	public:
		Word(const Text& value);
		Word(const Text& value, const WordMeaning& meaning);
		// ��ϣ���
		int hashID() const;
		// �ı�
		const Text& value() const;
		// ˳��
		const char index() const;
		// �Ƿ�Ϊ��
		bool empty() const;
		// ����
		void release();
	private:
		static int s_HashID;
		// �ı�
		Text _value;
		// ����
		WordMeaning _meaning;
		// ��ϣ���
		int _hashID;
	};
}