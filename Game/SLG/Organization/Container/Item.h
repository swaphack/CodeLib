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
		// ��ȡ��Ʒid
		int getItemID();
		// ������Ʒid
		void setItemID(int itemID);
		// ��ȡ��Ʒ����
		int getItemType();
		// ������Ʒ����
		void setItemType(int itemType);
	private:
		// ��Ʒid
		int _itemID;
		// ��Ʒ����
		int _itemType;
	};
}