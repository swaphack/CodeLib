#include "LayoutWidgetItem.h"

using namespace ui;

LayoutWidgetItem::LayoutWidgetItem(Widget* widget)
{
	ASSERT(widget != nullptr);

	this->setWidget(widget);
}

LayoutWidgetItem::~LayoutWidgetItem()
{

}