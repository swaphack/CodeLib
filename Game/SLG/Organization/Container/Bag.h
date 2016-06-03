#pragma once

#include "IContainer.h"

#include <map>

namespace slg
{
	// 背包
	class Bag : public IContainer
	{
	public:
		Bag();
		virtual ~Bag();
	public:
		// 添加物品
		virtual bool addItem(Item* item);
		// 移除物品
		virtual bool removeItem(int itemID);
		// 获取物品id
		virtual Item* getItem(int itemID);
		// 移除所有物品
		virtual void removeAllItems();
		// 物品总量
		virtual int count();
	protected:
	private:
		std::map<int, Item*> _items;
	};
}