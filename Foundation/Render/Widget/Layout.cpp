#include "Layout.h"

using namespace render;
Layout::Layout()
:_layoutScaleX(1)
, _layoutScaleY(1)
, _layoutContentScale(1)
{

}

Layout::~Layout()
{

}

bool Layout::init()
{
	Node::init();

	_notify->addListen(ENP_USER_INTERFACE, [&](){
		this->updateLayout();
	});

	return true;
}

void Layout::setLayoutSize(float width, float height)
{
	_layoutSize.width = width;
	_layoutSize.height = height;

	this->setVolume(width, height);

	_notify->addMark(ENP_USER_INTERFACE);
}

void Layout::updateViewSize(float width, float height)
{
	if (_layoutSize.width == width && _layoutSize.height == height)
	{
		return;
	}

	_layoutScaleX = width / _layoutSize.width;
	_layoutScaleY = height / _layoutSize.height;

	_layoutContentScale = _layoutScaleX < _layoutScaleY ? _layoutScaleX : _layoutScaleY;

	_notify->addMark(ENP_USER_INTERFACE);
}

void Layout::updateLayout()
{
	this->build(_layoutScaleX, _layoutScaleY, _layoutContentScale);
}

