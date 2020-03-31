#pragma once

#include "system.h"
#include "Common/Touch/TouchDelegate.h"
#include <vector>

namespace render
{
	class Node;
	class TouchProxy;
	// ��������
	class TouchManager : public TouchProtocol
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
		void onTouchMoved(float x, float y);
		void onTouchEnded(float x, float y);
	private:
		std::vector<TouchProxy*> _touchProtocols;
		TouchProxy* _lastTouchProtocol;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}