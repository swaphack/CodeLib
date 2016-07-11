#pragma once

#include "Message.h"

namespace idea
{
	// �¼�
	class Event : public sys::Object
	{
	public:
		Event();
		virtual ~Event();
	public:
		// ��ȡ��Ϣ
		Result* getMessage();
		// ������Ϣ
		void setMessage(Result* result);
		// ��ȡ�¼�����
		int getType();
		// �����¼�����
		void setType(int value);
	private:
		// ��Ϣ
		Message* _message;
		// �¼�����
		int _type;
	};
}