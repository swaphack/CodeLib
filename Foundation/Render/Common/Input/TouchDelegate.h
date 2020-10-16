#pragma once


#include "system.h"
#include <functional>

namespace render
{
	class Node;

	// ��������
	enum class TouchType
	{
		NONE,	// δ����
		DOWN,	// ����	
		ON,		// ��ס����
		UP,		// ����
	};

	typedef void (sys::Object::*TOUCH_DELEGATE_HANDLER)(Node* node, float x, float y, bool include);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// ����ί��
	typedef std::pair<sys::Object*, TOUCH_DELEGATE_HANDLER> TouchDelegate;

	// ����������
	typedef std::function<void(Node* node, float x, float y, bool include)> TouchFunc;

	// ����Э��
	class TouchProtocol
	{
	public:
		virtual ~TouchProtocol() {}
	public:
		/**
		*	�����Ļ
		*/
		virtual bool onTouchBegan(float x, float y, bool include) = 0;
		/**
		*	����Ļ�ϻ���
		*/
		virtual bool onTouchMoved(float x, float y, bool include) = 0;
		/**
		*	�뿪��Ļ
		*/
		virtual bool onTouchEnded(float x, float y, bool include) = 0;
	};
}