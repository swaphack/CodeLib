#include "Node.h"
#include "Common/Touch/TouchProxy.h"
#include "Common/Action/ActionProxy.h"
#include "Common/Tool/Tool.h"
#include <algorithm>
#include "Graphic/import.h"

using namespace render;

//////////////////////////////////////////////////////////////////////////

Node::Node()
:_tag(0)
,_userData(nullptr)
,_parent(nullptr)
,_bVisibled(false)
,_bTouchEnabled(false)
,_actionProxy(nullptr)
, _bRelativeToParent(true)
, _zOrder(0)
, _touchProxy(nullptr)
{
	this->setVisible(true);

	_notify = new Notify<NodeNotifyType>;
}

Node::~Node()
{
	this->removeAllChildren();
	SAFE_DELETE(_actionProxy);
	SAFE_DELETE(_touchProxy);
	SAFE_DELETE(_notify);
}

bool Node::init()
{
	// 添加属性改变监听
	_notify->addListen(NodeNotifyType::SPACE, [&](){
		calSpaceData(); 
	});

	_notify->addListen(NodeNotifyType::NODE, [&](){ this->sortChildren(); });

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
	this->addChild(node, 0);
}

void render::Node::addChild(Node* node, int zOrder)
{
	ASSERT(node != nullptr && node->getParent() == nullptr);

	if (node->getParent() == this)
	{
		return;
	}
	node->setZOrder(zOrder);
	node->setParent(this);

	SAFE_RETAIN(node);
	_children.push_back(node);

	onChildrenChange();
}

void Node::removeChild( Node* node )
{
	ASSERT(node != nullptr);

	if (node->getParent() != this)
	{
		return;
	}

	node->setParent(nullptr);

	SAFE_RELEASE(node);
	auto it = std::find(_children.begin(), _children.end(), node);
	if (it != _children.end())
	{
		_children.erase(it);
	}

	onChildrenChange();
}

void Node::removeAllChildren()
{
	std::vector<Node*> children = _children;
	auto it = children.begin();

	while (it != children.end())
	{
		Node* node = dynamic_cast<Node*>((*it));
		ASSERT(node != nullptr);
		node->removeFromParent();
		it++;
	}

	_children.clear();
	onChildrenChange();
}

Node* Node::getChildByID( long id )
{
	for (auto item : _children)
	{
		if (item->getID() == id)
		{
			return item;
		}
	}
	return nullptr;
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
	for (auto item : _children)
	{
		if (item->getTag() == tag)
		{
			return item;
		}
	}
	return nullptr;
}

Node* Node::getChildByName(const std::string& name)
{
	for (auto item : _children)
	{
		if (item->getName() == name)
		{
			return item;
		}
	}
	return nullptr;
}

Node* Node::getFirstChild()
{
	if (_children.size() == 0)
	{
		return nullptr;
	}

	return _children.front();
}

// void Node::foreachChild(std::function<void(Node*)> handler)
// {
// 	std::vector<Object*>::iterator iter = _children.begin();
// 	while (iter != _children.end())
// 	{
// 		handler(dynamic_cast<Node*>(*iter));
// 		iter++;
// 	}
// }

void Node::setUserData( void* data )
{
	_userData = data;
}

void* Node::getUserData()
{
	return _userData;
}

void Node::setZOrder(int z)
{
	_zOrder = z;
	setDirty(true);
}

int Node::getZOrder()
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
	return _bRelativeToParent;
}

void Node::setRelativeWithParent(bool status)
{
	_bRelativeToParent = status;
}

TouchProxy* Node::getTouchProxy()
{
	if (_touchProxy == nullptr)
	{
		_touchProxy = new TouchProxy(this);
	}
	return _touchProxy;
}

void Node::draw()
{

}

void Node::startUpdateTranform()
{
	if (!this->isRelativeWithParent())
	{
		GLMatrix::pushMatrix();
		GLMatrix::loadIdentity();
	}

	GLMatrix::multMatrix(_localMatrix);

	GLDebug::showError();
}

void Node::endUpdateTranform()
{
	GLMatrix::multMatrix(_localInverseMatrix);

	if (!this->isRelativeWithParent())
	{
		GLMatrix::popMatrix();
	}
}

void Node::notifyEvents()
{
	// 数值计算
	if (isDirty())
	{
		_notify->run();

		setDirty(false);
	}
}

void Node::sortChildren()
{
	std::vector<Node*> orderNodes;
	bool bInsert;
	std::vector<Node*>::iterator oIt;

	auto it = _children.begin();
	while (it != _children.end())
	{
		Node* node = *it;
		if (node)
		{
			node->retain();
			bInsert = false;
			oIt = orderNodes.begin();
			while (oIt != orderNodes.end())
			{
				if ((*oIt)->getZOrder() < node->getZOrder())
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
		SAFE_RELEASE(*oIt);
		_children.push_back((*oIt));
		oIt++;
	}
}


// 还未对旋转后坐标进行计算
void Node::calSpaceData()
{
	//Tool::convertToOGLPoisition(_position, _obPosition);

	Tool::convertToRadian(_rotation, _obRotation);

	calRealSpaceByMatrix();
}

void Node::calRealSpaceByMatrix()
{
	//_localMatrix = math::Matrix44::getRST(_obRotation, getScale(), _obPosition);

	_localMatrix = math::Matrix44::getRST(_obRotation, getScale(), _position);

	_localInverseMatrix = _localMatrix.getInverse();

	//PRINT("mat\n%s\n", _mat44.toString().c_str());

	if (this->getParent() != nullptr)
	{
		if (this->isRelativeWithParent())
		{
			math::Matrix44 mat = this->getParent()->getWorldMatrix();
			_worldMatrix = _localMatrix * mat;
		}
		else
		{
			_worldMatrix = _localMatrix;
		}
	}
	else
	{
		_worldMatrix = _localMatrix;
	}
}

void Node::onSpaceChange()
{
	this->notify(NodeNotifyType::SPACE);
}

void Node::onBodyChange()
{
	this->notify(NodeNotifyType::SPACE);
}

void Node::onChildrenChange()
{
	this->notify(NodeNotifyType::NODE);
}

const math::Matrix44& Node::getWorldMatrix() const
{
	return _worldMatrix;
}

const math::Matrix44& Node::getLocalMatrix() const
{
	return _localMatrix;
}

math::Vector3 render::Node::convertWorldPostitionToLocal(const math::Vector3& point)
{
	math::Matrix44 mat = _worldMatrix.getInverse();

	return math::Matrix44::transpose(point, mat);
}

math::Vector3 render::Node::convertLocalPostitionToWorld(const math::Vector3& point)
{
	return math::Matrix44::transpose(point, _worldMatrix);
}

void render::Node::updateNode()
{
	this->notifyEvents();

	for (auto item : _children)
	{
		item->updateNode();
	}
}

void render::Node::beforeDrawNode()
{
}

void Node::drawNode()
{
	if (this->isVisible() == false)
	{
		return;
	}

	this->startUpdateTranform();

	this->beforeDrawNode();

	this->draw();

	this->afterDrawNode();

	this->endUpdateTranform();

	GLDebug::showError();
}

void render::Node::afterDrawNode()
{
	this->drawAllChildren();
}

void render::Node::drawAllChildren()
{
	for (auto item : _children)
	{
		item->drawNode();
	}
}

void Node::notify(NodeNotifyType id)
{
	_notify->addMark(id);
	setDirty(true);
}

void render::Node::notifyToAll(NodeNotifyType id)
{
	this->notify(id);

	for (auto it = _children.begin(); it != _children.end(); it++)
	{
		(*it)->notifyToAll(id);
	}
}