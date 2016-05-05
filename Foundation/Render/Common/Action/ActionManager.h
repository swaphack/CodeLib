#pragma once

#include "Action.h"

#include <set>

namespace render
{
	class Action;

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

		void pauseAllActionsByTargets(sys::Object* target);
		void resumeAllActionsByTargets(sys::Object* target);
		void removeAllActionsByTargets(sys::Object* target);
	private:
		std::set<Action*> _actions;
	};

	#define G_ACTIONMANAGER sys::Instance<ActionManager>::getInstance()
}