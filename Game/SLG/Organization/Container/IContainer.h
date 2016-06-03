#pragma once

#include "Item.h"

namespace slg
{
	class IContainer
	{
	public:
		virtual ~IContainer() {}
	public:
		// 添加物品
		virtual bool addItem(Item* item) = 0;
		// 移除物品
		virtual bool removeItem(int itemID) = 0;
		// 获取物品id
		virtual Item* getItem(int itemID) = 0;
		// 移除所有物品
		virtual void removeAllItems() = 0;
		// 物品总量
		virtual int count() = 0;
	};
}