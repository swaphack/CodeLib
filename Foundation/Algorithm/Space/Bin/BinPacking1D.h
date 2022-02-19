#pragma once

#include "mathlib.h"

#include <vector>
#include <map>

namespace alg
{
	namespace space
	{
		/**
		*	一维装箱算法
		*/
		class BinPacking1D
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
				// 长度
				int32_t length = 0;
				// 位置
				int32_t x = 0;
				// 所属箱子编号
				int32_t box = -1;

				bool operator==(const Item& item)
				{
					return id == item.id;
				}

				bool operator!=(const Item& item)
				{
					return id != item.id;
				}

				// 重置
				void reset()
				{
					box = -1;
					x = 0;
				}
			};
			/**
			*	箱子信息
			*/
			struct Box
			{
				// 箱子编号
				int32_t id = 0;
				// 长度
				int32_t length = 0;
				// 偏移位置
				int32_t offset = 0;
				// 物体
				std::vector<Item> items;

				// 剩余空间
				int32_t remain() const
				{
					return length - offset;
				}

				// 是否能添加物品
				bool canAddItem(const Item& item)
				{
					return item.length + offset <= length;
				}
				// 添加物品
				void addItem(const Item& item)
				{
					Item temp = item;
					temp.box = id;
					temp.x = offset;
					offset += temp.length;
					items.push_back(temp);
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
			BinPacking1D();
			~BinPacking1D();
		public:
			/**
			*	添加物品
			*/
			void addItem(int32_t id, int32_t length);
			/**
			*	移除物品
			*/
			void removeItem(int32_t id);
			/**
			*	移除所有物品
			*/
			void removeAllItems();
			/**
			*	对物品进行排序，让所有物品按长度从大到小排序
			*/
			void sortItems();
		public:
			/**
			*	获得装箱方法
			*/
			bool getPackWay(int length, PackingMethod method, std::vector<Box>& boxes);
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
}