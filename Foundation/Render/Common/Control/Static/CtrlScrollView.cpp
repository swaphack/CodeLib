#include "CtrlScrollView.h"
using namespace render;

ScrollItem::ScrollItem()
{
	this->setAnchorPoint(0, 0);
}

ScrollItem::~ScrollItem()
{

}

void ScrollItem::addItem(Node* node, const sys::Size& size)
{
	if (node == nullptr)
	{
		return;
	}
	node->setPosition(size.width * 0.5f, size.height * 0.5f);
	this->addChild(node);
	this->setVolume(size.width, size.height);
}

ScrollItem* ScrollItem::create(Node* node, const sys::Size& size)
{
	ScrollItem* item = new ScrollItem();
	AUTO_RELEASE_OBJECT(item);
	item->addItem(node, size);

	return item;
}


//////////////////////////////////////////////////////////////////////////
CtrlScrollView::CtrlScrollView()
:_scrollDirection(ESD_NONE)
{
	_content = CREATE_NODE(Node);
	this->addChild(_content);

	this->getTouchProxy()->addTouchDelegate(ETT_DOWN, this, (TOUCH_DELEGATE_HANDLER)&CtrlScrollView::onBeginTouch);
	this->getTouchProxy()->addTouchDelegate(ETT_ON, this, (TOUCH_DELEGATE_HANDLER)&CtrlScrollView::onMoveTouch);
	this->getTouchProxy()->addTouchDelegate(ETT_UP, this, (TOUCH_DELEGATE_HANDLER)&CtrlScrollView::onEndTouch);
}

CtrlScrollView::~CtrlScrollView()
{

}

void CtrlScrollView::setScrollDirection(ScrollDirection direction)
{
	if (_scrollDirection != direction)
	{
		_scrollDirection = direction;
		initItems();
		initContent();
	}
}

ScrollDirection CtrlScrollView::getScrollDirection()
{
	return _scrollDirection;
}

void CtrlScrollView::append(Node* item)
{
	if (item == nullptr)
	{
		return;
	}
	
	this->append(item, _itemSize);
}

void CtrlScrollView::append(Node* item, const sys::Size& size)
{
	if (item == nullptr)
	{
		return;
	}

	ASSERT(size.width != 0 && size.height != 0);
	
	ScrollItem* pScrollItem = ScrollItem::create(item, size);
	pScrollItem->init();
	AUTO_RELEASE_OBJECT(pScrollItem);

	_content->addChild(pScrollItem);
	_nodes.push_back(pScrollItem);

	initItems();
}

void CtrlScrollView::remove(Node* item)
{
	if (item == nullptr)
	{
		return;
	}
	
	std::vector<Node*>::iterator iter = _nodes.begin();
	while (iter != _nodes.end())
	{
		if ((*iter)->getFirstChild() == item)
		{
			_nodes.erase(iter);
			_content->removeChild(*iter);
			break;
		}
		iter++;
	}

	initItems();
}

void CtrlScrollView::removeAllItems()
{
	std::vector<Node*>::iterator iter = _nodes.begin();
	while (iter != _nodes.end())
	{
		(*iter)->release();
		iter++;
	}

	_nodes.clear();
	initItems();
}


void CtrlScrollView::setItemSize(const sys::Size& size)
{
	_itemSize = size;
}

void CtrlScrollView::setItemSize(float width, float height)
{
	_itemSize.width = width;
	_itemSize.height = height;
}

const sys::Size& CtrlScrollView::getItemSize()
{
	return _itemSize;
}


void CtrlScrollView::onBeginTouch(sys::Object* object, float x, float y)
{
	if (object != this)
	{
		return;
	}

	onTouchBegan(x, y);
}

void CtrlScrollView::onMoveTouch(sys::Object* object, float x, float y)
{
	if (object != this)
	{
		return;
	}

	onTouchMoved(x, y);
}

void CtrlScrollView::onEndTouch(sys::Object* object, float x, float y)
{
	if (object != this)
	{
		return;
	}

	onTouchEnded(x, y);
}

bool CtrlScrollView::onTouchBegan(float x, float y)
{
	_touchPosition.x = x;
	_touchPosition.y = y;

	return true;
}

void CtrlScrollView::onTouchMoved(float x, float y)
{
	sys::Point delta = sys::Point(x, y);
	delta.sub(_touchPosition);

	float offX = -getAnchorPoint().x * getWidth();
	float offY = -getAnchorPoint().y * getHeight();

	sys::Vector pos = _content->getPosition();

	float min = 0;
	float max = 0;

	switch (_scrollDirection)
	{
	case ESD_HORIZONTAL_LEFT:
	{
		pos.x += delta.x;
		min = getWidth() - _content->getWidth() + offX;
		max = 0 + offX;
		if (pos.x < min) pos.x = min;
		if (pos.x > max) pos.x = max;
		break;
	}
	case ESD_HORIZONTAL_RIGHT:
	{
		pos.x += delta.x;
		min = getWidth() - _content->getWidth() + offX;
		max = 0 + offX;
		if (pos.x < min) pos.x = min;
		if (pos.x > max) pos.x = max;
		break;
	}
	case ESD_VERTICAL_TOP:
	{
		pos.y += delta.y;
		min = getHeight() - _content->getHeight() + offY;
		max = 0 + offY;
		if (pos.y < min) pos.y = min;
		if (pos.y > max) pos.y = max;
		break;
	}
	case ESD_VERTICAL_BOTTOM:
	{
		pos.y += delta.y;
		min = getHeight() - _content->getHeight() + offY;
		max = 0 + offY;
		if (pos.y < min) pos.y = min;
		if (pos.y > max) pos.y = max;
		break;
	}
	default:
		break;
	}

	_content->setPosition(pos);

	_touchPosition = sys::Point(x, y);
}

void CtrlScrollView::onTouchEnded(float x, float y)
{

}

void CtrlScrollView::initSelf()
{
	CtrlScissor::initSelf();
}

void CtrlScrollView::initItems()
{
	if (_scrollDirection == ESD_NONE)
	{
		return;
	}
	if (_nodes.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	switch (_scrollDirection)
	{
	case ESD_HORIZONTAL_LEFT:
	{
		std::vector<Node*>::iterator iter = _nodes.begin();
		while (iter != _nodes.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
		break;
	}
	case ESD_HORIZONTAL_RIGHT:
	{
		std::vector<Node*>::reverse_iterator iter = _nodes.rbegin();
		while (iter != _nodes.rend())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
		break;
	}
	case ESD_VERTICAL_TOP:
	{
		std::vector<Node*>::iterator iter = _nodes.begin();
		while (iter != _nodes.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY));
		break;
	}
	case ESD_VERTICAL_BOTTOM:
	{
		std::vector<Node*>::reverse_iterator iter = _nodes.rbegin();
		while (iter != _nodes.rend())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY));
		break;
	}
	default:
		break;
	}
}

void CtrlScrollView::initContent()
{
	float offX = -getAnchorPoint().x * getWidth();
	float offY = -getAnchorPoint().y * getHeight();

	switch (_scrollDirection)
	{
	case ESD_HORIZONTAL_LEFT:
		_content->setPosition(0 + offX, 0 + offY);
		break;
	case ESD_HORIZONTAL_RIGHT:
		_content->setPosition(getWidth() - _content->getWidth() + offX, 0 + offY);
		break;
	case ESD_VERTICAL_TOP:
		_content->setPosition(0 + offX, getHeight() - _content->getHeight() + offY);
		break;
	case ESD_VERTICAL_BOTTOM:
		_content->setPosition(0 + offX, 0 + offY);
		break;
	default:
		break;
	}
}