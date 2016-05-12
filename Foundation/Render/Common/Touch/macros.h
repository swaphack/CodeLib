#pragma once

#include "system.h"
#include "../Node/import.h"

namespace render
{
	// 触摸状态
	enum TouchStatus
	{
		ETS_NONE,	// 未触摸
		ETS_DOWN,	// 按下	
		EST_ON,		// 按住不放
		ETS_UP,		// 放手
	};

	typedef bool (sys::Object::*TOUCH_DELEGATE_SEL)(TouchStatus status, float x, float y);

	// 触摸委托
	struct TouchDelegate
	{
		sys::Object* target;
		TOUCH_DELEGATE_SEL hander;

		TouchDelegate() :target(nullptr), hander(nullptr){}

		void hand(TouchStatus status, float x, float y)
		{
			if (!empty())
				(target->*hander)(status, x, y);
		}

		bool empty()
		{
			return target == nullptr || hander == nullptr;
		}

		void clean()
		{
			target = nullptr;
			hander = nullptr;
		}
	};
}