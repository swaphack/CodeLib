#include "Node.h"
#include <algorithm>

using namespace render;

//////////////////////////////////////////////////////////////////////////

Node::Node()
:_tag(0)
,_userData(nullptr)
,_parent(nullptr)
,_bVisibled(false)
,_bTouchEnabled(false)
,_actionProxy(nullptr)
, _bRelative(true)
, _zOrder(0.0f)
, _bShowRect(false)
{
	this->setVisible(true);
	this->setTouchEnabled(true);
	this->setPosition(0, 0, 0);
	this->setScale(1, 1, 1);
	this->setRotation(0, 0, 0);
	this->setAnchorPoint(0.5, 0.5, 0.5);
	this->setVolume(1,1,1);
}

Node::~Node()
{
	SAFE_DELETE(_actionProxy);
	this->clearAllChildren();
}

bool Node::init()
{
	return true;
}

void Node::setParent( Node* node )
{
	ASSERT(this->getParent() == nullptr || node == nullptr);

	_parent = node;
}

Node* Node::getParent()
{
	return _parent;
}

void Node::removeFromParent()
{
	ASSERT(this->getParent() != nullptr);

	this->getParent()->removeChild(this);
}

void Node::addChild( Node* node )
{
	ASSERT(node != nullptr);

	node->setParent(this);

	_children.addObject(node);

	setDirty(true);
}

void Node::removeChild( Node* node )
{
	ASSERT(node != nullptr);

	node->setParent(nullptr);

	_children.removeObject(node);

	setDirty(true);
}

void Node::clearAllChildren()
{
	std::vector<Object*>::iterator begin = _children.begin();

	while (begin != _children.end())
	{
		Node* node = dynamic_cast<Node*>((*begin));
		ASSERT(node != nullptr);
		node->removeFromParent();
		begin++;
	}

	_children.clear();
}

Node* Node::getChildByID( long id )
{
	return dynamic_cast<Node*>(_children.getObject(id));
}

void Node::setTag( int tag )
{
	_tag = tag;
}

int Node::getTag()
{
	return _tag;
}

void Node::setUserData( void* data )
{
	_userData = data;
}

void* Node::getUserData()
{
	return _userData;
}

void Node::setZOrder(float z)
{
	_position.z = z;
	_zOrder = z;
	setDirty(true);
}

float Node::getZOrder()
{
	return _zOrder;
}

void Node::setPosition( float x, float y, float z )
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_zOrder = z;
	setDirty(true);
}

const sys::Vector& Node::getPosition()
{
	return _position;
}

void Node::setScale( float x, float y, float z )
{
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
	setDirty(true);
}

const sys::Vector& Node::getScale()
{
	return _scale;
}

void Node::setRotation( float x, float y, float z )
{
	_rotation.x = x;
	_rotation.y = y;
	_rotation.z = z;
	setDirty(true);
}

const sys::Vector& Node::getRotation()
{
	return _rotation;
}

void Node::setAnchorPoint( float x, float y, float z )
{
	_anchor.x = x;
	_anchor.y = y;
	_anchor.z = z;
	setDirty(true);
}

const sys::Vector& Node::getAnchorPoint()
{
	return _anchor;
}

void Node::setVolume( float w, float h, float d )
{
	_volume.width = w;
	_volume.height = h;
	_volume.deep = d;

	setDirty(true);
}

const sys::Volume& Node::getVolume()
{
	return _volume;
}

void Node::setVisible( bool status )
{
	if (_bVisibled == status)
	{
		return;
	}

	_bVisibled = status;
}

bool Node::isVisible()
{
	return _bVisibled;
}

void Node::setTouchEnabled( bool status )
{
	if (_bTouchEnabled == status)
	{
		return;
	}

	_bTouchEnabled = status;
}

bool Node::isTouchEnabled()
{
	return _bTouchEnabled;
}

void Node::draw()
{
	if (_bShowRect)
	{
		GLTool::setColor(_rectColor);
		GLTool::drawRect(&_rectVertex, GL_LINE_LOOP);
	}
}

void Node::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	glPushMatrix();

	if (isDirty())
	{
		this->initSelf();

		setDirty(false);
	}
	this->updateTranform();

	if (_children.count() == 0)
	{
		this->draw();
	}
	else
	{
		bool show = false;
		std::vector<Object*>::iterator iter = _children.begin();
		while (iter != _children.end())
		{
			Node* node = dynamic_cast<Node*>(*iter);
			if (node->getZOrder() >= 0 && show == false)
			{
				this->draw();
				show = true;
			}
			node->visit();
			iter++;
		}
	}

	glPopMatrix();
}

ActionProxy* Node::getActionProxy()
{
	if (_actionProxy == nullptr)
	{
		_actionProxy = new ActionProxy(this);
	}
	return _actionProxy;
}

bool Node::isRelativeWithParent()
{
	return _bRelative;
}

void Node::setRelativeWithParent(bool status)
{
	_bRelative = status;
}

void Node::setRectVisible(bool status)
{
	_bShowRect = status;
}

void Node::setRectColor(const sys::Color4B& color)
{
	_rectColor = color;
}

bool Node::containTouchPoint(float x, float y)
{
	return false;
}

void Node::updateTranform()
{
	if (!this->isRelativeWithParent())
	{
		glLoadIdentity();
	}

	glTranslatef(_obPosition.x, _obPosition.y, _obPosition.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(_scale.x, _scale.y, _scale.z);
	glTranslatef(-_obPosition.x, -_obPosition.y, -_obPosition.z);
}

void Node::initSelf()
{
	UITool::convertToOGLPoisition(_position, _obPosition);

	GLTool::calRect(_position, _volume, _anchor, _rectVertex);

	sortChildren();
}

void Node::sortChildren()
{
	std::vector<Node*> orderNodes;
	bool bInsert;
	std::vector<Node*>::iterator oIt;

	std::vector<Object*>::iterator it = _children.begin();
	while (it != _children.end())
	{
		Node* node = dynamic_cast<Node*>(*it);
		if (node)
		{
			node->retain();
			bInsert = false;
			oIt = orderNodes.begin();
			while (oIt != orderNodes.end())
			{
				if ((*oIt)->getZOrder() > node->getZOrder())
				{
					orderNodes.insert(oIt, node);
					bInsert = true;
					break;
				}
				oIt++;
			}
			if (bInsert == false)
			{
				orderNodes.push_back(node);
			}
		}
		it++;
	}

	_children.clear();
	oIt = orderNodes.begin();
	while (oIt != orderNodes.end())
	{
		(*oIt)->release();
		_children.addObject((*oIt));
		oIt++;
	}
}