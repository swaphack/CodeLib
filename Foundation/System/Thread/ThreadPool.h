#pragma once

#include "Mutex.h"
#include <functional>
#include <map>
#include <condition_variable>

namespace sys
{
	class Thread;
	/** 
	*	�̳߳�
	*	��ӵ��̳߳ص��̣߳��ڽ����󣬻��Զ��ͷ�
	*/
	class ThreadPool
	{
	private:
		ThreadPool();
	public:
		~ThreadPool();
	public:
		static ThreadPool* getInstance();
		// ����һ�������������߳�
		Thread* createThread(const std::function<void()>& handler);

		// ����һ�����������߳�
		template<class _Fn, class... _Args>
		Thread* createThreadWithParams(_Fn&& handler, _Args&&... _Ax);

		// ���һ�����߳�
		void add(Thread* pThread);
		// �Ƴ�һ�����е��߳�
		void remove(size_t nThreadID);
	protected:
		void update();
	private:
		typedef std::map<size_t, Thread*> Threads;
		// �̼߳���
		Threads m_mThreads;
		// ���ӻ�����
		MultMutex m_pMutex;
	};

	template<class _Fn, class... _Args>
	Thread* ThreadPool::createThreadWithParams(_Fn&& handler, _Args&&... _Ax)
	{
		Thread* pThread = new Thread();
		pThread->startWithParams(handler, _Ax...);
		this->add(pThread);

		return pThread;
	}

}