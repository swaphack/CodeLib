#pragma once

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
		static const int32_t INVALID_THREAD_ID = -1;
	public:
		Thread();
		~Thread();
	public:
		// ִ��
		template<class _Fn, class... _Args>
		void startWithParams(_Fn&& handler, _Args&&... _Ax);
		// ִ��
		void start(const std::function<void()>& handler);
		// ����ִ��
		bool detach();
		// ����ִ��
		bool join();
		// ֹͣ
		bool isFinish() const;
		// ��ȡ�߳�id
		int32_t getID() const;
	private:
		// �����߳�
		std::thread m_pThread;
		// �߳�id
		size_t m_nID = 0;
		// �Ƿ����
		bool m_bFinish = false;
	};

	template<class _Fn, class... _Args>
	void Thread::startWithParams(_Fn&& handler, _Args&&... _Ax)
	{
		m_pThread = std::thread([=](_Args&&... _Bx){
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