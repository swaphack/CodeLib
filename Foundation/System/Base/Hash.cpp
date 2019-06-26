#include "Hash.h"

using namespace sys;

uint32 Hash::getSDBMHash(char *str)
{
	uint32 hash = 0;

	while (*str)
	{
		// equivalent to: hash = 65599*hash + (*str++);
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}

	return (hash & 0x7FFFFFFF);
}

// RS Hash Function
uint32 Hash::getRSHash(char *str)
{
	uint32 b = 378551;
	uint32 a = 63689;
	uint32 hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

// JS Hash Function
uint32 Hash::getJSHash(char *str)
{
	uint32 hash = 1315423911;

	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF);
}

// P. J. Weinberger Hash Function
uint32 Hash::getPJWHash(char *str)
{
	uint32 BitsInUnignedint32 = (uint32)(sizeof(uint32) * 8);
	uint32 ThreeQuarters    = (uint32)((BitsInUnignedint32  * 3) / 4);
	uint32 OneEighth        = (uint32)(BitsInUnignedint32 / 8);
	uint32 HighBits         = (uint32)(0xFFFFFFFF) << (BitsInUnignedint32 - OneEighth);
	uint32 hash             = 0;
	uint32 test             = 0;

	while (*str)
	{
		hash = (hash << OneEighth) + (*str++);
		if ((test = hash & HighBits) != 0)
		{
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
		}
	}

	return (hash & 0x7FFFFFFF);
}

// ELF Hash Function
uint32 Hash::getELFHash(char *str)
{
	uint32 hash = 0;
	uint32 x    = 0;

	while (*str)
	{
		hash = (hash << 4) + (*str++);
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF);
}

// BKDR Hash Function
uint32 Hash::getBKDRHash(char *str)
{
	uint32 seed = 131; // 31 131 1313 13131 131313 etc..
	uint32 hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

// DJB Hash Function
uint32 Hash::getDJBHash(char *str)
{
	uint32 hash = 5381;

	while (*str)
	{
		hash += (hash << 5) + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

// AP Hash Function
uint32 Hash::getAPHash(char *str)
{
	uint32 hash = 0;
	int32 i;

	for (i=0; *str; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
		}
	}

	return (hash & 0x7FFFFFFF);
}