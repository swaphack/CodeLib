#pragma once

#include "Map/Base/Module.h"
#include "Map/Base/MapAssets.h"
#include "Map/Creator/MapCreator.h"
#include "CubeMap.h"

namespace alg
{
	namespace map
	{
		// ��ά��λ
		enum class CubeModuleDirection
		{
			LEFT,
			RIGHT,
			Top,
			Bottom,
			FRONT,
			BACK,
		};
		// ������ģ��
		class CubeMapModule : public Module
		{
		public:
			CubeMapModule();
			virtual ~CubeMapModule();
		public:
			/**
			*	���÷�λ���
			*/
			void setSlot(CubeModuleDirection eDirection, uint32_t slotIndex);
			/**
			*	��ȡ��λ���
			*/
			uint32_t getSlot(CubeModuleDirection eDirection);
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
			void setTopSlot(uint32_t slotIndex);
			/**
			*	�����·�λ���
			*/
			void setBottomSlot(uint32_t slotIndex);
			/**
			*	����ǰλ���
			*/
			void setFrontSlot(uint32_t slotIndex);
			/**
			*	���ú�λ���
			*/
			void setBackSlot(uint32_t slotIndex);
		};

		//////////////////////////////////////////////////////////////////////////

		// �������ͼ����
		template<const uint32_t SlotCount, const uint32_t Width, const uint32_t Height, const uint32_t Depth, const uint32_t PonitCount = Width * Height* Depth>
		class CubeMapCreator : public MapCreator<SlotCount, PonitCount, 1, CubeMapModule>
		{
		public:
			CubeMapCreator() {}
			virtual ~CubeMapCreator() {}
		public:
			/**
			*	������Ӧλ�õ�ģ��
			*/
			virtual bool getMatchModules(uint32_t nIndex, std::vector<uint32_t>& modules)
			{
				return false;
			}
			/**
			*	�ж�����λ�õĲ���Ƿ�ƥ��
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID)
			{
				return false;
			}
		public:
			/**
			*	���ɵ�ͼ
			*/
			bool create()
			{
				return false;
			}
		};
	}
}