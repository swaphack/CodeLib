#pragma once

#include "system.h"
#include <set>

namespace render
{
	class Action;
	class Node;

	// ��������
	class ActionManager : public sys::ITimer
	{
	public:
		ActionManager();
		virtual ~ActionManager();
	public:
		// ����
		void update(float interval);
		// ��Ӷ���
		void addAction(Action* action);
		// �Ƴ�����
		void removeAction(Action* action);
		// �Ƴ����ж���
		void removeAllActions();

		void pauseAllActionsByTargets(Node* target);
		void resumeAllActionsByTargets(Node* target);
		void removeAllActionsByTargets(Node* target);
	private:
		std::set<Action*> _actions;
	};

	#define G_ACTIONMANAGER sys::Instance<ActionManager>::getInstance()
}