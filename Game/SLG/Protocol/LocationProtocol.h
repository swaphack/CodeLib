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
		// 获取位置坐标
		int getPositionX();
		int getPositionY();
		int getPositionY();
		sys::Vector getPosition();

		// 设置位置
		void setPositionX(int x);
		void setPositionY(int y);
		void setPositionZ(int z);
		void setPosition(float x, float y, float z = 0);
	protected:
	private:
		// 位置
		int _positionX;
		int _positionY;
		int _positionZ;
	};
}