#pragma once

#include "IntervalAction.h"

namespace render
{
	/**
	*	轨迹运动
	*/
	class TrackAction : public IntervalAction
	{
	public:
		TrackAction();
		virtual ~TrackAction();
	protected:
		virtual void updatePercent(float percent);
		// 获取位置
		virtual math::Vector3 getPosition(float curPercent);
	};
}
