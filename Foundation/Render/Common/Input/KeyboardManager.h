#pragma once

#include "system.h"
#include "KeyboardDelegate.h"

namespace render
{
	class Node;
	class KeyboardManager
	{
	public:
		KeyboardManager();
		~KeyboardManager();
	public:
		// ��Ӱ����ɷ�����
		void addKeyboardDelegate(sys::Object* target, Node* node, KEYBOARD_DELEGATE_HANDLER handler);
		// �Ƴ������ɷ�����
		void removeKeyboardDelegate(sys::Object* target, Node* node);
		// �Ƴ����а����ɷ�����
		void removeAllKeyboardDelegates();
	public:
		// ��Ӱ����ɷ�����
		void addKeyboardFunc(sys::Object* target, Node* node, KeyboardFunc func);
		// �Ƴ������ɷ�����
		void removeKeyboardFunc(sys::Object* target, Node* node);
		// �Ƴ����а����ɷ�����
		void removeAllKeyboardFuncs();
	public:
		// �Ƴ������¼�
		void removeTargetAllEvents(sys::Object* target);
	public:
		// �ɷ����յ��İ�ť�¼�
		void onDispatchButtonEvent(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// �����¼�ί�м�
		std::map<sys::Object*, std::map<Node*, KEYBOARD_DELEGATE_HANDLER>> _keyboardDelegates;
		// �����¼�ί�м�
		std::map< sys::Object*, std::map<Node*, KeyboardFunc>> _keyboardFuncs;
	};


	#define G_KEYBOARDMANAGER sys::Instance<render::KeyboardManager>::getInstance()
}