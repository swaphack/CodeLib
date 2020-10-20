#include "ViewLayout.h"
#include "DesignPanel.h"
#include "PopMenu.h"

ue::ViewLayout::ViewLayout()
{
	this->setTouchEnable(true);
	this->setRootView(true);
}

ue::ViewLayout::~ViewLayout()
{

}

void ue::ViewLayout::initUI()
{
	auto layoutItem = m_pLayout->findItemByName("DesignPanel");
	if (layoutItem->getWidget() != nullptr)
	{
		m_pDesignPanel = layoutItem->getWidget()->as<DesignPanel>();
	}
}

void ue::ViewLayout::initEvent()
{

}

void ue::ViewLayout::initText()
{
}

bool ue::ViewLayout::onTouchBegan(float x, float y, bool include)
{
	if (m_pDesignPanel)
	{
		if (!m_pDesignPanel->containTouchPoint(x, y))
		{
			m_pDesignPanel->unselectTarget();
		}
	}

	return false;
}

bool ue::ViewLayout::onTouchMoved(float x, float y, bool include)
{
	return false;
}

bool ue::ViewLayout::onTouchEnded(float x, float y, bool include)
{
	return false;
}
