#pragma once

namespace idea
{
	// �洢��Ԫ
	class Storage
	{
	public:
		Storage(int capacity);
		virtual ~Storage();
	public:
		// ��ȡ���䳤��
		int getCapacity();
		// ��������
		void setMemory(void* memory, int capacity);
		// ��ȡ����
		void* getMemory();
		// ��ȡ��Ϣ
		bool read(void* data, int& length);
		// д����Ϣ
		bool write(void* data, int length);
	protected:
		// �ڴ���䳤��
		int _capacity;
		// �ڴ�����
		void* _memory;
	};
}