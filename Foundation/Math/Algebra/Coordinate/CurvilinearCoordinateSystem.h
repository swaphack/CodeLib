#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	��������ϵ
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