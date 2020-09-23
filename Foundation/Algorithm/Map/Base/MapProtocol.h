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
			*	��Ԫ����
			*/
			virtual uint32_t getCellCount() const
			{
				return 0;
			}
			/**
			*	�������ڽڵ�
			*/
			virtual bool findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const
			{
				return false;
			}
			/**
			*	�������ڵ�ľ���
			*/
			virtual float getDistance(uint32_t srcIndex, uint32_t toIndex) const
			{
				return -1;
			}
			/**
			*	��ȡ��Ԫ
			*/
			virtual MapCell* getCell(uint32_t nIndex)
			{
				return nullptr;
			}
		};
	}
}