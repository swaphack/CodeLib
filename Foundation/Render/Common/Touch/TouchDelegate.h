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
	typedef std::pair<sys::Object*, TOUCH_DELEGATE_HANDLER> TouchDelegate;
}