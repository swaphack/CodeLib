#pragma once

#include "Message.h"

namespace idea
{
	// �¼�
	class Event
	{
	public:
		Event();
		virtual ~Event();
	public:
		// ������Ϣ
		void setMessage(Message* message);
		// ��ȡ��Ϣ
		Message* getMessage();
	private:
		// ��Ϣ
		Message* _message;
	};
}