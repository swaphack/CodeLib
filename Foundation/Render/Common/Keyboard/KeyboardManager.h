#pragma once

#include "system.h"

namespace render
{
	typedef void(*KEYBOARD_DELEGATE_HANDLER)(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);

	#define KEYBOARD_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_DELEGATE_HANDLER>(&HANDLER_SEL)

	// ����ί��
	struct KeyBoardDelegate
	{
		sys::Object* target;
		KEYBOARD_DELEGATE_HANDLER handler;

		KeyBoardDelegate() :target(nullptr), handler(nullptr){}

		void hand(sys::BoardKey key, sys::ButtonStatus type)
		{
			if (!empty())
				(*handler)(target, key, type);
		}

		bool empty()
		{
			return handler == nullptr;
		}

		bool isEquals(sys::Object* t, KEYBOARD_DELEGATE_HANDLER h)
		{
			return target == t && handler == h;
		}

		void clean()
		{
			target = nullptr;
			handler = nullptr;
		}
	};

	class KeyboardManager
	{
	public:
		KeyboardManager();
		~KeyboardManager();
	public:
		// ��Ӱ����ɷ�����
		void addDispatcher(sys::Object* node, KEYBOARD_DELEGATE_HANDLER handler);
		// �Ƴ������ɷ�����
		void removeDispatcher(sys::Object* node);
		// �Ƴ����а����ɷ�����
		void removeAllDispatchers();
		// �ɷ����ܵ��İ�ť�¼�
		void onDispatcher(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// �����¼�ί�м�
		std::vector<KeyBoardDelegate*> _keyboardDispatchers;
	};


	#define G_KEYBOARDMANAGER sys::Instance<KeyboardManager>::getInstance()
}