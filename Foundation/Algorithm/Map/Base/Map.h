#pragma once

#include "MapObject.h"
#include "MapObjects.h"
#include "MapCell.h"
#include "MapRelation.h"

namespace alg
{
	class MapProtocol
	{
	public:
		MapProtocol() {}
		virtual ~MapProtocol() {}
	public:
		virtual uint32_t getCellCount() const
		{
			return 0;
		}
		/**
		*	查找相邻节点
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const
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
	};
	/**
	*	地图
	*/
	template<typename N, typename R>
	class Map : public MapObject, public MapProtocol
	{
		static_assert(std::is_base_of<MapCell, N>::value, "N must inherit from MapCell");
		static_assert(std::is_base_of<MapRelation, R>::value, "R must inherit from MapRelation");
	public:
		Map() {}
		virtual ~Map() {}
	public:
		/**
		*	生成单元
		*/
		N* createCell()
		{
			return _mapCell.create();

		}
		/**
		*	移除所有单元
		*/
		void removeAllCells()
		{
			_mapCell.removeAllObjects();
		}
		/**
		*	获取单元数量
		*/
		virtual uint32_t getCellCount() const
		{
			return _mapCell.getObjectCount();
		}
		/**
		*	获取点坐标
		*/
		const N* getCell(uint32_t nIndex) const
		{
			return _mapCell.getObject(nIndex);
		}
	public:
		/**
		*	添加关系
		*/
		template<uint32_t Length>
		int32_t addRelation(uint32_t start, ...)
		{
			R* mr = _mapRelations.create();
			if (mr)
			{
				va_list ap;
				va_start(ap, start);
				mr->addRelation(Length, start, ap);
				va_end(ap);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	添加关系
		*/
		template<uint32_t Length>
		int32_t addRelation(uint32_t start, va_list ap)
		{
			R* mr = _mapRelations.create();
			if (mr)
			{
				mr->addRelation(Length, start, ap);
				return mr->getObjectIndex();
			}
			return -1;
		}

		/**
		*	添加关系
		*/
		template<uint32_t Length>
		int32_t addRelation(uint32_t index[])
		{
			R* mr = _mapRelations.create();
			if (mr)
			{
				mr->addRelation(Length, index);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	添加关系
		*/
		int32_t addRelation(const std::vector<uint32_t>& relation)
		{
			R* mr = _mapRelations.create();
			if (mr)
			{
				mr->addRelation(relation);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	移除所有关系
		*/
		void removeAllRelations()
		{
			_mapRelations.removeAllObjects();
		}
		/**
		*	获取关系数量
		*/
		uint32_t getRelationCount() const
		{
			return _mapRelations.getObjectCount();
		}
		/**
		*	获取关系
		*/
		bool getRelation(uint32_t nIndex, std::vector<uint32_t>& indices) const
		{
			auto mp = _mapRelations.getObject(nIndex);
			if (mp == nullptr)
			{
				return false;
			}

			indices = mp->getAllRelations();

			return indices.size() > 0;
		}
	protected:
		// 地图点坐标集
		MapObjects<N> _mapCell;
		// 地图点关系集
		MapObjects<R> _mapRelations;
	};
}
