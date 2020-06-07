#include "LayoutWidgetItem.h"

using namespace ui;

LayoutWidgetItem::LayoutWidgetItem(render::CtrlWidget* widget)
{
	ASSERT(widget != nullptr);

	this->setWidget(widget);
}

LayoutWidgetItem::~LayoutWidgetItem()
{

}