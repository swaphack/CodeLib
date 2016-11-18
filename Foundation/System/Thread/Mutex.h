#pragma once

#include <mutex>

namespace sys
{
	// ������
	class Mutex
	{
	public:
		Mutex();
		~Mutex();
	public:
		// ����
		void lock();
		// ���Լ���
		bool tryLock();
		// ����
		void unlock();
		// �Ƿ����
		bool isLock();
	private:
		// ������
		std::mutex m_pMutex;
		// �ػ���
		std::unique_lock<std::mutex> m_pLock;
		// �Ƿ����
		bool m_bLock;
	};

	// ���ػ�����
	class MultMutex
	{
	public:
		MultMutex();
		~MultMutex();
	public:
		// ����
		void lock();
		// ���Լ���
		bool tryLock();
		// ����
		void unlock();
		// �Ƿ����
		bool isLock();
	private:
		std::recursive_mutex m_pMutex;
		// �ػ���
		std::unique_lock<std::recursive_mutex> m_pLock;
		// �������ĸ���
		int m_nLockCount;
	};
}