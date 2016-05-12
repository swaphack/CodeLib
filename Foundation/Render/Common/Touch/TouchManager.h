#pragma once

#include "system.h"
#include "TouchProtocol.h"

#include <set>

namespace render
{
	class TouchProtocol;
	// ��������
	class TouchManager
	{
	public:
		TouchManager();
		virtual ~TouchManager();
	public:
		// ��Ӵ�������
		void addTouch(TouchProtocol* protocol);
		// �Ƴ���������
		void removeTouch(TouchProtocol* protocol);
		// �Ƴ����д�������
		void removeAllTouches();

		virtual bool onTouchBegan(float x, float y);
		virtual void onTouchMove(float x, float y);
		virtual void onTouchEnd(float x, float y);
	private:
		std::vector<TouchProtocol*> _touchProtocols;
		TouchProtocol* _lastTouchProtocol;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}