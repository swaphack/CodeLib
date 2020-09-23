#pragma once

#include <cstdint>
#include <vector>

namespace alg
{
	namespace map
	{
		class MapCell;

		class MapProtocol
		{
		public:
			MapProtocol() {}
			virtual ~MapProtocol() {}
		public:
			/**
			*	单元总数
			*/
			virtual uint32_t getCellCount() const
			{
				return 0;
			}
			/**
			*	查找相邻节点
			*/
			virtual bool findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const
			{
				return false;
			}
			/**
			*	计算两节点的距离
			*/
			virtual float getDistance(uint32_t srcIndex, uint32_t toIndex) const
			{
				return -1;
			}
			/**
			*	获取单元
			*/
			virtual MapCell* getCell(uint32_t nIndex)
			{
				return nullptr;
			}
		};
	}
}