#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	��������ϵ
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