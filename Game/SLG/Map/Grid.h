#pragma once

namespace slg
{
	// ����
	class Grid
	{
	public:
		// Ĭ�ϳ����Ϊ1��������
		Grid();
		Grid(int width, int height);
	public:
		// ��ȡ���ӿ��
		int getWidth();
		// ��ȡ���Ӹ߶�
		int getHeight();

		void setWidth(int width);
		void setHeight(int height);
		void setSize(int width, int height);
	private:
		int _width;
		int _height;
	};
}