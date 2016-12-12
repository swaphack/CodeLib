#pragma once

#include "../macros.h"

#include <queue>

namespace idea
{
	// ����
	class IO
	{
	public:
		IO();
		virtual ~IO();
	public:
		// ��������Ϣ
		void push(Message* msg);
		// ��ȡ�����������Ϣ
		Message* pick();
	protected:
		void removeAllMessages();
	private:
		std::queue<Message*> _msgs;
	};
}