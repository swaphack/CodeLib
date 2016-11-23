#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	//class ActionManager;
	// 动作接口
	class Action : public SystemProtocol, public sys::ITimer
	{
	public:
		Action();
		virtual ~Action();
	public:
		virtual void update(float duration) {}
		// 设置动作执行目标
		void setTarget(sys::Object* target);		
		// 判断动作执行对象是否相同
		bool isEqualsTarget(const sys::Object* target);
	protected:
		// 动作执行目标
		sys::Object* _target;
		
	};
}