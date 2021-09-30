#pragma once

#include "mathlib.h"

#include <vector>
#include <map>

namespace alg
{
	/**
	*	二维集装箱
	*/
	class Container2D
	{
	public:
		/**
		*	二维箱子
		*/
		struct Item
		{
			int boxID = 0;

			math::Size Size;
		};
	public:
		Container2D();
		~Container2D();
	public:
		/**
		*	设置大小
		*/
		void setSize(const math::Size& size);
		/**
		*	获取大小
		*/
		const math::Size& getSize() const;
	public:
		/**
		*	添加物品
		*/
		void addItem(const Container2D::Item& item);
		/**
		*	移除物品
		*/
		void removeItem(const Container2D::Item& item);
		/**
		*	移除所有物品
		*/
		void removeAllItems();
	public:
		/**
		*	获得陈列方法
		*/
		bool getLayoutWay(std::map<int, math::Vector2>& positions);
	private:
		/**
		*	位置
		*/
		math::Size _containerSize;
		/**
		*	物品
		*/
		std::map<int, Item> _items;
	};
}