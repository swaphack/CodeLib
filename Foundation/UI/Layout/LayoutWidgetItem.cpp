#include "LayoutWidgetItem.h"

using namespace ui;

LayoutWidgetItem::LayoutWidgetItem(Widget* widget)
{
	ASSERT(widget != nullptr);

	this->setWidget(widget);

	this->addChild(widget);
}

LayoutWidgetItem::~LayoutWidgetItem()
{

}