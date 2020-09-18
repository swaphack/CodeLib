#pragma once

#include "Map/Base/MapModule.h"
#include "Map/Base/MapAssets.h"
#include "Array2DMap.h"

namespace alg
{
	// ��ά��λ
	enum class MapDirection2D
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};
	// ��άģ��
	class MapModule2D : public MapModule
	{
	public:
		MapModule2D();
		virtual ~MapModule2D();
	public:
		/**
		*	���÷�λ���
		*/
		void setDirectionSlot(MapDirection2D eDirection, uint32_t slotIndex);
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

	//////////////////////////////////////////////////////////////////////////

	/**
	*	��ά��ͼ����
	*/
	template<const uint32_t SlotCount, const uint32_t Width, const uint32_t Height, const uint32_t Count = Width * Height>
	class MapCreator2D : public WFCAlgorithm
	{
	public:
		MapCreator2D() {}
		virtual ~MapCreator2D() {}
	public:
	};
}