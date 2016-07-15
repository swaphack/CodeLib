#include "system.h"
#include "../Node/import.h"

#include <functional>

namespace render
{
	// ��������
	enum TouchType
	{
		ETT_NONE,	// δ����
		ETT_DOWN,	// ����	
		ETT_ON,		// ��ס����
		ETT_UP,		// ����
	};

	typedef void (sys::Object::*TOUCH_DELEGATE_HANDLER)(sys::Object* object, float x, float y);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// ����ί��
	struct TouchDelegate
	{
	public:
		sys::Object* target;

		TOUCH_DELEGATE_HANDLER handler;

		TouchDelegate() :target(nullptr), handler(nullptr){}

		void hand(sys::Object* obj, float x, float y)
		{
			if (!empty())
				(target->*handler)(obj, x, y);
		}

		bool empty()
		{
			return handler == nullptr || target == nullptr;
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