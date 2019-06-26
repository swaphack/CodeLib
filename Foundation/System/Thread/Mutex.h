#pragma once

#include <mutex>
#include "Base/Types.h"

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
		void lock(const std::string& msg = "");
		// ���Լ���
		bool tryLock(const std::string& msg = "");
		// ����
		void unlock(const std::string& msg = "");
	private:
		// ������
		std::mutex m_pMutex;
		// �ػ���
		std::unique_lock<std::mutex> m_pLock;
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
		int32 m_nLockCount;
	};
}