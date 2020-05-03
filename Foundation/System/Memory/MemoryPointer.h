#pragma once

#include "Base/macros.h"
#include "Base/Protocol.h"
#include "MemoryData.h"
#include <map>
#include <cstdint>

namespace sys
{
	// 缓存
	class MemoryPointer
	{
	public:
		MemoryPointer(int8_t* ptr, size_t size);
		MemoryPointer(const MemoryData& data);
		virtual ~MemoryPointer();
	public:
		/**
		*	数据
		*/
		int8_t* getPtr();
		/**
		*	大小
		*/
		size_t getSize();
		/**
		*	重置
		*/
		void resetCursor();
		/**
		*	分配空间
		*/ 
		MemoryPointer* alloctPtr(size_t size);
	protected:
		void clear();
	private:
		/**
		*	大小
		*/
		size_t _size = 0;
		/**
		*	数据
		*/
		int8_t* _value = nullptr;

		// 当前游标位置
		size_t _cursor;
		// 已分配的内存块
		std::map<size_t, MemoryPointer*> _alloctedPtrs;
	};
}