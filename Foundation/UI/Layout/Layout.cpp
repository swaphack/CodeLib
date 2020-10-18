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
	m_vChildren.push_back(item);
}

void Layout::removeItem(LayoutItem* item)
{
	ASSERT(item != nullptr);

	for (int i = 0; i < m_vChildren.size(); i++)
	{
		if (m_vChildren[i] == item)
		{
			m_vChildren.erase(m_vChildren.begin() + i);
			SAFE_RELEASE(item);
			break;
		}
	}
}

void Layout::removeAllItems()
{
	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();

	while (iter != m_vChildren.end())
	{
		SAFE_RELEASE((*iter));
		iter++;
	}

	m_vChildren.clear();
	
}

const std::vector<LayoutItem*>& Layout::getChildren() const
{
	return m_vChildren;
}

LayoutItem* ui::Layout::findItemByName(const std::string& name) const
{
	if (this->getName() == name)
	{
		return (LayoutItem*)this;
	}

	for (auto item : m_vChildren)
	{
		if (item->getName() == name)
		{
			return item;
		}
		else if (item->is<Layout>())
		{
			return item->as<Layout>()->findItemByName(name);
		}
	}

	return nullptr;
}

void Layout::resize(const math::Size& size)
{
	if (this->getName() == "UIMain")
	{
		int a = 1;
	}
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

	std::vector<LayoutItem*>::const_iterator iter = item->getChildren().begin();
	while (iter != item->getChildren().end())
	{
		this->addItem(*iter);
		iter++;
	}

	return LayoutItem::copy(item);
}

void Layout::onLayoutSizeChanged(const math::Size& innerSize)
{
	const math::Size& parentSize = m_pWidget->getSize();

	int count = m_vChildren.size();
	for (int i = 0; i < count; i++)
	{
		LayoutItem* child = m_vChildren[i];
		if (child == nullptr)
		{
			continue;
		}
		
		child->resize(parentSize);
	}
}