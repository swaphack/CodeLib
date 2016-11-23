#include "Node.h"
#include "../Touch/TouchProxy.h"
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
, _touchProxy(nullptr)
{
	this->setVisible(true);
}

Node::~Node()
{
	SAFE_DELETE(_actionProxy);
	SAFE_DELETE(_touchProxy);
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

Node* Node::getChildByTag(int tag)
{
	std::vector<Object*>::iterator iter = _children.begin();

	Node* node;
	while (iter != _children.end())
	{
		node = dynamic_cast<Node*>(*iter);
		if (node && node->getTag() == tag)
		{
			return node;
		}
		iter++;
	}

	return nullptr;
}

Node* Node::getChildByName(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}
	std::vector<Object*>::iterator iter = _children.begin();

	Node* node;
	while (iter != _children.end())
	{
		node = dynamic_cast<Node*>(*iter);
		if (node && strcmp(node->getName(), name) == 0)
		{
			return node;
		}
		iter++;
	}

	return nullptr;
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
	_zOrder = z;
	setDirty(true);
}

float Node::getZOrder()
{
	return _zOrder;
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

// void Node::calculate()
// {
// 	if (this->isVisible() == false)
// 	{
// 		return;
// 	}
// 
// 	if (isDirty())
// 	{
// 		this->initSelf();
// 
// 		setDirty(false);
// 	}
// 
// 	std::vector<Object*>::iterator iter = _children.begin();
// 	while (iter != _children.end())
// 	{
// 		Node* node = dynamic_cast<Node*>(*iter);
// 		node->calculate();
// 		iter++;
// 	}
// }

void Node::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	// 数值计算
	if (isDirty())
	{
		this->initSelf();

		setDirty(false);
	}

	// 图形命令
	//glPushMatrix();
	G_DRAWCOMMANDER->addCommand(DCMatrix::create(true));

	this->updateSelf();

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
			if (show == false && node->getZOrder() >= 0)
			{
				this->draw();
				show = true;
			}
			node->visit();
			iter++;
		}
	}

	//glPopMatrix();
	G_DRAWCOMMANDER->addCommand(DCMatrix::create(false));
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

bool Node::containTouchPoint(float x, float y)
{
	return _realSpaceVertex.containPoint(x, y);
}

TouchProxy* Node::getTouchProxy()
{
	if (_touchProxy == nullptr)
	{
		_touchProxy = new TouchProxy(this);
	}
	return _touchProxy;
}

const RectangeVertex& Node::getRectVertex()
{
	return _rectVertex;
}

void Node::draw()
{

}

void Node::updateTranform()
{
// 	if (!this->isRelativeWithParent())
// 	{
// 		glLoadIdentity();
// 	}
// 
// 	glTranslatef(_obPosition.x, _obPosition.y, _obPosition.z);
// 	glRotatef(_rotation.x, 1, 0, 0);
// 	glRotatef(_rotation.y, 0, 1, 0);
// 	glRotatef(_rotation.z, 0, 0, 1);
// 	glScalef(_scale.x, _scale.y, _scale.z);

	G_DRAWCOMMANDER->addCommand(DCSpace::create(_obPosition, _scale, _rotation, _bRelative));
}

void Node::updateSelf()
{
	this->updateTranform();
}


void Node::initSelf()
{
	Tool::convertToOGLPoisition(_position, _obPosition);

	Tool::calRect(sys::Vector::Zero, _volume, _anchor, _rectVertex);

	calRealSpaceInfo();

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
	// 计数器减1
	_children.clear();
	oIt = orderNodes.begin();
	while (oIt != orderNodes.end())
	{
		(*oIt)->release();
		_children.addObject((*oIt));
		oIt++;
	}
}

// 还未对旋转后坐标进行计算
void Node::calRealSpaceInfo()
{
	Node* temp = this;
	sys::Vector position;
	sys::Vector scale = sys::Vector::One;
	sys::Volume volume = _volume;
	do 
	{
		position.add(temp->getPosition());
		scale.mult(temp->getScale());

		if (!temp->isRelativeWithParent())
		{
			break;
		}
		else
		{
			temp = temp->getParent();
		}
	} while (temp != NULL);
	volume.mult(scale);

	Tool::calRealRect(position, volume, _anchor, _realSpaceVertex);
}

void Node::onSpaceChange()
{
	setDirty(true);
}

void Node::onBodyChange()
{
	setDirty(true);
}
