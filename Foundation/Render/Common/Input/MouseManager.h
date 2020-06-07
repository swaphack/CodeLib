#pragma once

#include "system.h"
#include "MouseDelegate.h"

namespace render
{
	class Node;
	class MouseManager
	{
	public:
		MouseManager();
		~MouseManager();
	public:
		// ��������ֻ����ɷ�����
		void addMouseScrollDelegate(sys::Object* target, Node* node, MOUSE_SCROLL_DELEGATE_HANDLER handler);
		// �Ƴ������ֻ����ɷ�����
		void removeMouseScrollDelegate(sys::Object* target, Node* node);
		// �Ƴ����������ֻ����ɷ�����
		void removeAllMouseScrollDelegates();
	public:
		// ��������ֻ����ɷ�����
		void addMouseScrollFunc(sys::Object* target, Node* node, MouseScrollFunc func);
		// �Ƴ������ֻ����ɷ�����
		void removeMouseScrollFunc(sys::Object* target, Node* node);
		// �Ƴ����������ֻ����ɷ�����
		void removeAllMouseScrollFuncs();
	public:
		// �ɷ����ܵ��İ�ť�¼�
		void onDispatcher(sys::ScrollEvent evt, float param);
	private:
		// �����¼�ί�м�
		std::map<sys::Object*, std::map<Node*, MOUSE_SCROLL_DELEGATE_HANDLER>> _mouseScrollDelegates;
		// �����¼�ί�м�
		std::map< sys::Object*, std::map<Node*, MouseScrollFunc>> _mouseScrollFuncs;
	};


#define G_MOUSEMANAGER sys::Instance<MouseManager>::getInstance()
}