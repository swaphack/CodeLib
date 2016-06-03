#pragma once

#include "../macros.h"

namespace slg
{
	class Item : public Target
	{
	public:
		Item();
		virtual ~Item();
	public:
		// 获取物品id
		int getItemID();
		// 设置物品id
		void setItemID(int itemID);
		// 获取物品类型
		int getItemType();
		// 设置物品类型
		void setItemType(int itemType);
	private:
		// 物品id
		int _itemID;
		// 物品类型
		int _itemType;
	};
}