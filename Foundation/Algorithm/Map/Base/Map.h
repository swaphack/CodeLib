#pragma once

#include "MapProtocol.h"
#include "MapObject.h"
#include "MapObjects.h"
#include "MapCell.h"
#include "MapRelation.h"

namespace alg 
{
	namespace map 
	{
		class MapCellCreate : public IMapObjectCreate
		{
		public:
			virtual ~MapCellCreate();
		public:
			MapObject* create();
		};

		class MapRelationCreate : public IMapObjectCreate
		{
		public:
			virtual ~MapRelationCreate();
		public:
			MapObject* create();
		};

		/**
		*	地图
		*/
		class Map : public MapObject, public MapProtocol
		{
		public:
			Map();
			virtual ~Map();
		public:
			/**
			*	生成单元
			*/
			MapCell* createCell();
			/**
			*	生成单元
			*/
			template<class T, typename = std::enable_if<std::is_base_of<MapCell, T>::value, T>::type>
			T* createCell()
			{
				return dynamic_cast<T*>(_mapCell.create());
			}
			/**
			*	移除所有单元
			*/
			void removeAllCells();
			/**
			*	获取单元数量
			*/
			uint32_t getCellCount() const;
			/**
			*	获取点坐标
			*/
			const MapCell* getCell(uint32_t nIndex) const;

			/**
			*	获取单元
			*/
			MapCell* getCell(uint32_t nIndex);
		public:
			/**
			*	生成关系
			*/
			MapRelation* createRelation();
			/**
			*	添加关系
			*/
			int32_t addRelation(uint32_t length, uint32_t start, ...);
			/**
			*	添加关系
			*/
			int32_t addRelation(uint32_t length, uint32_t start, va_list ap);

			/**
			*	添加关系
			*/
			int32_t addRelation(uint32_t length, uint32_t index[]);
			/**
			*	添加关系
			*/
			int32_t addRelation(const std::vector<uint32_t>& relation);
			/**
			*	移除所有关系
			*/
			void removeAllRelations();
			/**
			*	获取关系数量
			*/
			uint32_t getRelationCount() const;
			/**
			*	获取单元
			*/
			MapRelation* getRelation(uint32_t nIndex) const;
			/**
			*	获取关系
			*/
			bool getRelation(uint32_t nIndex, std::vector<uint32_t>& indices) const;
		protected:
			// 地图点坐标集
			MapObjects _mapCell;
			// 地图点关系集
			MapObjects _mapRelations;
		};
	}
}