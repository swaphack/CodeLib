#include "LayoutItemParser.h"
#include "../../Layout/LayoutItem.h"

using namespace ui;

LayoutItemParser::LayoutItemParser()
:m_pLayoutItem(nullptr)
{

}

LayoutItemParser::~LayoutItemParser()
{
}

void LayoutItemParser::setLayoutItem(LayoutItem* item)
{
	m_pLayoutItem = item;
}