#pragma once

#include "system.h"

namespace render
{
	typedef void(sys::Object::*KEYBOARD_DELEGATE_HANDLER)(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);

	#define KEYBOARD_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_DELEGATE_HANDLER>(&HANDLER_SEL)

	class KeyboardManager
	{
	public:
		KeyboardManager();
		~KeyboardManager();
	public:
		// ��Ӱ����ɷ�����
		void addDispatcher(sys::Object* node, sys::Object* target, KEYBOARD_DELEGATE_HANDLER handler);
		// �Ƴ������ɷ�����
		void removeDispatcher(sys::Object* target);
		// �Ƴ����а����ɷ�����
		void removeAllDispatchers();
		// �ɷ����ܵ��İ�ť�¼�
		void onDispatcher(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// �ص����󣬻ص��ӿڣ��ص��������
		typedef sys::Tuple3<sys::Object*, KEYBOARD_DELEGATE_HANDLER, sys::Object*> KeyBoardDelegate;
		// �����¼�ί�м�
		std::vector<KeyBoardDelegate> _keyboardDispatchers;
	};


	#define G_KEYBOARDMANAGER sys::Instance<KeyboardManager>::getInstance()
}