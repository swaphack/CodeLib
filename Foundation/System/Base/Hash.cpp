#include "Hash.h"

using namespace sys;

uint Hash::getSDBMHash(char *str)
{
	uint hash = 0;

	while (*str)
	{
		// equivalent to: hash = 65599*hash + (*str++);
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}

	return (hash & 0x7FFFFFFF);
}

// RS Hash Function
uint Hash::getRSHash(char *str)
{
	uint b = 378551;
	uint a = 63689;
	uint hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

// JS Hash Function
uint Hash::getJSHash(char *str)
{
	uint hash = 1315423911;

	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF);
}

// P. J. Weinberger Hash Function
uint Hash::getPJWHash(char *str)
{
	uint BitsInUnignedInt = (uint)(sizeof(uint) * 8);
	uint ThreeQuarters    = (uint)((BitsInUnignedInt  * 3) / 4);
	uint OneEighth        = (uint)(BitsInUnignedInt / 8);
	uint HighBits         = (uint)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);
	uint hash             = 0;
	uint test             = 0;

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
uint Hash::getELFHash(char *str)
{
	uint hash = 0;
	uint x    = 0;

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
uint Hash::getBKDRHash(char *str)
{
	uint seed = 131; // 31 131 1313 13131 131313 etc..
	uint hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

// DJB Hash Function
uint Hash::getDJBHash(char *str)
{
	uint hash = 5381;

	while (*str)
	{
		hash += (hash << 5) + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

// AP Hash Function
uint Hash::getAPHash(char *str)
{
	uint hash = 0;
	int i;

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