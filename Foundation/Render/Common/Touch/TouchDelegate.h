#include "system.h"
#include "../Node/import.h"

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

	typedef void (*TOUCH_DELEGATE_HANDLER)(sys::Object* object, float x, float y);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// ����ί��
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