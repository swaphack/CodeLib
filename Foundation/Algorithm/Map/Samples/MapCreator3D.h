#pragma once

#include "Map/Base/MapModule.h"
#include "Map/Base/MapAssets.h"
#include "Array3DMap.h"

namespace alg
{
	// ��ά��λ
	enum class MapDirection3D
	{
		LEFT,
		RIGHT,
		Top,
		Bottom,
		FRONT,
		BACK,
	};
	// ��άģ��
	class MapModule3D : public MapModule
	{
	public:
		MapModule3D();
		virtual ~MapModule3D();
	public:
		/**
		*	���÷�λ���
		*/
		void setDirectionSlot(MapDirection3D eDirection, uint32_t slotIndex);
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

	// ��ά��ͼ����
	template<const uint32_t SlotCount, const uint32_t Width, const uint32_t Height, const uint32_t Depth, const uint32_t Count = Width * Height * Depth>
	class MapCreator3D : public WFCAlgorithm
	{
	public:
		MapCreator3D() {}
		virtual ~MapCreator3D() {}
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