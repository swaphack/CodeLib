#pragma once

#include "Action.h"

namespace render
{
	typedef void (sys::Object::*ACTION_UPDATE)(float intervale);
	#define SEL_ACTION_UPDATE(SELECTOR) static_cast<ACTION_UPDATE>(&SELECTOR)

	// �����Զ�ʱ��
	class Scheduler : public Action
	{
	public:
		Scheduler();
		virtual ~Scheduler();
	public:
		virtual void update(float interval);
		// ���ö���ִ���¼�
		void setHandler(const ACTION_UPDATE handler);
	protected:
		// ����ִ���¼�
		ACTION_UPDATE _handler;
	};
}