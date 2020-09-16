#pragma once

#include "Map/Creator/MapModule.h"
#include "Map/Creator/MapCreator.h"

namespace alg
{
	// ��ά��λ
	enum class Map2DDirection
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};
	// ��ά���
	class MapModule2D : public MapModule
	{
	public:
		MapModule2D();
		virtual ~MapModule2D();
	public:
		/**
		*	���÷�λ���
		*/
		void setDirectionSlot(Map2DDirection eDirection, uint32_t slotIndex);
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

	// ��ά��ͼ����
	class MapCreator2D : public MapCreator
	{
	public:
		MapCreator2D();
		virtual ~MapCreator2D();
	public:
		/**
		*	���õ�ͼ��С
		*/
		void setMapSize(uint32_t width, uint32_t height);
		/**
		*	���õ�ͼ���
		*/
		uint32_t getWidth() const;
		/**
		*	���õ�ͼ�߶�
		*/
		uint32_t getHeight() const;
	public:
		/**
		*	���ɵ�ͼ
		*/
		//void create(Map& map);
	private:
		// ��ͼ���
		uint32_t _mapWidth = 0;
		// ��ͼ�߶�
		uint32_t _mapHeight = 0;
	};
}