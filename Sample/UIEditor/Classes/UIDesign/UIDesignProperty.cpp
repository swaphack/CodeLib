#include "UIDesignProperty.h"
#include "Panel/PanelEvent.h"
#include "UIProperty/import.h"

ue::UIDesignProperty::UIDesignProperty()
{
}

ue::UIDesignProperty::~UIDesignProperty()
{
	G_KEYBOARDMANAGER->removeTargetAllEvents(this);
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

	auto it = m_mapWidgetPropertyProtocol.find(name);
	if (it == m_mapWidgetPropertyProtocol.end())
	{
		return;
	}

	auto pHelper = it->second;
	if (pHelper == nullptr)
	{
		return;
	}

	if (m_pCurUIProperty == pHelper)
	{
		m_pCurUIProperty->setTarget(m_pTargetItem);
		m_pCurUIProperty->readWidgetProperty();
		return;
	}

	m_pCurUIProperty = pHelper;

	auto pUIFile = ui::UIProxy::getInstance()->createWidgetProperty(name);
	if (pUIFile == nullptr)
	{
		return;
	}

	m_pUIFile = pUIFile;

	m_pListProperty->removeAllItems();
	m_pListProperty->addItem(m_pUIFile);

	m_pTargetItem = pWidget;

	m_pCurUIProperty->initPropertyUI(m_pUIFile);
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
