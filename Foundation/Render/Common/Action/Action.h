#pragma once

#include "system.h"
#include "Common/struct/import.h"

namespace render
{
#define CREATE_ACTION(ACTION_TYPE) createAction<ACTION_TYPE>()

	template<typename T>
	T* createAction()
	{
		T* temp = new T();

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}

	//class ActionManager;
	// 动作接口
	class Action : public sys::Object, public SystemProtocol, public sys::ITimer
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
		virtual void setTarget(sys::Object* target);
		// 判断动作执行对象是否相同
		bool isEqualsTarget(const sys::Object* target);
	protected:
		// 动作执行目标
		sys::Object* _target;
		
	};
}