#include "Layout.h"

using namespace ui;

Layout::Layout()
{
}

Layout::~Layout()
{
	this->removeAllItems();
}

void Layout::addItem(LayoutItem* item)
{
	ASSERT(item != nullptr);
	
	SAFE_RETAIN(item);
	_items.push_back(item);
}

void Layout::removeItem(LayoutItem* item)
{
	ASSERT(item != nullptr);

	for (int i = 0; i < _items.size(); i++)
	{
		if (_items[i] == item)
		{
			_items.erase(_items.begin() + i);
			SAFE_RELEASE(item);
			break;
		}
	}
}

void Layout::removeAllItems()
{
	std::vector<LayoutItem*>::iterator iter = _items.begin();

	while (iter != _items.end())
	{
		SAFE_RELEASE((*iter));
		iter++;
	}

	_items.clear();
	
}

const std::vector<LayoutItem*>& Layout::getAllItems() const
{
	return _items;
}

LayoutItem* ui::Layout::findItemByName(const std::string& name) const
{
	if (this->getName() == name)
	{
		return (LayoutItem*)this;
	}

	for (auto item : _items)
	{
		if (item->getName() == name)
		{
			return item;
		}

		if (item->is<Layout>())
		{
			auto layoutItem = item->as<Layout>()->findItemByName(name);
			if (layoutItem != nullptr)
			{
				return layoutItem;
			}
		}
	}

	return nullptr;
}

LayoutItem* ui::Layout::getItem(int index) const
{
	if (index < 0 || index >= _items.size())
	{
		return nullptr;
	}
	return _items[index];
}

void Layout::resize(const math::Size& size)
{
	LayoutItem::resize(size);

	this->onLayoutSizeChanged(size);
}

bool Layout::copy(Layout* item)
{
	if (item == nullptr) 
	{
		return false;
	}

	setMargin(item->getMargin());

	std::vector<LayoutItem*>::const_iterator iter = item->getAllItems().begin();
	while (iter != item->getAllItems().end())
	{
		this->addItem(*iter);
		iter++;
	}

	return LayoutItem::copy(item);
}

void Layout::onLayoutSizeChanged(const math::Size& innerSize)
{
	const math::Size& parentSize = m_pWidget->getSize();

	int count = _items.size();
	for (int i = 0; i < count; i++)
	{
		LayoutItem* child = _items[i];
		if (child == nullptr)
		{
			continue;
		}
		
		child->resize(parentSize);
	}
}