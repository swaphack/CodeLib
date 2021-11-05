#include "UIDesignProperty.h"
#include "Panel/PanelEvent.h"
#include "UIProperty/import.h"

ue::UIDesignProperty::UIDesignProperty()
{
}

ue::UIDesignProperty::~UIDesignProperty()
{
	G_KEYBOARDMANAGER->removeTargetAllEvents(this);

	for (auto& item : m_mapWidgetPropertyProtocol)
	{
		delete item.second;
	}

	for (auto& item : m_mapUIFile)
	{
		delete item.second;
	}
}

bool ue::UIDesignProperty::init()
{
	if (!Panel::init())
	{
		return false;
	}

	m_mapWidgetPropertyProtocol[ELEMENT_NAME_WIDGET] = new UIPropertyWidget();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_LAYOUT] = new UIPropertyLayout();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_IMAGE] = new UIPropertyImage();
	//m_mapWidgetPropertyProtocol[ELEMENT_NAME_SCALE9_IMAGE] = new UIPropertyWidget();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_TEXT] = new UIPropertyText();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_BUTTON] = new UIPropertyButton();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_EDITTEXT] = new UIPropertyEditText();
	//m_mapWidgetPropertyProtocol[ELEMENT_NAME_FILE] = new UIPropertyWidget();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_SCROLLVIEW] = new UIPropertyScrollView();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_LISTVIEW] = new UIPropertyListView();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_TABLEVIEW] = new UIPropertyTableView();
	m_mapWidgetPropertyProtocol[ELEMENT_NAME_GRIDVIEW] = new UIPropertyGridView();

	G_PANELEVT->addEventListener(PANEL_SELECT_VIEW_WIDGET, this, [this](const sys::Event* evt) {
		if (evt)
		{
			auto pWidget = (ui::CtrlWidget*)evt->getUserData();
			this->loadWidget(pWidget);
		}
 	});


	return true;
}

void ue::UIDesignProperty::loadWidget(ui::CtrlWidget* pWidget)
{
	if (pWidget == nullptr || m_pListProperty == nullptr)
	{
		return;
	}

	std::string name = ui::UIProxy::getLayoutItemName(pWidget);
	if (name.empty())
	{
		return;
	}

	auto pUIProperty = getUIProperty(name);
	if (pUIProperty == nullptr)
	{
		return;
	}
	m_pTargetItem = pWidget;

	if (m_pCurUIProperty == pUIProperty)
	{
		m_pCurUIProperty->setTarget(m_pTargetItem);
		m_pCurUIProperty->readWidgetProperty();
		return;
	}

	m_pCurUIProperty = pUIProperty;

	auto pUIFile = getUIWidget(name);
	if (pUIFile == nullptr)
	{
		return;
	}

	if (m_pCurUIFile != pUIFile)
	{
		m_pCurUIFile = pUIFile;

		m_pListProperty->removeAllItems();
		m_pListProperty->addItem(m_pCurUIFile);
	}

	m_pCurUIProperty->initPropertyUI(m_pCurUIFile);
	m_pCurUIProperty->setTarget(m_pTargetItem);
	m_pCurUIProperty->readWidgetProperty();
}


void ue::UIDesignProperty::initUI()
{
	m_pRootWidget->findWidgetByName("property", m_pListProperty);
}

void ue::UIDesignProperty::initEvent()
{
	G_KEYBOARDMANAGER->addKeyboardFunc(this, this, [this](sys::BoardKey key, sys::ButtonStatus status){

		if (key == sys::BoardKey::KRETURN)
		{
			m_pCurUIProperty->writeWidgetProperty();
		}
	});
}

void ue::UIDesignProperty::initText()
{
}

ue::UIPropertyProtocol* ue::UIDesignProperty::getUIProperty(const std::string& name)
{
	auto it = m_mapWidgetPropertyProtocol.find(name);
	if (it == m_mapWidgetPropertyProtocol.end())
	{
		return nullptr;
	}
	return it->second;
}

ui::CtrlWidget* ue::UIDesignProperty::getUIWidget(const std::string& name)
{
	auto it = m_mapUIFile.find(name);
	if (it == m_mapUIFile.end())
	{
		auto pWidgetProperty = ui::UIProxy::getInstance()->createWidgetProperty(name);
		if (pWidgetProperty == nullptr)
		{
			return nullptr;
		}
		pWidgetProperty->retain();
		m_mapUIFile[name] = pWidgetProperty;
		return pWidgetProperty;
	}
	return it->second;
}
