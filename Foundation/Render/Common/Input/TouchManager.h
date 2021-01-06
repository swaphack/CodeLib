#pragma once

#include "system.h"
#include <list>

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
		void addTarget(TouchProtocol* target);
		void removeTarget(TouchProtocol* target);
	public:
		void onTouchBegan(const math::Vector2& touchPoint);
		void onTouchMoved(const math::Vector2& touchPoint);
		void onTouchEnded(const math::Vector2& touchPoint);
	private:

		std::vector<TouchProtocol*> _targets;
		std::vector<TouchProtocol*> _temps;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}