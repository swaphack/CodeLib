#pragma once

#include "mathlib.h"
#include <vector>
#include <map>

namespace alg
{
	/**
	*	2d装箱
	*/
	class Bin2D
	{
	public:
		struct Item
		{
			int id = 0;
			int width = 0;
			int height = 0;
			int x = 0;
			int y = 0;
			bool rotate = false;
		};
	public:
		Bin2D();
		~Bin2D();
	public:
		/**
		*	设置大小
		*/
		void setSize(int width, int height);
		/**
		*	添加物品
		*/
		void addItem(int id, int width, int height);
	public:
		/**
		*	打包
		*/
		bool pack(std::vector<Item>& items);
	private:
		// 宽度
		int _width = 0;
		// 高度
		int _height = 0;
		// 物品
		std::vector<Item> _items;
	};
}