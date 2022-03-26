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
		*	��ͼ
		*/
		class Map : public MapObject, public MapProtocol
		{
		public:
			Map();
			virtual ~Map();
		public:
			/**
			*	���ɵ�Ԫ
			*/
			MapCell* createCell();
			/**
			*	���ɵ�Ԫ
			*/
			template<class T, typename = std::enable_if<std::is_base_of<MapCell, T>::value, T>::type>
			T* createCell()
			{
				return dynamic_cast<T*>(_mapCell.create());
			}
			/**
			*	�Ƴ����е�Ԫ
			*/
			void removeAllCells();
			/**
			*	��ȡ��Ԫ����
			*/
			uint32_t getCellCount() const;
			/**
			*	��ȡ������
			*/
			const MapCell* getCell(uint32_t nIndex) const;

			/**
			*	��ȡ��Ԫ
			*/
			MapCell* getCell(uint32_t nIndex);
		public:
			/**
			*	���ɹ�ϵ
			*/
			MapRelation* createRelation();
			/**
			*	��ӹ�ϵ
			*/
			int32_t addRelation(uint32_t length, uint32_t start, ...);
			/**
			*	��ӹ�ϵ
			*/
			int32_t addRelation(uint32_t length, uint32_t start, va_list ap);

			/**
			*	��ӹ�ϵ
			*/
			int32_t addRelation(uint32_t length, uint32_t index[]);
			/**
			*	��ӹ�ϵ
			*/
			int32_t addRelation(const std::vector<uint32_t>& relation);
			/**
			*	�Ƴ����й�ϵ
			*/
			void removeAllRelations();
			/**
			*	��ȡ��ϵ����
			*/
			uint32_t getRelationCount() const;
			/**
			*	��ȡ��Ԫ
			*/
			MapRelation* getRelation(uint32_t nIndex) const;
			/**
			*	��ȡ��ϵ
			*/
			bool getRelation(uint32_t nIndex, std::vector<uint32_t>& indices) const;
		protected:
			// ��ͼ�����꼯
			MapObjects _mapCell;
			// ��ͼ���ϵ��
			MapObjects _mapRelations;
		};
	}
}