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
		MemoryPointer(char* ptr, size_t size);
		MemoryPointer(const MemoryData& data);
		virtual ~MemoryPointer();
	public:
		/**
		*	����
		*/
		char* getPtr() const;
		/**
		*	��С
		*/
		size_t getSize() const;
		/**
		*	����
		*/
		void resetCursor();
		/**
		*	����ռ�
		*/ 
		MemoryPointer* alloctPtr(size_t size);
	protected:
		void clear();
	private:
		/**
		*	��С
		*/
		size_t _size = 0;
		/**
		*	����
		*/
		char* _value = nullptr;

		// ��ǰ�α�λ��
		size_t _cursor;
		// �ѷ�����ڴ��
		std::map<size_t, MemoryPointer*> _alloctedPtrs;
	};
}