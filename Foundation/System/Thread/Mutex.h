#pragma once

#include <mutex>

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
		void lock();
		// 尝试加锁
		bool tryLock();
		// 解锁
		void unlock();
		// 是否加锁
		bool isLock();
	private:
		// 互斥锁
		std::mutex m_pMutex;
		// 守护锁
		std::unique_lock<std::mutex> m_pLock;
		// 是否加锁
		bool m_bLock;
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
		int m_nLockCount;
	};
}