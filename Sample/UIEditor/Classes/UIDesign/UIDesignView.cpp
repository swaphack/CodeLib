#include "UIDesignView.h"
#include "Panel/PanelEvent.h"
ue::UIDesignView::UIDesignView()
{
	this->setTouchEnabled(true);
}

ue::UIDesignView::~UIDesignView()
{
}

bool ue::UIDesignView::init()
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

	G_PANELEVT->addEventListener(PANEL_SELECT_NODE_TREE, this, [this](const sys::Event* evt) {
		if (evt && evt->getUserData())
		{
			std::vector<int> vecIndex = *((std::vector<int>*)evt->getUserData());

			ui::CtrlWidget* pTarget = nullptr;
			render::Node* pTemp = m_pUIFile;
			for (size_t i = 0; i < vecIndex.size(); i++)
			{
				if (pTemp == nullptr) return;
				pTemp = pTemp->getChildByIndex(vecIndex[i]);
			}

			if (pTemp)
			{
				this->setSelectTarget(dynamic_cast<ui::CtrlWidget*>(pTemp));
			}
		}
	});


	G_KEYBOARDMANAGER->addKeyboardFunc(this, this, [this](sys::BoardKey key, sys::ButtonStatus status) {
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

	this->addTouchFunc(render::TouchType::UP, [this](const math::Vector2& touchPoint, bool include) {
		if (m_pUIFile == nullptr) return;

		ui::CtrlFile* pFile = m_pUIFile->as<ui::CtrlFile>();
		if (pFile)
		{
			touchFrontWidget(pFile, touchPoint);
		}

		G_PANELEVT->setSelectNode(m_pSelectedTarget);
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
}

void ue::UIDesignView::selectTarget(ui::CtrlWidget* target)
{
	if (target == nullptr) return;

	m_pSelectedTarget = target;
	target->setBoxWidth(1.0f);
	target->setBoxColor(phy::Color4B(255, 255, 255, 255));
	target->setBoxVisible(true);
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

void ue::UIDesignView::setDesignFile(const std::string& filepath)
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
		G_PANELEVT->setRoot(m_pUIFile);
		m_pUIFile->refreshLayout();
	}
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

bool ue::UIDesignView::touchFrontWidget(ui::CtrlWidget* widget, const math::Vector2& touchPoint)
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
			if (touchFrontWidget(vecWidgets[i], touchPoint))
			{
				contain = true;
				return true;
			}
		}
	}

	if (!contain)
	{
		if (!widget->containTouchPoint(touchPoint))
		{
			return false;
		}
		setSelectTarget(widget);
	}

	return true;
}

void ue::UIDesignView::saveFile()
{
	auto pFile = m_pUIFile->as<ui::CtrlFile>();
	if (pFile)
	{
		pFile->save();
	}
}

void ue::UIDesignView::reloadFile()
{
	this->setDesignFile(m_strFileName);
}

