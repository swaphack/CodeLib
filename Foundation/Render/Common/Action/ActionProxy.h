#pragma once

#include "Action.h"

#include <vector>

namespace render
{
	class ActionProxy
	{
	public:
		ActionProxy(sys::Object* target);
		~ActionProxy();
	public:
		// ִ�ж���
		Action* runAction(Action* handler);
		// ֹͣ����
		void stopAction(Action* handler);
		// ��ͣ����
		void pauseAction(Action* handler);
		// �ָ�����
		void reusmeAction(Action* handler);
		// ��ͣ���ж���
		void pauseAllActions();
		// �ָ����ж���
		void resumeAllActions();
		// ֹͣ���ж���
		void stopAllActions();
	private:
		// ����
		sys::Object* _target;
	};
}