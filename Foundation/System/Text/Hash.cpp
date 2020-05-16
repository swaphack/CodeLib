#include "Hash.h"

using namespace sys;

uint32_t Hash::getSDBMHash(char *str)
{
	uint32_t hash = 0;

	while (*str)
	{
		// equivalent to: hash = 65599*hash + (*str++);
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}

	return (hash & 0x7FFFFFFF);
}

// RS Hash Function
uint32_t Hash::getRSHash(char *str)
{
	uint32_t b = 378551;
	uint32_t a = 63689;
	uint32_t hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

// JS Hash Function
uint32_t Hash::getJSHash(char *str)
{
	uint32_t hash = 1315423911;

	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF);
}

// P. J. Weinberger Hash Function
uint32_t Hash::getPJWHash(char *str)
{
	uint32_t BitsInUnignedint32 = (uint32_t)(sizeof(uint32_t) * 8);
	uint32_t ThreeQuarters    = (uint32_t)((BitsInUnignedint32  * 3) / 4);
	uint32_t OneEighth        = (uint32_t)(BitsInUnignedint32 / 8);
	uint32_t HighBits         = (uint32_t)(0xFFFFFFFF) << (BitsInUnignedint32 - OneEighth);
	uint32_t hash             = 0;
	uint32_t update             = 0;

	while (*str)
	{
		hash = (hash << OneEighth) + (*str++);
		if ((update = hash & HighBits) != 0)
		{
			hash = ((hash ^ (update >> ThreeQuarters)) & (~HighBits));
		}
	}

	return (hash & 0x7FFFFFFF);
}

// ELF Hash Function
uint32_t Hash::getELFHash(char *str)
{
	uint32_t hash = 0;
	uint32_t x    = 0;

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
uint32_t Hash::getBKDRHash(char *str)
{
	uint32_t seed = 131; // 31 131 1313 13131 131313 etc..
	uint32_t hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

// DJB Hash Function
uint32_t Hash::getDJBHash(char *str)
{
	uint32_t hash = 5381;

	while (*str)
	{
		hash += (hash << 5) + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

// AP Hash Function
uint32_t Hash::getAPHash(char *str)
{
	uint32_t hash = 0;
	int32_t i;

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