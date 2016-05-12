#pragma once

#include "system.h"
#include "../Node/import.h"

namespace render
{
	// ����״̬
	enum TouchStatus
	{
		ETS_NONE,	// δ����
		ETS_DOWN,	// ����	
		EST_ON,		// ��ס����
		ETS_UP,		// ����
	};

	typedef bool (sys::Object::*TOUCH_DELEGATE_SEL)(TouchStatus status, float x, float y);

	// ����ί��
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