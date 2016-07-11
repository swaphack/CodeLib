#pragma once
#include "../macros.h"
#include "Storage.h"
#include <map>
#include <string>

namespace idea
{
	// ����
	class Memory : public IWorker
	{
	public:
		Memory();
		virtual ~Memory();
	public:
		static Memory* getInstance();

		// ��ȡһ���Ѵ��ڵ��ڴ�
		Storage* pick(const char* name);

		// ����һ���µ��ڴ�
		Storage* alloc(const char* name, int capacity);
		// T �� Result
		Storage* alloc(const char* name, Result* cls);

		// �������
		virtual Result* run(Event* e);
	protected:
		std::map<std::string, Storage*> _storages;
	};
}