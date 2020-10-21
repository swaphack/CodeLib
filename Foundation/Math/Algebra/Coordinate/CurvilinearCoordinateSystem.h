#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	ÇúÏß×ø±êÏµ
	*/
	template<const int Count>
	class CurvilinearCoordinateSystem : public CoordinateSystem<Count>
	{
	public:
		CurvilinearCoordinateSystem()
		{
		}
		virtual ~CurvilinearCoordinateSystem()
		{
		}
	public:
	protected:
	private:
	};
}