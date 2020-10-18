#include "DesignPanel.h"

ue::DesignPanel::DesignPanel()
{
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

void ue::DesignPanel::setUIFile(const std::string& filepath)
{
	// ÒÆ³ý¾ÉµÄ
	m_pUIFile = CREATE_NODE(ui::CtrlFile);
	m_pUIFile->setFilePath(filepath);

	sys::CSSSize size;
	size.setWidth(sys::NumberType::Percent, 1);
	size.setHeight(sys::NumberType::Percent, 1);

	auto layoutItem = CREATE_OBJECT(ui::LayoutItem);
	layoutItem->setSize(size);
	layoutItem->setWidget(m_pUIFile);

	auto item = m_pLayout->findItemByName("viewScene");
	if (item)
	{
		ui::Layout* childLayout = item->as<ui::Layout>();
		if (childLayout)
		{
			childLayout->addItem(layoutItem);
		}

		if (item->getWidget())
		{
			item->getWidget()->addWidget(m_pUIFile);
		}
	}	
}

void ue::DesignPanel::initUI()
{
	this->setUIFile("Resource/Layout/main.xml");
}

void ue::DesignPanel::initEvent()
{
}

void ue::DesignPanel::initText()
{
}

