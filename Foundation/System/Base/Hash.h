#pragma once

#include "Types.h"

namespace sys
{
	class Hash
	{
	public:
		static uint32_t getSDBMHash(char *str);

		// RS Hash Function
		static uint32_t getRSHash(char *str);

		// JS Hash Function
		static uint32_t getJSHash(char *str);

		// P. J. Weinberger Hash Function
		static uint32_t getPJWHash(char *str);

		// ELF Hash Function
		static uint32_t getELFHash(char *str);

		// BKDR Hash Function
		static uint32_t getBKDRHash(char *str);

		// DJB Hash Function
		static uint32_t getDJBHash(char *str);

		// AP Hash Function
		static uint32_t getAPHash(char *str);
	};
}