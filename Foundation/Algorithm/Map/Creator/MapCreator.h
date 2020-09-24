#pragma once

#include <cstdint>

#include "Map/Base/Module.h"
#include "Map/Base/MapAssets.h"
#include "WFCAlgorithm.h"

namespace alg
{
	namespace map
	{
		class MapProtocol;

		/**
		*	���ɵ�ͼ�ӿ�
		*/
		class CreateMapProtocol
		{
		public:
			virtual ~CreateMapProtocol() {}
		public:
			/**
			*	ȡ�������λ�õ�ģ��
			*/
			virtual bool getFillPointModules(MapProtocol* map, uint32_t nIndex, std::vector<uint32_t>& modules) const = 0;
			/**
			*	�ж�����λ�õĲ���Ƿ�ƥ��
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const = 0;
			/**
			*	��ȡģ������
			*/
			virtual const Module* getModule(uint32_t moduleID) const = 0;
		};

		/**
		*	��ͼ����
		*/
		template<const uint32_t SlotCount, const uint32_t PonitCount, 
			const uint32_t RelationValue, typename M>
			class MapCreator : public CreateMapProtocol
		{
			static_assert(std::is_base_of<Module, M>::value, "M must inherit from Module");
		public:
			MapCreator() {}
			virtual ~MapCreator() {}
		public:
			/**
			*	�����������
			*/
			void setSeed(uint32_t seed)
			{
				_seed = seed;
			}
			/**
			*	�������
			*/
			uint32_t getSeed() const
			{
				return _seed;
			}

			MapAssets<M, SlotCount, RelationValue>* getMapAssets() const
			{
				return _mapAssets;
			}
		public:
			/**
			*	������Ӧλ�õĲ�
			*/
			virtual bool getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const
			{
				return false;
			}
			/**
			*	�ж�����λ�õĲ���Ƿ�ƥ��
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const
			{
				return false;
			}
			/**
			*	��ȡģ������
			*/
			virtual const Module* getModule(uint32_t moduleID) const
			{
				if (_mapAssets == nullptr)
				{
					return nullptr;
				}

				return _mapAssets->getModule(moduleID);
			}
		public:
			/**
			*	��ȡģ������
			*/
			M* getModule(uint32_t moduleID)
			{
				if (_mapAssets == nullptr)
				{
					return nullptr;
				}

				return (M*)_mapAssets->getModule(moduleID);
			}
			
			/**
			*	���ص�ͼ��Դ
			*/
			void setMapAssets(const MapAssets<M, SlotCount, RelationValue>* assets)
			{
				_mapAssets = (MapAssets<M, SlotCount, RelationValue>*)assets;
			}
			
			/**
			*	������ͼ
			*/
			bool create(MapProtocol* map, WFCAlgorithm* alg)
			{
				if (map == nullptr || alg == nullptr)
				{
					return false;
				}

				sys::Random::setSeed(_seed);

				MultiState states;
				for (const auto& item : _mapAssets->getAllModules())
				{
					states.add(item.first);
				}
				alg->initMap(map->getCellCount(), states);
				return alg->autoFillMap(map, this);
			}

			/**
			*	ȡ�������λ�õ�ģ��
			*/
			virtual bool getFillPointModules(MapProtocol* map, uint32_t nIndex, std::vector<uint32_t>& modules) const
			{
				if (map == nullptr)
				{
					return false;
				}
				if (nIndex >= map->getCellCount())
				{
					return false;
				}
				CombineSlots slots;
				if (!getMatchPointSlots(map, nIndex, slots))
				{
					return false;
				}

				if (!slots.empty())
				{
					return _mapAssets->findModule(slots, modules);
				}
				else
				{
					return true;
				}
			}
		protected:
			// ��ͼ��Դ
			MapAssets<M, SlotCount, RelationValue>* _mapAssets = nullptr;
			// �������
			uint32_t _seed = 0;
		};
	}
}