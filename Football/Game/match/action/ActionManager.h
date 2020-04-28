#pragma once

#include "../../base/ITimer.h"

#include <set>

namespace game
{
	class ActionManager : public ITimer
	{
	public:
		ActionManager();
		virtual ~ActionManager();
	public:
		/**
		*	���Ӷ���
		*/
		virtual void addAction(ITimer* action);
		/**
		*	�Ƴ�����
		*/
		virtual void removeAction(ITimer* action);
		/**
		*	�Ƴ����ж���
		*/
		virtual void removeAllActions();
		/**
		*	����
		*/
		virtual void update(float dt);
	private:
		std::set<ITimer*> m_sActions;
	};
}