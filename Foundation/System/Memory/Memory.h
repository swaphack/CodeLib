#pragma once

#include "Base/import.h"
#include "PtrCache.h"

namespace sys
{
	// �ڴ����
	class Memory
	{
	private:
		Memory();
		~Memory();
	public:
		static Memory* getInstance();
		// ����һ������
		PtrCache* alloct(const char* name, uint32 size);
		// ����һ������
		void destory(const char* name);
		// ���
		void clear();
	private:
		// �ѷ���Ļ���
		std::map<std::string, PtrCache*> _caches;
		// Ψһʵ��
		static Memory* s_pMemory;
	};
}