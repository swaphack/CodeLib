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
		// �ɷ����յ��İ�ť�¼�
		void onDispatchScrolleEvent(sys::ScrollEvent evt, float param);
	public:
		// ��Ӱ����ɷ�����
		void addMouseButtonDelegate(sys::Object* target, Node* node, MOUSE_BUTTON_DELEGATE_HANDLER handler);
		// �Ƴ������ɷ�����
		void removeMouseButtonDelegate(sys::Object* target, Node* node);
		// �Ƴ����а����ɷ�����
		void removeAllMouseButtonDelegates();
	public:
		// ��Ӱ����ɷ�����
		void addMouseButtonFunc(sys::Object* target, Node* node, MouseButtonFunc func);
		// �Ƴ������ɷ�����
		void removeMouseButtonFunc(sys::Object* target, Node* node);
		// �Ƴ����а����ɷ�����
		void removeAllMouseButtonFuncs();
	public:
		// �Ƴ������¼�
		void removeTargetAllEvents(sys::Object* target);
	public:
		// �ɷ����յ��İ�ť�¼�
		void onDispatchButtonEvent(sys::MouseKey key, sys::ButtonStatus status, float x, float y);
	private:
		// �������¼�ί�м�
		std::map<sys::Object*, std::map<Node*, MOUSE_SCROLL_DELEGATE_HANDLER>> _mouseScrollDelegates;
		// �������¼�ί�м�
		std::map< sys::Object*, std::map<Node*, MouseScrollFunc>> _mouseScrollFuncs;
	private:
		// �����¼�ί�м�
		std::map<sys::Object*, std::map<Node*, MOUSE_BUTTON_DELEGATE_HANDLER>> _mouseButtonDelegates;
		// �����¼�ί�м�
		std::map< sys::Object*, std::map<Node*, MouseButtonFunc>> _mouseButtonFuncs;

	};


#define G_MOUSEMANAGER sys::Instance<MouseManager>::getInstance()
}