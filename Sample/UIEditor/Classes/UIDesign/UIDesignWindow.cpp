#include "UIDesignWindow.h"
#include "UIDesignView.h"
#include "UIDesignPopMenu.h"

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

	this->addTouchFunc(render::TouchType::ENDED, [this](const math::Vector2& touchPoint, bool include) {
		if (m_pDesignPanel)
		{
			if (!m_pDesignPanel->containTouchPoint(touchPoint))
			{
				m_pDesignPanel->unselectTarget();
			}
		}
	});

	return true;
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
