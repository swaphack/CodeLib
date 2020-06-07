#pragma once

#include <vector>

namespace render
{
	class Node;
	class Action;

	class ActionProxy
	{
	public:
		ActionProxy(Node* target);
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
		Node* _target;
	};
}