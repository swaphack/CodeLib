#pragma once

#include "TrackAction.h"

namespace render
{
	/**
	*	�����˶�
	*/
	class LinearAction : public TrackAction
	{
	public:
		LinearAction();
		virtual ~LinearAction();
	protected:
		virtual void updateInterval(float percent);
	};
}
