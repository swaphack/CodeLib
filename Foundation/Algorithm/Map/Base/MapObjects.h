#pragma once

#include "MapObject.h"
#include <vector>

namespace alg
{
	namespace map
	{
		//地图对象创建接口
		class IMapObjectCreate
		{
		public:
			virtual~IMapObjectCreate() {}
		public:
			virtual MapObject* create() = 0;
		};

		/**
		*	地图单一类型对象管理
		*/
		class MapObjects : public MapObject
		{
		public:
			MapObjects();
			virtual ~MapObjects();
		public:
			/**
			*	设置创建接口, IMapObjectCreate都要new出来
			*/
			void setCreateFunc(IMapObjectCreate* func);
			/**
			*	移除所有对象
			*/
			void removeAllObjects();
			/**
			*	获取地图对象
			*/
			uint32_t getObjectCount() const;
			/**
			*	是否为空
			*/
			bool isEmpty() const;
			/**
			*	获取对象
			*/
			const MapObject* getObject(uint32_t nIndex) const;
			/**
			*	获取对象
			*/
			MapObject* getObject(uint32_t nIndex);
			/**
			*	创建对象
			*/
			MapObject* create();
			/**
			*	递增id
			*/
			void increaseID();
			/**
			*	获取所有对象
			*/
			const std::map<uint32_t, MapObject*>& getAllObjects() const;
		protected:
			// 索引
			uint32_t _mapObjectID = 0;
			// 地图点
			std::map<uint32_t, MapObject*> _mapObjects;
			// 创建接口
			IMapObjectCreate* _createObjectFunc = nullptr;
		};
	}
}