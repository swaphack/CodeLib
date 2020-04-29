#pragma once

#include "Base/macros.h"
#include "Base/Protocol.h"
#include "MemoryData.h"
#include <map>
#include <cstdint>

namespace sys
{
	// ����
	class MemoryPointer
	{
	public:
		MemoryPointer(int8_t* ptr, uint32_t size);
		MemoryPointer(const MemoryData& data);
		virtual ~MemoryPointer();
	public:
		/**
		*	����
		*/
		int8_t* getPtr();
		/**
		*	��С
		*/
		uint32_t getSize();
		/**
		*	����
		*/
		void resetCursor();
		/**
		*	����ռ�
		*/ 
		MemoryPointer* alloctPtr(uint32_t size);
	protected:
		void clear();
	private:
		/**
		*	��С
		*/
		uint32_t _size = 0;
		/**
		*	����
		*/
		int8_t* _value = nullptr;

		// ��ǰ�α�λ��
		uint32_t _cursor;
		// �ѷ�����ڴ��
		std::map<uint32_t, MemoryPointer*> _alloctedPtrs;
	};
}