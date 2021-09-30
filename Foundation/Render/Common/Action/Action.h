#pragma once

#include "system.h"
#include "ActionProtocol.h"

namespace render
{
	class Node;

	//class ActionManager;
	// 动作接口
	class Action : public sys::Object, public ActionProtocol, public sys::ITimer
	{
	public:
		Action();
		virtual ~Action();
	public:
		virtual void update(float duration) {}
		// 重置
		virtual void reset();
		// 反转
		virtual void reverse() {}
		// 设置动作执行目标
		virtual void setTarget(Node* target);
		// 判断动作执行对象是否相同
		bool isEqualsTarget(const Node* target) const;

		const Node* getTarget() const;
	protected:
		// 动作执行目标
		Node* _target;
	};

#define CREATE_ACTION(ACTION_TYPE) render::createAction<ACTION_TYPE>()

	template<typename T, typename = std::enable_if<std::is_base_of<Action, T>::value, T>::type>
	T* createAction()
	{
		T* temp = new T();

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}
}