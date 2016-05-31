#include "system.h"
#include "../Node/import.h"

namespace render
{
	// 触摸类型
	enum TouchType
	{
		ETT_NONE,	// 未触摸
		ETT_DOWN,	// 按下	
		ETT_ON,		// 按住不放
		ETT_UP,		// 放手
	};

	typedef void (*TOUCH_DELEGATE_HANDLER)(sys::Object* object, float x, float y);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// 触摸委托
	struct TouchDelegate
	{
		sys::Object* target;
		TOUCH_DELEGATE_HANDLER handler;

		TouchDelegate() :target(nullptr), handler(nullptr){}

		void hand(float x, float y)
		{
			if (!empty())
				(*handler)(target, x, y);
		}

		bool empty()
		{
			return handler == nullptr;
		}

		bool isEquals(sys::Object* t, TOUCH_DELEGATE_HANDLER h)
		{
			return target == t && handler == h;
		}

		void clean()
		{
			target = nullptr;
			handler = nullptr;
		}
	};
}