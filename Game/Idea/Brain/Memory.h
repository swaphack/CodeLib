#pragma once
#include "../AI/ai.h"
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
		// ���÷��䳤��
		void setCapacity(int capacity);
		// ��ȡ���䳤��
		int getCapacity();
		// ��ȡʹ�õĳ���
		int getLength();
		// ��ȡ��Ϣ
		bool read(void* data, int& length);
		// д����Ϣ
		bool write(void* data, int length);
	protected:
		// �ڴ���䳤��
		int _capacity;
		// �ڴ�����
		void* _memory;
		// ��ʹ���ڴ泤��
		int _length;
	};

	// ����
	class Memory : public IWorker
	{
	public:
		Memory();
		virtual ~Memory();
	public:
		// ��ȡһ���Ѵ��ڵ��ڴ�
		Storage* pick(const char* name);
		// ����һ���µ��ڴ�
		Storage* alloc(const char* name, int capacity);

		virtual Result* run(Event* e);
	protected:
		std::map<std::string, Storage*> _storages;
	};
}