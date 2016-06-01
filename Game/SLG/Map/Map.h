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
		// ��ͼ���
		virtual int getWidth();
		// ��ͼ�߶�
		virtual int getHeight();
		// ��ȡָ��λ�õĸ���
		virtual const Grid* getGridByPosition(int x, int y);
		// ��ȡռ��ָ������ĸ���
		virtual const Grid* getGridByContainsPosition(int x, int y);
		// ����һ������㵽�յ��·��
		virtual std::vector<Grid*> findWay(int srcX, int srcY, int destX, int destY);
		// �ж��Ƿ��ܷ���һ������
		virtual bool canPut(int x, int y, int width, int height);
		// ��Ӹ���
		virtual bool addGrid(Grid* grid);
		// �Ƴ�����
		virtual bool removeGrid(Grid* grid);
		// �Ƴ����и���
		virtual void removeAllGrids();
	protected:
	private:
		int _width;
		int _height;
		Grid** _grids;
	};
}