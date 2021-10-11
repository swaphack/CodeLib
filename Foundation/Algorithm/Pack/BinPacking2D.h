#pragma once

#include "mathlib.h"

#include <vector>
#include <map>

namespace alg
{
	/**
	*	��άװ���㷨
	*/
	class BinPacking2D
	{
	public:
		// �����ʽ
		enum class PackingMethod
		{
			// Next - Fit Decreasing Height
			NFDH,
			// First - Fit Decreasing Height
			FFDH,
			// Best - Fit Decreasing Height
			BFDH,
		};
	public:
		/**
		*	��Ʒ��Ϣ
		*/
		struct Item
		{
			// ��Ʒ���
			int32_t id = 0;
			// ���
			int32_t width = 0;
			// ����
			int32_t height = 0;
			// xλ��
			int32_t x = 0;
			// yλ��
			uint32_t y = 0;
			// �������ӱ��
			int32_t box = -1;
			// �Ƿ���ת
			bool rotate = false;

			bool operator==(const Item& item)
			{
				return id == item.id;
			}

			bool operator!=(const Item& item)
			{
				return id != item.id;
			}

			// ���
			int32_t getMagnitude() const 
			{ 
				return width * height; 
			}
			// ���
			int32_t getWidth() const
			{
				return rotate ? height : width;
			}
			// �߶�
			int32_t getHeight() const
			{
				return rotate ? width : height;
			}
			// ����
			void reset()
			{
				box = -1;
				x = 0;
				y = 0;
			}
		};
		/**
		*	������Ϣ
		*/
		struct Box
		{
			// ���ӱ��
			int32_t id = 0;
			// ���
			int32_t width = 0;
			// �߶�
			int32_t height = 0;
			// ƫ��λ��x
			int32_t offsetX = 0;
			// ƫ��λ��y
			int32_t offsetY = 0;
			// ����
			std::vector<Item> items;
			// �Ƿ��������Ʒ
			bool canAddItem(const Item& item)
			{
				return (offsetX + item.getWidth() <= width) && (item.getHeight() <= height);
			}
			// �����Ʒ
			void addItem(const Item& item)
			{
				Item temp = item;
				temp.box = id;
				temp.x = offsetX;
				offsetX += temp.getWidth();
				items.push_back(temp);
			}
			// �ϲ���������,��ֱ�������
			void combineRow(const Box& box)
			{
				offsetX = 0;

				for (const auto& item : box.items)
				{
					Item temp = item;
					temp.box = id;
					temp.y = offsetY;
					items.push_back(temp);
				}
				height += box.height;
				offsetY += box.height;
			}
			// �Ƴ�������Ʒ
			void removeAllItems()
			{
				for (size_t i = 0; i < items.size(); i++)
				{
					items[i].reset();
				}
				items.clear();
			}
		};
	public:
		BinPacking2D();
		~BinPacking2D();
	public:
		/**
		*	�����Ʒ
		*/
		void addItem(int32_t id, int32_t width, int32_t height);
		/**
		*	�Ƴ���Ʒ
		*/
		void removeItem(int32_t id);
		/**
		*	�Ƴ�������Ʒ
		*/
		void removeAllItems();
		/**
		*	����Ʒ����������������Ʒ���߶ȴӴ�С����
		*	�������ת������Ʒԭ�еĿ�ȸߴ���ת
		*/
		void sortItems(bool rotate);
	public:
		/**
		*	��ô����ʽ Shelf
		*	����Ʒ���ڶ��������, ÿ�����ӵĸ߶��ɵ�һ�����߶Ⱦ���
		*/
		bool getPackWay(int width, PackingMethod method, std::vector<Box>& boxes);
		/**
		*	��ô����ʽ Hybrid First-Fit
		*	����Ʒ���ڶ��������,��ʹ��FF�Կ�Ƚ������ϣ��ٶԷ����ĺ���ͨ���߶Ƚ�������
		*/
		bool getHybridPackWay(int width, int height, PackingMethod method, std::vector<Box>& boxes);
	protected:
		/**
		*	First - Fit Decreasing Height
		*/
		bool createPackWayWithFFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains);
		/**
		*	Next - Fit Decreasing Height
		*/
		bool createPackWayWithNFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains);
		/**
		*	Best - Fit Decreasing Height
		*/
		bool createPackWayWithBFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains);
	private:
		/**
		*	��Ʒ
		*/
		std::vector<Item> _items;
	};
}