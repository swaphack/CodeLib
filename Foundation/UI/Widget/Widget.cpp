#include "Widget.h"

using namespace ui;

Widget::Widget()
:_bBoxVisible(false)
{

}

Widget::~Widget()
{

}

const sys::Rect& Widget::getGeometry()
{
	return m_rGeometry;
}

void Widget::setGeometry(float x, float y, float width, float height)
{
	m_rGeometry.x = x;
	m_rGeometry.y = y;
	m_rGeometry.width = width;
	m_rGeometry.height = height;
}

void Widget::setGeometry(const sys::Rect& rect)
{
	m_rGeometry = rect;
}

void Widget::setPosition(float x, float y)
{
	m_rGeometry.x = x;
	m_rGeometry.y = y;
}

void Widget::setSize(float width, float height)
{
	m_rGeometry.width = width;
	m_rGeometry.height = height;
}

const sys::Size& Widget::getMinSize()
{
	return m_sMinSize;
}

void Widget::setMinSize(float width, float height)
{
	m_sMinSize.width = width;
	m_sMinSize.height = height;
}

const sys::Size& Widget::getMaxSize()
{
	return m_sMaxSize;
}

void Widget::setMaxSize(float width, float height)
{
	m_sMaxSize.width = width;
	m_sMaxSize.height = height;
}
