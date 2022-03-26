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
		class MapCreator : public CreateMapProtocol
		{
		public:
			MapCreator(uint32_t slotCount, IMapObjectCreate* moduleCreate);
			virtual ~MapCreator();
		public:
			/**
			*	�����������
			*/
			void setSeed(uint32_t seed);
			/**
			*	�������
			*/
			uint32_t getSeed() const;
			/**
			*	��ͼ��Դ
			*/
			MapAssets* getMapAssets() const;
		public:
			/**
			*	������Ӧλ�õĲ�
			*/
			virtual bool getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const;
			/**
			*	�ж�����λ�õĲ���Ƿ�ƥ��
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const;
			/**
			*	��ȡģ������
			*/
			virtual const Module* getModule(uint32_t moduleID) const;
		public:			
			/**
			*	���õ�ͼ��Դ
			*/
			void setMapAssets(const MapAssets* assets);
			
			/**
			*	������ͼ
			*/
			bool create(MapProtocol* map, WFCAlgorithm* alg);

			/**
			*	ȡ�������λ�õ�ģ��
			*/
			virtual bool getFillPointModules(MapProtocol* map, uint32_t nIndex, std::vector<uint32_t>& modules) const;
		protected:
			// ��ͼ��Դ
			MapAssets* _mapAssets = nullptr;
			// �������
			uint32_t _seed = 0;
		};
	}
}