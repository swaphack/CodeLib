#include "Node.h"
#include "Common/Action/ActionProxy.h"
#include "Common/Tool/Tool.h"
#include <algorithm>
#include "Graphic/import.h"
#include "Common/View/Camera.h"
#include "NotifyCenter.h"
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
{
	this->setVisible(true);

	_notify = G_NOTIFYCENTER->alloct(this);
}

Node::~Node()
{
	this->removeAllChildren();
	SAFE_RELEASE(_actionProxy);
	G_NOTIFYCENTER->release(this);
}

bool Node::init()
{
	// 添加属性改变监听
	_notify->addListen(NodeNotifyType::SPACE, [&](){
		calSpaceData(); 
	});

	_notify->addListen(NodeNotifyType::NODE, [&](){ 
		this->sortChildren();
	});

	return true;
}

void Node::setParent( Node* node )
{
	ASSERT(this->getParent() == nullptr || node == nullptr);

	_parent = node;
}

Node* Node::getParent() const
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
		Node* node = (*it);
		ASSERT(node != nullptr);
		node->removeFromParent();
		it++;
	}

	_children.clear();
	onChildrenChange();
}

Node* Node::getChildByID( long id ) const
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

int Node::getTag() const
{
	return _tag;
}

Node* Node::getChildByTag(int tag) const
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

Node* Node::getChildByName(const std::string& name) const
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

Node* Node::getFirstChild() const
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

void* Node::getUserData() const
{
	return _userData;
}

void Node::setZOrder(int z)
{
	_zOrder = z;
	setDirty(true);
}

int Node::getZOrder() const
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

bool Node::isVisible() const
{
	return _bVisibled;
}

ActionProxy* Node::getActionProxy()
{
	if (_actionProxy == nullptr)
	{
		_actionProxy = CREATE_OBJECT(ActionProxy);
		_actionProxy->setTarget(this);
		_actionProxy->retain();
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
				if ( node->getZOrder() < (*oIt)->getZOrder())
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

	//calDirectionWithRotate();
}

void Node::calRealSpaceByMatrix()
{
	math::Matrix4x4::getRST(_obRotation, getScale(), _position, _localMatrix);

	math::SquareMatrix4 sm = _localMatrix;
	_localInverseMatrix = sm.getInverse();

	if (this->getParent() != nullptr)
	{
		if (this->isRelativeWithParent())
		{
			math::Matrix4x4 mat = this->getParent()->getWorldMatrix();
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

	_worldInverseMatrix = _worldMatrix.getInverse();
}

void Node::onSpaceChange()
{
	this->notifyToAll(NodeNotifyType::SPACE);
}

void Node::onBodyChange()
{
	this->notify(NodeNotifyType::BODY);
}

void Node::onChildrenChange()
{
	this->notify(NodeNotifyType::NODE);
}

const math::Matrix4x4& Node::getWorldMatrix() const
{
	return _worldMatrix;
}

const math::Matrix4x4& Node::getLocalMatrix() const
{
	return _localMatrix;
}

math::Vector3 render::Node::convertWorldPostitionToLocal(const math::Vector3& point)
{
	math::Matrix4x4 mat = _worldMatrix.getInverse();

	return math::Matrix4x4::transpose(point, mat);
}

math::Vector3 render::Node::convertLocalPostitionToWorld(const math::Vector3& point)
{
	return math::Matrix4x4::transpose(point, _worldMatrix);
}

void render::Node::doSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include)
{
	/*
	for (auto item : _children)
	{
		if (type == TouchType::DOWN) item->onTouchBegan(touchPoint);
		else if (type == TouchType::ON) item->onTouchMoved(touchPoint);
		else if (type == TouchType::UP) item->onTouchEnded(touchPoint);
	}
	*/
}

void render::Node::doNotSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include)
{
	for (auto item : _children)
	{
		if (type == TouchType::DOWN) item->onTouchBegan(touchPoint);
		else if (type == TouchType::ON) item->onTouchMoved(touchPoint);
		else if (type == TouchType::UP) item->onTouchEnded(touchPoint);
	}
}

void render::Node::setSkipDraw(bool status)
{
	_bSkipDraw = status;
}

bool render::Node::isSkipDraw() const
{
	return _bSkipDraw;
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
	if (this->isSkipDraw())
	{
		return;
	}
	if (!this->isVisible())
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

void render::Node::addNotifyListener(NodeNotifyType id, const NotifyDelegate& handler)
{
	_notify->addListen(id, handler);
}

void render::Node::notifyToAll(NodeNotifyType id)
{
	this->notify(id);

	for (auto it = _children.begin(); it != _children.end(); it++)
	{
		(*it)->notifyToAll(id);
	}
}

void render::Node::broadcastFunc(const std::function<void(Node*)>& func, bool recursive /*= false*/)
{
	if (func == nullptr)
	{
		return;
	}

	func(this);

	if (recursive)
	{
		for (auto it = _children.begin(); it != _children.end(); it++)
		{
			(*it)->broadcastFunc(func, recursive);
		}
	}
}

void render::Node::calDirectionWithRotate()
{
	if (_obRotation == math::Vector3(0,0,0))
	{
		setRight(getDefaultRight());
		setUp(getDefaultUp());
		setFront(getDefaultFront());
		return;
	}
	math::Matrix4x4 mat; 
	mat.setRotate(_obRotation);

	setRight(math::Matrix4x4::transpose(getDefaultRight(), mat));
	setUp(math::Matrix4x4::transpose(getDefaultUp(), mat));
	setFront(math::Matrix4x4::transpose(getDefaultFront(), mat));
}
