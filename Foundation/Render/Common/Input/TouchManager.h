#pragma once

#include "system.h"
#include "TouchDelegate.h"
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
		void addBeganTouchPoint(const math::Vector2& touchPoint);
		void addMovedTouchPoint(const math::Vector2& touchPoint);
		void addEndedTouchPoint(const math::Vector2& touchPoint);
	public:
		// ����
		void process();
	protected:
		// ��ӽӴ���Ϣ
		void addTouchInfo(TouchType type, const math::Vector2& touchPoint);

		void onTouchBegan(const math::Vector2& touchPoint);
		void onTouchMoved(const math::Vector2& touchPoint);
		void onTouchEnded(const math::Vector2& touchPoint);
	private:
		struct TouchSlotInfo
		{
			TouchType type = TouchType::NONE;
			math::Vector2 touchPoint;

			TouchSlotInfo() {}
		};
		std::vector<TouchProtocol*> _targets;
		std::vector<TouchProtocol*> _temps;
		// ����ӵ��
		std::vector<TouchSlotInfo> _waitAddTouches;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}