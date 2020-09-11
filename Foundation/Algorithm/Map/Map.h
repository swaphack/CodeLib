#pragma once

#include "MapObject.h"
#include "MapObjects.h"

namespace alg
{
	/**
	*	地图上坐标点
	*/
	class MapPoint : public MapObject
	{
	public:
		MapPoint();
		virtual ~MapPoint();
	public:
		/**
		*	设置坐标
		*/
		void setPosition(const math::Vector3& pos);
		/**
		*	获取坐标
		*/
		const math::Vector3& getPosition() const;
	protected:
		math::Vector3 _position;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	地图关系网
	*/
	class MapRelation : public MapObject
	{
	public:
		MapRelation();
		virtual ~MapRelation();
	public:
		/**
		*	添加点索引
		*/
		void addMapIndex(uint32_t nLength, uint32_t startIndex, ...);
		/**
		*	添加点索引
		*/
		void addMapIndex(uint32_t nLength, uint32_t startIndex, va_list ap);
		/**
		*	添加点索引
		*/
		void addMapIndex(uint32_t mapIndex);
		/**
		*	移除点索引
		*/
		void removeMapIndex(uint32_t mapIndex);
		/**
		*	移除所有点索引
		*/
		void removeAllMapIndices();
		/**
		*	是否包含点索引
		*/
		bool containMapIndex(uint32_t mapIndex) const;
		/**
		*	获取关联索引
		*/
		const std::vector<uint32_t>& getMapIndices() const;
	public:
		/**
		*	索引数量
		*/
		uint32_t getMapIndexCount() const;
		/**
		*	获取点索引
		*/
		uint32_t getMapIndex(uint32_t index) const;
		/**
		*	获取索引
		*/
		int32_t getIndex(uint32_t mapIndex) const;
	public:

	protected:
		// 点索引
		std::vector<uint32_t> _mapIndices;
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	地图
	*/
	class Map
	{
	public:
		Map();
		virtual ~Map();
	public:
		/**
		*	添加坐标点
		*/
		int32_t addPoint(const math::Vector3& point);
		/**
		*	移除所有坐标点
		*/
		void removeAllPoints();
		/**
		*	获取点坐标数量
		*/
		uint32_t getPointCount() const;
		/**
		*	获取点坐标
		*/
		const math::Vector3* getPoint(uint32_t nIndex) const;
	public:
		/**
		*	添加关系
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<MapRelation, T>::value, T>::type>
		int32_t addRelation(uint32_t nLength, uint32_t start, ...)
		{
			T* mr = _mapRelations.create<T>();
			if (mr)
			{
				va_list ap;
				va_start(ap, start);
				mr->addMapIndex(nLength, start, ap);
				va_end(ap);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	添加关系
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<MapRelation, T>::value, T>::type>
		int32_t addRelation(uint32_t nLength, uint32_t start, va_list ap)
		{
			T* mr = _mapRelations.create<T>();
			if (mr)
			{
				mr->addMapIndex(nLength, start, ap);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	移除所有关系
		*/
		void removeAllRelations();
		/**
		*	获取关系数量
		*/
		uint32_t getRelationCount() const;
		/**
		*	获取关系
		*/
		bool getRelation(uint32_t nIndex, std::vector<uint32_t>& indices) const;
	public:
		/**
		*	查找相邻节点
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	protected:
		// 地图点坐标集
		MapObjects<MapPoint> _mapPoints;
		// 地图点关系集
		MapObjects<MapRelation> _mapRelations;
	};
}
