#pragma once

#include "IGrid.h"

namespace slg
{
	// ����
	class Grid : public IGrid
	{
	public:
		// Ĭ�ϳ����Ϊ1��������
		Grid();
		Grid(int width, int height);
	public:
		// ���ӿ��
		int getWidth();
		// ���Ӹ߶�
		int getHeight();

		void setWidth(int width);
		void setHeight(int height);
		void setSize(int width, int height);
	private:
		int _width;
		int _height;
	};
}