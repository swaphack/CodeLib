#pragma once

#include "system.h"
#include "TouchProxy.h"

#include <set>

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

		bool onTouchBegan(float x, float y);
		void onTouchMove(float x, float y);
		void onTouchEnd(float x, float y);
	private:
		std::vector<TouchProxy*> _touchProtocols;
		TouchProxy* _lastTouchProtocol;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}