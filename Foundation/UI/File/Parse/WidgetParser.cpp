#include "WidgetParser.h"

using namespace ui;

WidgetParser::WidgetParser()
:_node(nullptr)
, _layoutItem(nullptr)
{
}

WidgetParser::~WidgetParser()
{
}

void WidgetParser::setWidget(Widget* widget)
{
	_node = widget;
}

LayoutItem* WidgetParser::getLayoutItem()
{
	return _layoutItem;
}
