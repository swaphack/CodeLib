#pragma once

#include <vector>

namespace render
{
	class Node;
	class Action;

	class ActionProxy : public sys::Object
	{
	public:
		ActionProxy();
		~ActionProxy();
	public:
		void setTarget(Node* target);
		Node* getTarget();
		// 执行动作
		Action* runAction(Action* handler);
		// 停止动作
		void stopAction(Action* handler);
		// 暂停动作
		void pauseAction(Action* handler);
		// 恢复动作
		void reusmeAction(Action* handler);
		// 暂停所有动作
		void pauseAllActions();
		// 恢复所有动作
		void resumeAllActions();
		// 停止所有动作
		void stopAllActions();
	private:
		// 对象
		Node* _target = nullptr;
	};
}