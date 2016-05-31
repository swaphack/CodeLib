#pragma once

#include "IGrid.h"

namespace slg
{
	// 格子
	class Grid : public IGrid
	{
	public:
		Grid(int x, int y);
		Grid(int x, int y, int width, int height);
	public:
		virtual int getPositionX();
		// 格子y轴位置
		virtual int getPositionY();
		// 格子宽度
		virtual int getWidth();
		// 格子高度
		virtual int getHeight();
		// 目标
		virtual Target* getTarget();

		void setPositionX(int x);
		void setPositionY(int y);
		void setPosition(int x, int y);

		void setWidth(int width);
		void setHeight(int height);
		void setSize(int width, int height);

		void setTarget(Target* target);
	protected:
	private:
		int _x;
		int _y;
		int _width;
		int _height;
	};
}