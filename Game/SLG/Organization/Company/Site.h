#pragma once

#include "Building.h"

namespace slg
{
	// 所在地
	class Site : public LocationProtocol
	{
	public:
		Site();
		virtual ~Site();
	public:
		// 建筑
		const Building* getBuilding();
		void setBuilding(const Building* building);
	protected:
	private:
		// 建筑
		Building _building;
	};
}