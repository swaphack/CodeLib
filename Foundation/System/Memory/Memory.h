#pragma once

#include <string>
#include <cstdint>
#include <map>

namespace sys
{
	class MemoryData;

	// �ڴ����
	class Memory
	{
	private:
		Memory();
		~Memory();
	public:
		static Memory* getInstance();
		// ����һ������
		MemoryData* alloct(const std::string& name, uint32_t size);
		// ����һ������
		void destory(const std::string& name);
		// ���
		void clear();
	private:
		// �ѷ���Ļ���
		std::map<std::string, MemoryData*> _caches;
		// Ψһʵ��
		static Memory* s_pMemory;
	};
}