#pragma once

#include "IGrid.h"

namespace slg
{
	// ����
	class Grid : public IGrid
	{
	public:
		Grid(int x, int y);
		Grid(int x, int y, int width, int height);
	public:
		virtual int getPositionX();
		// ����y��λ��
		virtual int getPositionY();
		// ���ӿ��
		virtual int getWidth();
		// ���Ӹ߶�
		virtual int getHeight();
		// Ŀ��
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