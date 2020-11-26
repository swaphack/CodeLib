#include "DesignPanel.h"
#include "PanelEvent.h"
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
	G_PANELEVT->addEventListener(PANEL_SELECT_DESIGN_FILE, this, [this](const sys::Event* evt) {
		if (evt)
		{
			std::string filpath = (char*)evt->getUserData();
			this->setDesignFile(filpath);
		}
	});
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

void ue::DesignPanel::setDesignFile(const std::string& filepath)
{
	if (m_pViewScene == nullptr)
	{
		return;
	}

	m_pViewScene->removeAllItems();
	m_pViewScene->getWidget()->removeAllWidgets();

	/*filepath = "Resource/Layout/main.xml";*/
	m_pUIFile = createUIFile(filepath);
	if (m_pUIFile)
	{
		m_pViewScene->addItemWithWidget(m_pUIFile);
	}
}

void ue::DesignPanel::initUI()
{
	m_pLayout->findItemByName("viewScene", m_pViewScene);
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

