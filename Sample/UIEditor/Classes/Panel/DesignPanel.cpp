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

	SAFE_RELEASE(m_pUIFile);

	m_pUIFile = CREATE_NODE(ui::CtrlFile);
	m_pUIFile->setFilePath(filepath);

	auto item = m_pLayout->findItemByName("viewScene");

	if (item)
	{
		if (item->getWidget())
		{
			item->getWidget()->addWidget(m_pUIFile);
		}

		ui::Layout* childLayout = item->as<ui::Layout>();
		if (childLayout && m_pUIFile->getLayout())
		{
			childLayout->addItem(m_pUIFile->getLayout());
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

