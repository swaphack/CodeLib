#include "Panel.h"
#include "PanelEvent.h"

ue::Panel::Panel()
{
}

ue::Panel::~Panel()
{
	G_KEYBOARDMANAGER->removeTargetAllEvents(this);
	G_PANELEVT->removeEventListener(this);
}

bool ue::Panel::init()
{
	if (!CtrlFile::init())
	{
		return false;
	}

	return true;
}

void ue::Panel::initUI()
{
}

void ue::Panel::initEvent()
{
}

void ue::Panel::initText()
{
}

bool ue::Panel::touchFrontWidget(ui::CtrlWidget* widget, const math::Vector2& touchPoint, const FrontWidgetFunc& func)
{
	if (widget == nullptr || func == nullptr) return false;

	bool contain = false;
	const auto& vecWidgets = widget->getAllWidgets();
	int nChildCount = vecWidgets.size();
	if (nChildCount > 0)
	{
		for (int i = nChildCount - 1; i >= 0; i--)
		{
			if (touchFrontWidget(vecWidgets[i], touchPoint, func))
			{
				contain = true;
				return true;
			}
		}
	}

	if (!contain)
	{
		if (!widget->containsTouchPoint(touchPoint))
		{
			return false;
		}

		auto pParent = widget->getParent();
		if (pParent)
		{
			if (pParent->is<ui::CtrlScrollView>())
			{
				func(static_cast<ui::CtrlWidget*>(pParent));
			}
			else
			{
				func(widget);
			}
		}
		else
		{
			func(widget);
		}
	}

	return true;
}

ui::CtrlWidget* ue::Panel::createUIFile(const std::string& filepath)
{
	auto pFile = CREATE_NODE(ui::CtrlFile);
	if (pFile)
	{
		pFile->setFilePath(filepath);
	}

	return pFile;
}
