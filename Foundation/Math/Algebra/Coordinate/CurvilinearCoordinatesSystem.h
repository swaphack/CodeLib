#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	ÇúÏß×ø±êÏµ
	*/
	template<const int Count>
	class CurvilinearCoordinatesSystem : public CoordinateSystem<Count>
	{
	public:
		CurvilinearCoordinatesSystem()
		{
		}
		virtual ~CurvilinearCoordinatesSystem()
		{
		}
	public:
	protected:
	private:
	};
}