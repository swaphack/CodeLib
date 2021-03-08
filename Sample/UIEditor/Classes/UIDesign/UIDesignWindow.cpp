#include "UIDesignWindow.h"
#include "UIDesignView.h"

ue::UIDesignWindow::UIDesignWindow()
{
	this->setTouchEnabled(true);
	this->setRootView(true);
}

ue::UIDesignWindow::~UIDesignWindow()
{

}

bool ue::UIDesignWindow::init()
{
	if (!Panel::init())
		return false;
	return true;
}

void ue::UIDesignWindow::initUI()
{
	m_pRootWidget->findWidgetByName("DesignView", m_pDesignPanel);
}

void ue::UIDesignWindow::initEvent()
{

}

void ue::UIDesignWindow::initText()
{
}
