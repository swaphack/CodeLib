#pragma once

#include <mutex>
#include "Base/Types.h"

namespace sys
{
	// 互斥锁
	class Mutex
	{
	public:
		Mutex();
		~Mutex();
	public:
		// 加锁
		void lock(const std::string& msg = "");
		// 尝试加锁
		bool tryLock(const std::string& msg = "");
		// 解锁
		void unlock(const std::string& msg = "");
	private:
		// 互斥锁
		std::mutex m_pMutex;
		// 守护锁
		std::unique_lock<std::mutex> m_pLock;
	};

	// 多重互斥锁
	class MultMutex
	{
	public:
		MultMutex();
		~MultMutex();
	public:
		// 加锁
		void lock();
		// 尝试加锁
		bool tryLock();
		// 解锁
		void unlock();
		// 是否加锁
		bool isLock();
	private:
		std::recursive_mutex m_pMutex;
		// 守护锁
		std::unique_lock<std::recursive_mutex> m_pLock;
		// 互斥锁的个数
		int32 m_nLockCount;
	};
}