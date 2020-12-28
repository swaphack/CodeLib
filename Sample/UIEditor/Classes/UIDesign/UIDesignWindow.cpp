#include "UIDesignWindow.h"
#include "UIDesignView.h"
#include "UIDesignPopMenu.h"

ue::UIDesignWindow::UIDesignWindow()
{
	this->setTouchEnable(true);
	this->setRootView(true);
}

ue::UIDesignWindow::~UIDesignWindow()
{

}

void ue::UIDesignWindow::initUI()
{
	m_pRootWidget->findWidgetByName("UIDesignView", m_pDesignPanel);
}

void ue::UIDesignWindow::initEvent()
{

}

void ue::UIDesignWindow::initText()
{
}

bool ue::UIDesignWindow::onTouchBegan(float x, float y, bool include)
{
	if (m_pDesignPanel)
	{
		if (!m_pDesignPanel->containTouchPoint(x, y))
		{
			m_pDesignPanel->unselectTarget();
		}
	}

	return false;
}

bool ue::UIDesignWindow::onTouchMoved(float x, float y, bool include)
{
	return false;
}

bool ue::UIDesignWindow::onTouchEnded(float x, float y, bool include)
{
	return false;
}
