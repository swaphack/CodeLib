#pragma once

#include "Types.h"

namespace sys
{
	class Hash
	{
	public:
		static uint getSDBMHash(char *str);

		// RS Hash Function
		static uint getRSHash(char *str);

		// JS Hash Function
		static uint getJSHash(char *str);

		// P. J. Weinberger Hash Function
		static uint getPJWHash(char *str);

		// ELF Hash Function
		static uint getELFHash(char *str);

		// BKDR Hash Function
		static uint getBKDRHash(char *str);

		// DJB Hash Function
		static uint getDJBHash(char *str);

		// AP Hash Function
		static uint getAPHash(char *str);
	};
}