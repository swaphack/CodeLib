#pragma once

#include "common.h"

namespace render
{
	class TreeData;

	class MapCreator
	{
	public:
		MapCreator();
		~MapCreator();
	public:
		// 生成地形数据
		TerrianData* generateTerrian();
		// 生成树数据
		TreeData* generateTree();
	private:

	};
}