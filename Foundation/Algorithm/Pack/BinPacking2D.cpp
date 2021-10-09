#include "BinPacking2D.h"
#include <algorithm>

alg::BinPacking2D::BinPacking2D()
{
}

alg::BinPacking2D::~BinPacking2D()
{
}

void alg::BinPacking2D::addItem(int32_t id, int32_t width, int32_t height)
{
	Item item;
	item.id = id;
	item.width = width;
	item.height = height;
	_items.push_back(item);
}

void alg::BinPacking2D::removeItem(int32_t id)
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

void alg::BinPacking2D::removeAllItems()
{
	_items.clear();
}

void alg::BinPacking2D::sortItems(bool rotate)
{
	std::map<int32_t, int32_t> mapAreas;

	for (auto& item : _items)
	{
		if (rotate)
		{
			// 需要宽比高大
			if (item.height < item.width)
			{
				item.rotate = true;
			}
		}

		int32_t nArea = item.getHeight();
		mapAreas[item.id] = nArea;
	}

	std::sort(_items.begin(), _items.end(), [mapAreas](const Item& a, const Item& b) {
		float aa = mapAreas.at(a.id);
		float bb = mapAreas.at(b.id);
		return aa > bb;
	});
}

bool alg::BinPacking2D::getPackWay(int width, PackingMethod method, std::vector<Box>& boxes)
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
		box.width = width;

		if (vecItems.size() == 0)
		{
			return true;
		}
		if (box.height == 0)
		{
			box.height = vecItems[0].height;
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

bool alg::BinPacking2D::getHybridPackWay(int width, int height, PackingMethod method, std::vector<Box>& boxes)
{
	std::vector<Box> firstBoxes;
	if (!getPackWay(width, method, firstBoxes))
	{
		return false;
	}

	std::sort(firstBoxes.begin(), firstBoxes.end(), [](const Box& a, const Box& b) {
		return a.height > b.height;
	});

	std::map<int32_t, Box> mapBoxes;
	BinPacking2D binPack;
	for (const auto& box : firstBoxes)
	{
		mapBoxes[box.id] = firstBoxes[box.id];
		binPack.addItem(box.id, box.height, box.width);
	}
	std::vector<Box> secondBoxes;
	if (!binPack.getPackWay(height, method, secondBoxes))
	{
		return false;
	}

	std::map<int32_t, Box> finalBoxes;
	for (const auto& box : secondBoxes)
	{
		for (const auto& item : box.items)
		{
			auto it = finalBoxes.find(item.id);
			if (it == finalBoxes.end())
			{
				Box box;
				box.id = box.id;
				box.width = width;
				box.height = height;

				finalBoxes[item.id] = box;
			}
			finalBoxes[item.id].combine(mapBoxes[item.id]);
		}
	}

	for (const auto& box : finalBoxes)
	{
		boxes.push_back(box.second);
	}

	return true;
}

bool alg::BinPacking2D::createPackWayWithFFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains)
{
	remains = items;
	for (const auto& item : items)
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


bool alg::BinPacking2D::createPackWayWithNFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains)
{
	remains = items;
	for (const auto& item : items)
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

bool alg::BinPacking2D::createPackWayWithBFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains)
{
	remains = items;
	for (const auto& item : items)
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