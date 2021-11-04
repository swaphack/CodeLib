#include "Bin2D.h"
#include "BinPacking2D.h"
alg::Bin2D::Bin2D()
{
}

alg::Bin2D::~Bin2D()
{
}

void alg::Bin2D::setSize(int width, int height)
{
	_width = width;
	_height = height;
}

void alg::Bin2D::addItem(int id, int width, int height)
{
	Item item;
	item.id = id;
	item.width = width;
	item.height = height;

	_items.push_back(item);
}

void alg::Bin2D::setAutoRotate(bool rotated)
{
	_autoRotate = rotated;
}

bool alg::Bin2D::pack(std::vector<Item>& items)
{
	std::vector<BinPacking2D::Box> boxes;
	BinPacking2D binPack;
	for (auto& item : _items)
	{
		binPack.addItem(item.id, item.width, item.height);
	}
	binPack.sortItems(_autoRotate);
	if (!binPack.getHybridPackWay(_width, _height, BinPacking2D::PackingMethod::BFDH, boxes))
	{
		return false;
	}
	for (const auto& box : boxes)
	{
		for (const auto& item : box.items)
		{
			Item temp;
			temp.id = item.id;
			temp.rotate = item.rotate;
			temp.x = item.x;
			temp.y = item.y;
			temp.width = item.getWidth();
			temp.height = item.getHeight();
			items.push_back(temp);
		}
	}

	return items.size() > 0;
}
