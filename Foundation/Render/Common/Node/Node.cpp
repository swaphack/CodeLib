#include "Node.h"
#include "Common/Action/ActionProxy.h"
#include "Common/Tool/Tool.h"
#include <algorithm>
#include "Graphic/import.h"
#include "Common/Scene/Camera.h"
#include "NotifyCenter.h"
#include "Common/Action/import.h"
#include "ComputeQueue.h"
#include "Common/Scene/Scene.h"
#include "Canvas.h"

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
	G_COMPUTEQUEUE->remove(this);
}

bool Node::init()
{
	// ������Ըı����
	addNotifyListener(NodeNotifyType::SPACE, [&](){
		calSpaceData(); 
	});

	addNotifyListener(NodeNotifyType::NODE, [&](){ 
		this->sortChildren();
	});

	_scheduler->setTarget(this);
	_scheduler->setHandler([this](float dt) { this->update(dt); });

	this->setCamera(G_CAMERAS->getCamera3D());

	return true;
}

void render::Node::visit()
{
	this->updateNode();
	this->drawNode();
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
void render::Node::setChildrenScene(Scene* scene)
{
	for (auto it = _children.begin(); it != _children.end(); it++)
	{
		(*it)->setChildrenScene(scene);
	}

	this->setScene(scene);
}

void Node::addChild( Node* node )
{
	Node::addChild(node, 0);
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

	node->setChildrenScene(getScene());

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
	node->setChildrenScene(nullptr);

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

int Node::getChildrenCount() const
{
	return _children.size();
}

Node* Node::getFirstChild() const
{
	if (_children.size() == 0)
	{
		return nullptr;
	}

	return _children.front();
}

Node* render::Node::getChildByIndex(int index) const
{
	if (index < 0 || index >= _children.size())
	{
		return nullptr;
	}
	return _children[index];
}

int render::Node::indexOfChild(const Node* node) const
{
	if (node == nullptr)
	{
		return -1;
	}
	for (size_t i = 0; i < _children.size(); i++)
	{
		if (_children[i] == node)
		{
			return i;
		}
	}
	return -1;
}

bool render::Node::isDescendantsOf(const Node* parent) const
{
	const Node* temp = this;
	while (temp->getParent() != nullptr)
	{
		if (temp == parent)
		{
			return true;
		}

		temp = temp->getParent();
	}

	return false;
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

void render::Node::scheduleUpdate()
{
	this->getActionProxy()->runAction(getScheduler());
}

void render::Node::unscheduleUpdate()
{
	this->getActionProxy()->stopAction(getScheduler());
}

void render::Node::update(float dt)
{
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

bool render::Node::containTouchPoint(const math::Vector2& touchPoint)
{ 
	if (!isVisible() || this->isSkipDraw())
		return false;

	if (getScene() != Canvas::getInstance()->getCurScene())
	{
		return false;
	}

	auto parent = this->getParent();
	while (parent != nullptr)
	{
		if (parent->isClippingEnabled())
		{
			if (!parent->containPoint(touchPoint))
			{
				return false;
			}
		}

		parent = parent->getParent();
	}

	return containPoint(touchPoint);
}

bool render::Node::isInFrontOf(const TouchProtocol* target) const
{
	return isInFrontOfNode(dynamic_cast<const Node*>(target));
}

bool render::Node::isInFrontOfNode(const Node* target) const
{
	if (target == nullptr || target->getParent() == nullptr)
	{
		return true;
	}
	if (this->getParent() == nullptr)
	{
		return false;
	}

	// �Ӹ��ڵ㿪ʼ�Ƚ�����λ�ù�ϵ

	std::vector<int> vecNodeInfo1;
	std::vector<int> vecNodeInfo2;

	const Node* temp = this;
	while (temp->getParent() != nullptr)
	{
		int index = temp->getParent()->indexOfChild(temp);
		vecNodeInfo1.insert(vecNodeInfo1.begin(), index);
		temp = temp->getParent();
	}

	temp = target;
	while (temp->getParent() != nullptr)
	{
		int index = temp->getParent()->indexOfChild(temp);
		vecNodeInfo2.insert(vecNodeInfo2.begin(), index);

		temp = temp->getParent();
	}

	int len = MIN(vecNodeInfo1.size(), vecNodeInfo2.size());

	for (int i = 0; i < len; i++)
	{
		if (vecNodeInfo1[i] != vecNodeInfo2[i])
		{
			return vecNodeInfo1[i] > vecNodeInfo2[i];
		}
	}

	// �϶̽ڵ����ǽϳ��ڵ����ĸ��ڵ�
	return len == vecNodeInfo2.size();
}

bool render::Node::containPoint(const math::Vector2& touchPoint)
{
	return false;
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
	// ��ֵ����
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
	// ��������1
	_children.clear();
	oIt = orderNodes.begin();
	while (oIt != orderNodes.end())
	{
		SAFE_RELEASE(*oIt);
		_children.push_back((*oIt));
		oIt++;
	}
}


// ��δ����ת��������м���
void Node::calSpaceData()
{
	//Tool::convertToOGLPoisition(_position, _obPosition);

	Tool::convertToRadian(_rotation, _obRotation);

	calRealSpaceByMatrix();

	calDirectionWithRotate();
}

void Node::calRealSpaceByMatrix()
{
	math::Matrix4x4::getRST(_obRotation, getScale(), _position, _localMatrix);

	math::SquareMatrix4 sm = _localMatrix;
	_localInverseMatrix = sm.getInverse();

	//G_COMPUTEQUEUE->pushBack(this, [this]() {
		if (this->getParent() != nullptr)
		{
			if (this->isRelativeWithParent())
			{
				const math::Matrix4x4& mat = this->getParent()->getWorldMatrix();
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
	//});

	//if (isClippingEnabled())
	{
		_worldInverseMatrix = _worldMatrix.getInverse();
	}
}

void Node::onSpaceChange()
{
	this->notifyToAll(NodeNotifyType::SPACE);
	//this->notify(NodeNotifyType::SPACE);
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

math::Vector3 render::Node::convertWorldPostitionToLocal(const math::Vector3& point) const
{
	return math::Matrix4x4::transpose(point, _worldInverseMatrix);
}

math::Vector3 render::Node::convertLocalPostitionToWorld(const math::Vector3& point) const
{
	return math::Matrix4x4::transpose(point, _worldMatrix);
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

void render::Node::addNotifyListener(NodeNotifyType id, const NotifyDelegate& func)
{
	_notify->addListen(id, func);
}

void render::Node::addNotifyListener(NodeNotifyType id, void* target, const NotifyDelegate& func)
{
	_notify->addTargetListen(id, target, func);
}

void render::Node::removeNotifyListener(NodeNotifyType id, void* target)
{
	_notify->removeTargetListen(id, target);
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
