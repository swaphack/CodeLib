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
		// ��ȡ��Ϣ
		virtual Message* getMessage();
	protected:
		// ������Ϣ
		virtual void setMessage(Message* message);
	private:
		// ��Ϣ
		Message* _message;
	};
}