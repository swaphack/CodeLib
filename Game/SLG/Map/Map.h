#pragma once

#include <vector>

#include "Grid.h"

namespace slg
{
	// ��ͼ
	class IMap
	{
	public:
		virtual ~IMap(){}
	public:
		// ��ͼ���
		virtual int getWidth() = 0;
		// ��ͼ�߶�
		virtual int getHeight() = 0;
		// ��ȡָ��λ�õĸ���
		virtual const Grid* getGridByPosition(int x, int y) = 0;
		// ��ȡռ��ָ������ĸ���
		virtual const Grid* getGridByContainsPosition(int x, int y) = 0;
		// ����һ������㵽�յ��·��
		virtual std::vector<Grid*> findWay(int srcX, int srcY, int destX, int destY) = 0;
		// �ж��Ƿ��ܷ���һ������
		virtual bool canPut(int x, int y, int width, int height) = 0;
	};

	class Map : public IMap
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
		virtual void addGrid(Grid* grid);
		// �Ƴ�����
		virtual void removeGrid(Grid* grid);
		// �Ƴ����и���
		virtual void removeAllGrids();
	protected:
	private:
		int _width;
		int _height;
		Grid** _grids;
	};
}