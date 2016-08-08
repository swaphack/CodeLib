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
		uint getHash(const char* str);
		// »ñÈ¡×Ö·û´®
		std::string* getString(const char* str);
	protected:
		std::map<uint, std::string> _strings;
	};

	#define GET_STRING_PTR(str) (sys::Instance<StringPool>::getInstance()->getString(str))
}