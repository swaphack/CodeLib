#pragma once

#include "macros.h"

namespace ll
{
	struct Word;

	class English : Library
	{
	public:
		// МгдиЪ§Он
		void load(const char* content, int size);
	private:
		bool readWord(char* ptr);
	};
}