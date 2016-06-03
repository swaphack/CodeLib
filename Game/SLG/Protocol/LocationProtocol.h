#pragma once
#include "system.h"

namespace slg
{
	// 定位
	class LocationProtocol
	{
	public:
		LocationProtocol();
		virtual ~LocationProtocol();
	public:
		// x轴坐标
		int getPositionX();
		void setPositionX(int x);
		// y轴坐标
		int getPositionY();
		void setPositionY(int y);
		// z轴坐标
		int getPositionZ();
		void setPositionZ(int z);
	protected:
	private:
		// 位置
		sys::Vector _position;
	};
}