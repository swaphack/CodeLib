#pragma once

#include "system.h"

#include <map>
#include <string>


namespace search
{
	/*
	 * ×Ö·û´®³Ø
	 * Î¨Ò»×Ö·û´®
	 */
	class StringPool
	{
	public:
		// »ñÈ¡×Ö·û´®
		std::string* getString(const char* str);
	private:
		uint32_t getHash(const char* str);
	private:
		std::map<uint32_t, std::string> _strings;
	};

	#define GET_STRING_PTR(str) (sys::Instance<StringPool>::getInstance()->getString(str))
}