#include "Widget.h"

using namespace render;
Widget::Widget()
:_widgetHorizontalAlignment(EHA_LEFT)
, _widgetVerticalAlignment(EVA_CENTER)
, _offsetX(0)
, _offsetY(0)
, _bBoundBoxVisible(false)
, _contentScale(1)
{

}

Widget::~Widget()
{

}

void Widget::setHorizontalAlign(HorizontalAlignment alignment)
{
	_widgetHorizontalAlignment = alignment;
}

HorizontalAlignment Widget::getHorizontalAlign()
{
	return _widgetHorizontalAlignment;
}

void Widget::setVerticalAlign(VerticalAlignment alignment)
{
	_widgetVerticalAlignment = alignment;
}

VerticalAlignment Widget::getVerticalAlign()
{
	return _widgetVerticalAlignment;
}

void Widget::setOffsetX(float distance)
{
	_offsetX = distance;
}

float Widget::getOffsetX()
{
	return _offsetX;
}

void Widget::setOffsetY(float distance)
{
	_offsetY = distance;
}

float Widget::getOffsetY()
{
	return _offsetY;
}

void Widget::setBoundBoxVisible(bool visible)
{
	_bBoundBoxVisible = visible;
}

bool Widget::isBoundBoxVisible()
{
	return _bBoundBoxVisible;
}

void Widget::build(float scaleX, float scaleY, float contentScale)
{
	sys::Size contentSize;
	Widget* pParent = dynamic_cast<Widget*>(getParent());
	if (pParent)
	{
		contentSize = pParent->getSize();
	}
	
	float posX = 0;
	float poxY = 0;
	
	// xÖáÎ»ÖÃ
	if (_widgetHorizontalAlignment == EHA_LEFT)
	{
		posX = _offsetX * scaleX + getWidth() * getAnchorPoint().x * contentScale;
	}
	else if (_widgetHorizontalAlignment == EHA_CENTER)
	{
		posX = contentSize.width * 0.5f + getWidth() * (getAnchorPoint().x - 0.5f) * contentScale;
	}
	else if (_widgetHorizontalAlignment == EHA_RIGHT)
	{
		posX = (contentSize.width - _offsetX * scaleX) - getWidth() * (1 - getAnchorPoint().x) * contentScale;
	}
	// yÖáÎ»ÖÃ
	if (_widgetVerticalAlignment == EVA_BOTTOM)
	{
		poxY = _offsetY * scaleY + getHeight() * getAnchorPoint().y * contentScale;
	}
	else if (_widgetVerticalAlignment == EVA_CENTER)
	{
		poxY = contentSize.height * 0.5 + getHeight() * (getAnchorPoint().y - 0.5f) * contentScale;
	}
	else if (_widgetVerticalAlignment == EVA_TOP)
	{
		posX = (contentSize.height - _offsetX * scaleY) - getHeight() * (1 - getAnchorPoint().y) * contentScale;
	}

	this->setPosition(posX, poxY);

	_contentScale = contentScale;

	std::vector<Object*>::iterator iter = _children.begin();
	while (iter != _children.end())
	{
		Widget* pWidget = dynamic_cast<Widget*>(*iter);
		if (pWidget)
		{
			pWidget->build(scaleX, scaleY, contentScale);
		}

		iter++;
	}
}

void Widget::updateTranform()
{
	sys::Vector scale = _scale;
	scale.mult(_contentScale);
	G_DRAWCOMMANDER->addCommand(DCSpace::create(_obPosition, scale, _rotation, _bRelative));
}
