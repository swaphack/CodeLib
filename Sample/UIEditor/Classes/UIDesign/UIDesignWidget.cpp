#include "UIDesignWidget.h"
#include "Panel/PanelEvent.h"

ue::UIDesignWidget::UIDesignWidget()
{
}

ue::UIDesignWidget::~UIDesignWidget()
{
}

bool ue::UIDesignWidget::init()
{
	if (!Panel::init())
	{
		return false;
	}
	return true;
}

void ue::UIDesignWidget::initUI()
{
	m_pRootWidget->findWidgetByName("container", _gridView);
	if (_gridView)
	{
		int count = _gridView->getItemCount();
		for (size_t i = 0; i < count; i++)
		{
			auto pItem = _gridView->getItemByIndex(i);
			if (pItem)
			{
				pItem->addTouchFunc(render::TouchType::BEGAN, [pItem](const math::Vector2& touchPoint) {
					G_PANELEVT->setSelectControlWidget(pItem);
				});
				/*
				pItem->addClickFunc([](ui::CtrlWidget* item) {
					G_PANELEVT->setSelectControlWidget(item);
				});
				*/
			}
		}
	}
}

void ue::UIDesignWidget::initEvent()
{
}

void ue::UIDesignWidget::initText()
{
}
