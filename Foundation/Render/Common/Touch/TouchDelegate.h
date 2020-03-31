#pragma once


#include "system.h"
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

	// ����Э��
	class TouchProtocol
	{
	public:
		virtual ~TouchProtocol() {}
	public:
		// �����Ļ
		virtual bool onTouchBegan(float x, float y) = 0;
		// ����Ļ�ϻ���
		virtual void onTouchMoved(float x, float y) = 0;
		// �뿪��Ļ
		virtual void onTouchEnded(float x, float y) = 0;
	};
}