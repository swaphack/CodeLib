#include "BinPacking1D.h"
#include <algorithm>

alg::BinPacking1D::BinPacking1D()
{
}

alg::BinPacking1D::~BinPacking1D()
{
}

void alg::BinPacking1D::addItem(int32_t id, int32_t length)
{
	Item item;
	item.id = id;
	item.length = length;
	_items.push_back(item);
}

void alg::BinPacking1D::removeItem(int32_t id)
{
	for (size_t i = 0; i < _items.size(); i++)
	{
		if (_items[i].id == id)
		{
			_items.erase(_items.begin() + i);
			break;
		}
	}
}

void alg::BinPacking1D::removeAllItems()
{
	_items.clear();
}

void alg::BinPacking1D::sortItems()
{
	std::map<int32_t, int32_t> mapAreas;

	for (const auto& item : _items)
	{
		int32_t nLength = item.length;
		mapAreas[item.id] = nLength;
	}

	// 从大到小排序
	std::sort(_items.begin(), _items.end(), [mapAreas](const Item& a, const Item& b) {
		float aa = mapAreas.at(a.id);
		float bb = mapAreas.at(b.id);
		return aa > bb;
	});
}

bool alg::BinPacking1D::getPackWay(int length, PackingMethod method, std::vector<Box>& boxes)
{
	if (_items.size() == 0)
	{
		return false;
	}

	std::vector<Item> vecItems;
	for (const auto& item : _items)
	{
		vecItems.push_back(item);
	}

	do
	{
		Box box;
		box.id = boxes.size();
		box.length = length;

		if (vecItems.size() == 0)
		{
			return true;
		}
		if (!box.canAddItem(vecItems[0]))
		{
			return false;
		}

		std::vector<Item> remains;
		if (method == PackingMethod::FFDH)
		{
			if (!createPackWayWithFFDH(box, vecItems, remains))
			{
				return false;
			}
			vecItems = remains;
		}
		else if (method == PackingMethod::NFDH)
		{
			if (!createPackWayWithNFDH(box, vecItems, remains))
			{
				return false;
			}
		}		
		else if (method == PackingMethod::BFDH)
		{
			if (!createPackWayWithBFDH(box, vecItems, remains))
			{
				return false;
			}

			vecItems = remains;
		}

		boxes.push_back(box);
		// bfdh检查空余的空间是否能再添加箱子
		if (method == PackingMethod::BFDH)
		{
			for (auto& box : boxes)
			{
				createPackWayWithBFDH(box, vecItems, remains);
				vecItems = remains;
			}
		}
	} while (true);

	return true;
}

bool alg::BinPacking1D::createPackWayWithFFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains)
{
	remains = items;
	for (auto& item : items)
	{
		if (box.canAddItem(item))
		{
			box.addItem(item);
			auto it = std::find(remains.begin(), remains.end(), item);
			if (it != remains.end())
			{
				remains.erase(it);
			}
		}
	}
	return true;
}

bool alg::BinPacking1D::createPackWayWithNFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains)
{
	remains = items;
	for (auto& item : items)
	{
		if (box.canAddItem(item))
		{
			box.addItem(item);
			auto it = std::find(remains.begin(), remains.end(), item);
			if (it != remains.end())
			{
				remains.erase(it);
			}
		}
		else
		{
			break;
		}
	}
	return true;
}

bool alg::BinPacking1D::createPackWayWithBFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains)
{
	remains = items;
	for (auto& item : items)
	{
		if (box.canAddItem(item))
		{
			box.addItem(item);
			auto it = std::find(remains.begin(), remains.end(), item);
			if (it != remains.end())
			{
				remains.erase(it);
			}
		}
		else
		{
			break;
		}
	}
	return true;
}
