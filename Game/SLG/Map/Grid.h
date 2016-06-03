#pragma once

namespace slg
{
	// 格子
	class Grid
	{
	public:
		// 默认长宽均为1，看做点
		Grid();
		Grid(int width, int height);
	public:
		// 获取格子宽度
		int getWidth();
		// 获取格子高度
		int getHeight();

		void setWidth(int width);
		void setHeight(int height);
		void setSize(int width, int height);
	private:
		int _width;
		int _height;
	};
}