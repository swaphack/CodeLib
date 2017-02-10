#pragma once

#include "../Base/import.h"
#include "PtrCache.h"

#include <string>
#include <map>

namespace sys
{
	// �ڴ����
	class Memory
	{
	private:
		Memory();
	public:
		~Memory();
	public:
		static Memory* getInstance();
		// ����һ������
		PtrCache* alloct(const char* name, uint size);
		// ����һ������
		void destory(const char* name);
	protected:
		void dispose();
	private:
		// �ѷ���Ļ���
		std::map<std::string, PtrCache*> _caches;
		// Ψһʵ��
		static Memory* s_pMemory;
	};
}