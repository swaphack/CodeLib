#pragma once

#include "Mutex.h"

#include <functional>
#include <thread>

namespace sys
{
	// �߳�
	class Thread
	{
	public:
		friend class ThreadPool;
		// ��Ч���߳�id
		static const int INVALID_THREAD_ID = -1;
	public:
		Thread();
		~Thread();
	public:
		// ִ��
		template<class _Fn, class... _Args>
		void startWithParams(_Fn&& handler, _Args&&... _Ax);
		// ִ��
		void start(std::function<void()> handler);
		// ����ִ��
		bool detach();
		// ����ִ��
		bool join();
		// ֹͣ
		bool isFinish();
		// ��ȡ�߳�id
		int getID();
	private:
		// �����߳�
		std::thread m_pThread;
		// �߳�id
		size_t m_nID;
		// �Ƿ����
		bool m_bFinish;
	};

	template<class _Fn, class... _Args>
	void Thread::startWithParams(_Fn&& handler, _Args&&... _Ax)
	{
		m_pThread = std::thread([&](_Args&&... _Bx){
			do 
			{
				handler(_Bx...);
				m_bFinish = true;
			} while (0);
		}, _Ax...);
		m_nID = m_pThread.get_id().hash();
		m_bFinish = false;
	}
}