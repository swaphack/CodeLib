#pragma once

#include "Building.h"

namespace slg
{
	// ���ڵ�
	class Site : public LocationProtocol
	{
	public:
		Site();
		virtual ~Site();
	public:
		// ����
		const Building* getBuilding();
		void setBuilding(const Building* building);
	protected:
	private:
		// ����
		Building _building;
	};
}