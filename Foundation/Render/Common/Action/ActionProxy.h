#pragma once

#include <vector>

namespace sys
{
	class Object;
}

namespace render
{
	class Action;

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