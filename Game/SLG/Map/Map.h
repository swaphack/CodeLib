#pragma once

#include <vector>

#include "Grid.h"

namespace slg
{
	class Map
	{
	public:
		Map(int width, int height);
		virtual ~Map();
	public:
		// 地图宽度
		virtual int getWidth();
		// 地图高度
		virtual int getHeight();
		// 获取指定位置的格子
		virtual const Grid* getGridByPosition(int x, int y);
		// 获取占用指定坐标的格子
		virtual const Grid* getGridByContainsPosition(int x, int y);
		// 查找一条从起点到终点的路径
		virtual std::vector<Grid*> findWay(int srcX, int srcY, int destX, int destY);
		// 判断是否能放下一个格子
		virtual bool canPut(int x, int y, int width, int height);
		// 添加格子
		virtual bool addGrid(Grid* grid);
		// 移除格子
		virtual bool removeGrid(Grid* grid);
		// 移除所有格子
		virtual void removeAllGrids();
	protected:
	private:
		int _width;
		int _height;
		Grid** _grids;
	};
}