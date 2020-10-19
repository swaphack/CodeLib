#include "DesignPanel.h"

ue::DesignPanel::DesignPanel()
{
	this->setTouchEnable(true);
}

ue::DesignPanel::~DesignPanel()
{
}

bool ue::DesignPanel::init()
{
	if (!Panel::init())
	{
		return false;
	}
	return true;
}

void ue::DesignPanel::unselectTarget()
{
	if (m_pSelectedTarget != nullptr)
	{
		m_pSelectedTarget->setBoxVisible(false);
		m_pSelectedTarget = nullptr;
	}
}

ui::LayoutItem* ue::DesignPanel::getSelectedTarget() const
{
	return m_pSelectedTarget;
}

void ue::DesignPanel::initUI()
{
	auto item = m_pLayout->findItemByName("viewScene");
	if (item)
	{
		m_pUIFile = createUIFile("Resource/Layout/main.xml");
		if (m_pUIFile)
		{
			auto pWidget = m_pUIFile->getWidget();
			ui::Layout* childLayout = item->as<ui::Layout>();
			if (childLayout)
			{
				childLayout->addItem(m_pUIFile);
			}

			if (item->getWidget())
			{
				item->getWidget()->addWidget(pWidget);
			}
		}
	}
}

void ue::DesignPanel::initEvent()
{
}

void ue::DesignPanel::initText()
{
}

bool ue::DesignPanel::onTouchBegan(float x, float y, bool include)
{
	render::CtrlWidget* pFileWiget = m_pUIFile->getWidget();
	if (pFileWiget)
	{
		ui::CtrlFile* pFile = pFileWiget->as<ui::CtrlFile>();
		if (pFile)
		{
			touchFrontWidget(pFile->getLayout(), x, y);
		}
	}

	this->dispatchItem(m_pSelectedTarget);

	return true;
}

bool ue::DesignPanel::onTouchMoved(float x, float y, bool include)
{
	return true;
}

bool ue::DesignPanel::onTouchEnded(float x, float y, bool include)
{
	return true;
}

bool ue::DesignPanel::touchFrontWidget(ui::LayoutItem* layoutItem, float x, float y)
{
	if (layoutItem == nullptr)
	{
		return false;
	}

	bool contain = false;
	if (layoutItem->is<ui::Layout>())
	{
		auto layout = layoutItem->as<ui::Layout>();
		int nChildCount = layout->getAllItems().size();
		if (nChildCount > 0)
		{
			for (int i = nChildCount - 1; i >= 0; i--)
			{
				if (touchFrontWidget(layout->getItem(i), x, y))
				{
					contain = true;
					return true;
				}
			}
		}
	}

	if (!contain)
	{
		if (!layoutItem->containPoint(x, y))
		{
			return false;
		}
		if (m_pSelectedTarget == nullptr)
		{
			m_pSelectedTarget = layoutItem;
			layoutItem->setBoxVisible(true);
		}
		else
		{
			if (m_pSelectedTarget == layoutItem)
			{
				m_pSelectedTarget->setBoxVisible(false);
				m_pSelectedTarget = nullptr;
			}
			else
			{
				m_pSelectedTarget->setBoxVisible(false);
				m_pSelectedTarget = layoutItem;
				m_pSelectedTarget->setBoxVisible(true);
			}
		}
	}

	return true;
}

