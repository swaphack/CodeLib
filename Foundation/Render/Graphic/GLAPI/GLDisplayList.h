#pragma once

#include "macros.h"

namespace render
{
	/**
	*	œ‘ æ¡–±Ì
	*/
	class GLDisplayList
	{
	public:
		static void newList(uint32_t list, InterleavedArrays type);
		static void endList();
	public:
		static void callList(uint32_t list);
		static void callLists(int size, ListNameType type, const void* lists);
	public:
		static int genLists(int range);
		static int genList();
		static void setListBase(uint32_t base);
	public:
		static bool isList(uint32_t list);
	public:
		static void deleteLists(uint32_t list, int range);
		static void deleteList(uint32_t list);
	};
}