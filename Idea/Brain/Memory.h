#pragma once

#include <map>
#include <string>

namespace idea
{
	// �洢��Ԫ
	class Storage
	{
	public:
		Storage(int capacity);
		virtual ~Storage();
	public:
		int getCapacity();
	protected:
	private:
		// �ڴ���䳤��
		int _capacity;
		// �ڴ�����
		void* _memory;
	};

	// ����
	class Memory
	{
	public:
		Memory();
		~Memory();
	public:
		// ��ȡһ���Ѵ��ڵ��ڴ�
		Storage* pick(const char* name);
		// ����һ���µ��ڴ�
		Storage* alloc(const char* name, int capacity);
	protected:
	private:
		std::map<std::string, Storage*> _storages;
	};
}