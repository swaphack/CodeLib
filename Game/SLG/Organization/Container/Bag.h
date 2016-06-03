#pragma once

#include "IContainer.h"

#include <map>

namespace slg
{
	// ����
	class Bag : public IContainer
	{
	public:
		Bag();
		virtual ~Bag();
	public:
		// �����Ʒ
		virtual bool addItem(Item* item);
		// �Ƴ���Ʒ
		virtual bool removeItem(int itemID);
		// ��ȡ��Ʒid
		virtual Item* getItem(int itemID);
		// �Ƴ�������Ʒ
		virtual void removeAllItems();
		// ��Ʒ����
		virtual int count();
	protected:
	private:
		std::map<int, Item*> _items;
	};
}