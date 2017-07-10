#pragma once

#include "macros.h"

namespace ll
{
	struct Word;

	class English : Library
	{
	public:
		// ��������
		void load(const char* content, int size);
	private:
		bool readWord(char* ptr);
	};
}