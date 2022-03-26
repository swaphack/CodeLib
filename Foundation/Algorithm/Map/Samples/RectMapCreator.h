#pragma once

#include "Map/Base/Module.h"
#include "Map/Base/MapAssets.h"
#include "Map/Creator/MapCreator.h"
#include "RectMap.h"

namespace alg
{
	namespace map
	{
		// ��ά��λ
		enum class RectModuleDirection
		{
			LEFT,
			RIGHT,
			UP,
			DOWN,
		};
		// ����ģ��
		class RectModule : public Module
		{
		public:
			RectModule();
			virtual ~RectModule();
		public:
			/**
			*	���÷�λ���
			*/
			void setSlot(RectModuleDirection eDirection, uint32_t slotIndex);
			/**
			*	��ȡ��λ���
			*/
			uint32_t getSlot(RectModuleDirection eDirection);
			/**
			*	������λ���
			*/
			void setLeftSlot(uint32_t slotIndex);
			/**
			*	�����ҷ�λ���
			*/
			void setRightSlot(uint32_t slotIndex);
			/**
			*	�����Ϸ�λ���
			*/
			void setUpSlot(uint32_t slotIndex);
			/**
			*	�����·�λ���
			*/
			void setDownSlot(uint32_t slotIndex);
		};
		class RectModuleCreate : public IMapObjectCreate
		{
		public:
			RectModuleCreate();
			virtual ~RectModuleCreate();
		public:
			virtual MapObject* create();
		};
		//////////////////////////////////////////////////////////////////////////
		class RectMapCreator : public MapCreator
		{
		public:
			RectMapCreator(int slotCount, uint32_t width, uint32_t height);
			virtual ~RectMapCreator();
		protected:
			/**
			*	��ȡָ������Ĳ����Ϣ
			*/
			bool getSlots(const MapCell* cell, RectModuleDirection dir, CombineSlots& slots) const;
		public:
			/**
			*	������Ӧλ�õĲ�
			*/
			virtual bool getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const;

			/**
			*	�ж�����λ�õĲ���Ƿ�ƥ��
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const;
		private:
			int _width = 0;
			int _height = 0;
		};
	}
}