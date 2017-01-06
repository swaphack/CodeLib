#include "WidgetParser.h"

using namespace ui;

WidgetParser::WidgetParser()
:_node(nullptr)
{
}

WidgetParser::~WidgetParser()
{
}

void WidgetParser::setWidget(Widget* widget)
{
	_node = widget;
}
