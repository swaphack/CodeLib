#pragma once

namespace sys
{
	// �ź�
	class Signal
	{
	public:
		Signal();
		virtual ~Signal();
	public:
		// ������Ϣ
		virtual void setMessage(void* msg);
		// ��ȡ��Ϣ
		virtual void* getMessage() const;
	private:
		void* _msg = nullptr;
	};
}