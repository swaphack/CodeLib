#pragma once

#include "IGrid.h"

namespace slg
{
	// 格子
	class Grid : public IGrid
	{
	public:
		// 默认长宽均为1，看做点
		Grid();
		Grid(int width, int height);
	public:
		// 格子宽度
		int getWidth();
		// 格子高度
		int getHeight();

		void setWidth(int width);
		void setHeight(int height);
		void setSize(int width, int height);
	private:
		int _width;
		int _height;
	};
}