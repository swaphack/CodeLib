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
		/**
		*	��ͼ
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
			*	���ɵ�Ԫ
			*/
			N* createCell()
			{
				return _mapCell.create();

			}
			/**
			*	�Ƴ����е�Ԫ
			*/
			void removeAllCells()
			{
				_mapCell.removeAllObjects();
			}
			/**
			*	��ȡ��Ԫ����
			*/
			virtual uint32_t getCellCount() const
			{
				return _mapCell.getObjectCount();
			}
			/**
			*	��ȡ������
			*/
			const N* getCell(uint32_t nIndex) const
			{
				return _mapCell.getObject(nIndex);
			}

			/**
			*	��ȡ��Ԫ
			*/
			virtual MapCell* getCell(uint32_t nIndex)
			{
				return _mapCell.getObject(nIndex);
			}
		public:
			/**
			*	��ӹ�ϵ
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
					return mr->getMapObjectID();
				}
				return -1;
			}
			/**
			*	��ӹ�ϵ
			*/
			template<uint32_t Length>
			int32_t addRelation(uint32_t start, va_list ap)
			{
				R* mr = _mapRelations.create();
				if (mr)
				{
					mr->addRelation(Length, start, ap);
					return mr->getMapObjectID();
				}
				return -1;
			}

			/**
			*	��ӹ�ϵ
			*/
			template<uint32_t Length>
			int32_t addRelation(uint32_t index[])
			{
				R* mr = _mapRelations.create();
				if (mr)
				{
					mr->addRelation(Length, index);
					return mr->getMapObjectID();
				}
				return -1;
			}
			/**
			*	��ӹ�ϵ
			*/
			int32_t addRelation(const std::vector<uint32_t>& relation)
			{
				R* mr = _mapRelations.create();
				if (mr)
				{
					mr->addRelation(relation);
					return mr->getMapObjectID();
				}
				return -1;
			}
			/**
			*	�Ƴ����й�ϵ
			*/
			void removeAllRelations()
			{
				_mapRelations.removeAllObjects();
			}
			/**
			*	��ȡ��ϵ����
			*/
			uint32_t getRelationCount() const
			{
				return _mapRelations.getObjectCount();
			}
			/**
			*	��ȡ��ϵ
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
			// ��ͼ�����꼯
			MapObjects<N> _mapCell;
			// ��ͼ���ϵ��
			MapObjects<R> _mapRelations;
		};
	}
}