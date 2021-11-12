#include "UIDesignView.h"
#include "Panel/PanelEvent.h"

ue::UIDesignView::UIDesignView()
{
	G_PANELEVT->setViewPanel(this);
	this->setTouchEnabled(true);
}

ue::UIDesignView::~UIDesignView()
{
	G_PANELEVT->setViewPanel(nullptr);
}

bool ue::UIDesignView::init()
{
	if (!Panel::init())
	{
		return false;
	}
	G_PANELEVT->addEventListener(PANEL_SELECT_FILE, this, [this](const sys::Event* evt) {
		if (evt)
		{
			std::string filepath = (char*)evt->getUserData();
			if (filepath.empty()) return;

			int index = filepath.find_last_of(".xml");
			if (index == filepath.size() - 1)
			{
				this->setSelectFile(filepath);
			}
		}
	});
	G_PANELEVT->addEventListener(PANEL_SAVE_FILE, this, [this](const sys::Event* evt) {
		if (evt)
		{
			saveFile();
		}
	});

	G_PANELEVT->addEventListener(PANEL_SELECT_NODE_TREE, this, [this](const sys::Event* evt) {
		if (evt && evt->getUserData())
		{
			std::vector<int> vecIndex = *((std::vector<int>*)evt->getUserData());

			ui::CtrlWidget* pTarget = nullptr;
			render::Node* pTemp = m_pUIFile;
			for (size_t i = 0; i < vecIndex.size(); i++)
			{
				if (pTemp == nullptr) return;
				pTemp = pTemp->getChildAt(vecIndex[i]);
			}

			if (pTemp)
			{
				this->setSelectTarget(dynamic_cast<ui::CtrlWidget*>(pTemp));
			}
		}
	});


	G_KEYBOARDMANAGER->addKeyboardFunc(this, this, [this](sys::BoardKey key, sys::ButtonStatus status) {
		if (key == sys::BoardKey::KDELETE)
		{// É¾³ý
			if (m_pSelectedTarget != nullptr)
			{
				m_pSelectedTarget->removeFromParent();
				m_pSelectedTarget = nullptr;
				this->saveAndReload();
			}
			return;
		}


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

	this->addTouchFunc(render::TouchType::ENDED, [this](const math::Vector2& touchPoint) {
		if (m_pUIFile == nullptr) return;

		ui::CtrlFile* pFile = m_pUIFile->as<ui::CtrlFile>();
		if (pFile)
		{
			touchFrontWidget(pFile, touchPoint, [this](ui::CtrlWidget* widget) {
				setSelectTarget(widget);
			});
		}
	});


	return true;
}

void ue::UIDesignView::unselectTarget()
{
	if (m_pSelectedTarget != nullptr)
	{
		m_pSelectedTarget->setBoxVisible(false);
		m_pSelectedTarget = nullptr;
	}


	G_PANELEVT->setSelectNode(nullptr);
}

void ue::UIDesignView::selectTarget(ui::CtrlWidget* target)
{
	if (target == nullptr) return;

	m_pSelectedTarget = target;
	target->setBoxLineWidth(2.0f);
	target->setBoxColor(phy::Color4B(255, 0, 0, 255));
	target->setBoxVisible(true);

	G_PANELEVT->setSelectNode(target);
}

void ue::UIDesignView::setSelectTarget(ui::CtrlWidget* target)
{
	if (m_pSelectedTarget == nullptr)
	{
		selectTarget(target);
	}
	else
	{
		if (m_pSelectedTarget == target)
		{
			unselectTarget();
		}
		else
		{
			unselectTarget();
			selectTarget(target);
		}
	}
}

ui::CtrlWidget* ue::UIDesignView::getSelectedTarget() const
{
	return m_pSelectedTarget;
}

void ue::UIDesignView::setSelectFile(const std::string& filepath)
{
	if (m_pViewScene == nullptr)
	{
		return;
	}

	unselectTarget();

	m_strFileName = filepath;

	m_pViewScene->removeAllWidgets();

	/*filepath = "Resource/Layout/main.xml";*/
	m_pUIFile = createUIFile(filepath);
	if (m_pUIFile)
	{
		m_pViewScene->addWidget(m_pUIFile);
		G_PANELEVT->setRoot(m_pUIFile);
		m_pUIFile->refreshLayout();
	}
}

ui::CtrlWidget* ue::UIDesignView::getUIRoot() const
{
	return m_pUIFile;
}

void ue::UIDesignView::saveAndReload()
{
	this->saveFile();
	this->reloadFile();
}

void ue::UIDesignView::initUI()
{
	m_pRootWidget->findWidgetByName("viewScene", m_pViewScene);
}

void ue::UIDesignView::initEvent()
{

}

void ue::UIDesignView::initText()
{
}

void ue::UIDesignView::saveFile()
{
	if (m_pUIFile == nullptr)
	{
		return;
	}
		
	auto pFile = m_pUIFile->as<ui::CtrlFile>();
	if (pFile)
	{
		pFile->save();
	}
}

void ue::UIDesignView::reloadFile()
{
	this->setSelectFile(m_strFileName);
}

