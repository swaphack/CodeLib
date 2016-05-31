#pragma once

#include "../Data/Target.h"

namespace slg
{
	// 地图上的格子
	class  IGrid
	{
	public:
		virtual ~IGrid() {}
	public:
		// 格子x轴位置
		virtual int getPositionX() = 0;
		// 格子y轴位置
		virtual int getPositionY() = 0;
		// 格子宽度
		virtual int getWidth() = 0;
		// 格子高度
		virtual int getHeight() = 0;
		// 目标
		virtual Target* getTarget() = 0;
	};
}