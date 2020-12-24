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
			std::string filepath = (char*)evt->getUserData();
			if (filepath.empty()) return;

			int index = filepath.find_last_of(".xml");
			if (index == filepath.size() - 1)
			{
				this->setDesignFile(filepath);
			}
		}
	});
	G_PANELEVT->addEventListener(PANEL_SAVE_FILE, this, [this](const sys::Event* evt) {
		if (evt)
		{
			saveFile();
		}
	});


	G_KEYBOARDMANAGER->addKeyboardFunc(this, this, [this](Node* object, sys::BoardKey key, sys::ButtonStatus status) {
		if (!G_KEYCHAR->isControlEnabled())
		{
			return;
		}

		if (status == sys::ButtonStatus::BUTTON_DOWN)
		{
			if (key == sys::BoardKey::KS) saveFile();
			else if (key == sys::BoardKey::KR) reloadFile();
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

ui::CtrlWidget* ue::DesignPanel::getSelectedTarget() const
{
	return m_pSelectedTarget;
}

void ue::DesignPanel::setDesignFile(const std::string& filepath)
{
	if (m_pViewScene == nullptr)
	{
		return;
	}

	m_pSelectedTarget = nullptr;
	G_PANELEVT->setSelectNode(m_pSelectedTarget);

	m_strFileName = filepath;

	m_pViewScene->removeAllWidgets();

	/*filepath = "Resource/Layout/main.xml";*/
	m_pUIFile = createUIFile(filepath);
	if (m_pUIFile)
	{
		m_pViewScene->addWidget(m_pUIFile);
		m_pUIFile->refreshLayout();
	}
}

void ue::DesignPanel::initUI()
{
	m_pRootWidget->findWidgetByName("viewScene", m_pViewScene);
}

void ue::DesignPanel::initEvent()
{

}

void ue::DesignPanel::initText()
{
}

bool ue::DesignPanel::onTouchBegan(float x, float y, bool include)
{
	if (m_pUIFile == nullptr)
	{
		return true;
	}
	ui::CtrlFile* pFile = m_pUIFile->as<ui::CtrlFile>();
	if (pFile)
	{
		touchFrontWidget(pFile, x, y);
	}

	G_PANELEVT->setSelectNode(m_pSelectedTarget);

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

bool ue::DesignPanel::touchFrontWidget(ui::CtrlWidget* widget, float x, float y)
{
	if (widget == nullptr)
	{
		return false;
	}

	bool contain = false;
	const auto& vecWidgets = widget->getAllWidgets();
	int nChildCount = vecWidgets.size();
	if (nChildCount > 0)
	{
		for (int i = nChildCount - 1; i >= 0; i--)
		{
			if (touchFrontWidget(vecWidgets[i], x, y))
			{
				contain = true;
				return true;
			}
		}
	}

	if (!contain)
	{
		if (!widget->containTouchPoint(x, y))
		{
			return false;
		}
		if (m_pSelectedTarget == nullptr)
		{
			m_pSelectedTarget = widget;
			widget->setBoxWidth(1.0f);
			widget->setBoxColor(phy::Color4B(255, 255, 255, 255));
			widget->setBoxVisible(true);
		}
		else
		{
			if (m_pSelectedTarget == widget)
			{
				m_pSelectedTarget->setBoxVisible(false);
				m_pSelectedTarget = nullptr;
			}
			else
			{
				m_pSelectedTarget->setBoxVisible(false);
				m_pSelectedTarget = widget;
				m_pSelectedTarget->setBoxVisible(true);
			}
		}
	}

	return true;
}

void ue::DesignPanel::saveFile()
{
	auto pFile = m_pUIFile->as<ui::CtrlFile>();
	if (pFile)
	{
		pFile->save();
	}
}

void ue::DesignPanel::reloadFile()
{
	this->setDesignFile(m_strFileName);
}

