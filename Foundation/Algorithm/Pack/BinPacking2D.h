#pragma once

#include "mathlib.h"

#include <vector>
#include <map>

namespace alg
{
	/**
	*	二维装箱算法
	*/
	class BinPacking2D
	{
	public:
		// 打包方式
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
		*	物品信息
		*/
		struct Item
		{
			// 物品编号
			int32_t id = 0;
			// 宽度
			int32_t width = 0;
			// 长度
			int32_t height = 0;
			// x位置
			int32_t x = 0;
			// y位置
			uint32_t y = 0;
			// 所属箱子编号
			int32_t box = -1;
			// 是否旋转
			bool rotate = false;

			bool operator==(const Item& item)
			{
				return id == item.id;
			}

			bool operator!=(const Item& item)
			{
				return id != item.id;
			}

			// 面积
			int32_t getMagnitude() const 
			{ 
				return width * height; 
			}
			// 宽度
			int32_t getWidth() const
			{
				return rotate ? height : width;
			}
			// 高度
			int32_t getHeight() const
			{
				return rotate ? width : height;
			}
			// 重置
			void reset()
			{
				box = -1;
				x = 0;
				y = 0;
			}
		};
		/**
		*	箱子信息
		*/
		struct Box
		{
			// 箱子编号
			int32_t id = 0;
			// 宽度
			int32_t width = 0;
			// 高度
			int32_t height = 0;
			// 偏移位置x
			int32_t offsetX = 0;
			// 偏移位置y
			int32_t offsetY = 0;
			// 物体
			std::vector<Item> items;
			// 是否能添加物品
			bool canAddItem(const Item& item)
			{
				return (offsetX + item.getWidth() <= width) && (item.getHeight() <= height);
			}
			// 添加物品
			void addItem(const Item& item)
			{
				Item temp = item;
				temp.box = id;
				temp.x = offsetX;
				offsetX += temp.getWidth();
				items.push_back(temp);
			}
			// 合并两个箱子,垂直方向叠加
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
			// 移除所有物品
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
		*	添加物品
		*/
		void addItem(int32_t id, int32_t width, int32_t height);
		/**
		*	移除物品
		*/
		void removeItem(int32_t id);
		/**
		*	移除所有物品
		*/
		void removeAllItems();
		/**
		*	对物品进行排序，让所有物品按高度从大到小排序
		*	如果有旋转，且物品原有的宽比高大，旋转
		*/
		void sortItems(bool rotate);
	public:
		/**
		*	获得打包方式 Shelf
		*	将物品放在多个箱子里, 每个箱子的高度由第一个最大高度决定
		*/
		bool getPackWay(int width, PackingMethod method, std::vector<Box>& boxes);
		/**
		*	获得打包方式 Hybrid First-Fit
		*	将物品放在多个箱子里,先使用FF对宽度进行整合，再对分类后的盒子通过高度进行整合
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
		*	物品
		*/
		std::vector<Item> _items;
	};
}