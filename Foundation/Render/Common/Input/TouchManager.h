#pragma once

#include "system.h"
#include <vector>

namespace render
{
	class Node;
	class TouchProxy;
	// ��������
	class TouchManager 
	{
	public:
		TouchManager();
		virtual ~TouchManager();
	public:
		// ��Ӵ�������
		void addTouch(TouchProxy* protocol);
		// �Ƴ���������
		void removeTouch(TouchProxy* protocol);
		// �Ƴ����д�������
		void removeAllTouches();

		void onTouchBegan(float x, float y);
		void onTouchMoved(float x, float y);
		void onTouchEnded(float x, float y);
	private:
		std::vector<TouchProxy*> _touchProtocols;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}