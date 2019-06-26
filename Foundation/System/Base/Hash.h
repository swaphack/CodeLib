#pragma once

#include "Types.h"

namespace sys
{
	class Hash
	{
	public:
		static uint32 getSDBMHash(char *str);

		// RS Hash Function
		static uint32 getRSHash(char *str);

		// JS Hash Function
		static uint32 getJSHash(char *str);

		// P. J. Weinberger Hash Function
		static uint32 getPJWHash(char *str);

		// ELF Hash Function
		static uint32 getELFHash(char *str);

		// BKDR Hash Function
		static uint32 getBKDRHash(char *str);

		// DJB Hash Function
		static uint32 getDJBHash(char *str);

		// AP Hash Function
		static uint32 getAPHash(char *str);
	};
}