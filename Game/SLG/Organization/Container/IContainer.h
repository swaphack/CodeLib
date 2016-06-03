#pragma once

#include "Item.h"

namespace slg
{
	class IContainer
	{
	public:
		virtual ~IContainer() {}
	public:
		// �����Ʒ
		virtual bool addItem(Item* item) = 0;
		// �Ƴ���Ʒ
		virtual bool removeItem(int itemID) = 0;
		// ��ȡ��Ʒid
		virtual Item* getItem(int itemID) = 0;
		// �Ƴ�������Ʒ
		virtual void removeAllItems() = 0;
		// ��Ʒ����
		virtual int count() = 0;
	};
}