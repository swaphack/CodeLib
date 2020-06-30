#pragma once

#include "IntervalAction.h"

namespace render
{
	/**
	*	�켣�˶�
	*/
	class TrackAction : public IntervalAction
	{
	public:
		TrackAction();
		virtual ~TrackAction();
	protected:
		virtual void updatePercent(float percent);
		// ��ȡλ��
		virtual math::Vector3 getPosition(float curPercent);
	};
}
