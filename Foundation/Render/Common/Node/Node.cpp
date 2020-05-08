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
, _bRelative(true)
, _zOrder(0.0f)
, _touchProxy(nullptr)
{
	this->setVisible(true);

	_notify = new Notify<int>();
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
	_notify->addListen(ENP_SPACE, [&](){
		Tool::convertToOGLPoisition(_position, _obPosition);
		Tool::convertToRadian(_rotation, _obRotation);
		calRealSpaceInfo(); 
	});

	_notify->addListen(ENP_NODE, [&](){ this->sortChildren(); });

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
	ASSERT(node != nullptr && node->getParent() == nullptr);

	if (node->getParent() == this)
	{
		return;
	}

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

void Node::visit()
{
	if (this->isVisible() == false)
	{
		return;
	}

	this->notifyEvents();	
		
	this->updateTranform();

	if (_children.size() == 0)
	{
		this->drawNode();
	}
	else
	{
		bool show = false;
		auto it = _children.begin();
		while (it != _children.end())
		{
			Node* node = *it;
			if (show == false && node->getZOrder() >= 0)
			{
				this->drawNode();
				show = true;
			}
			node->visit();
			it++;
		}
	}

	this->inverseTranform();
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
	return false;
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

void Node::updateTranform()
{
	if (!this->isRelativeWithParent())
	{
		GLMatrix::pushMatrix();
		GLMatrix::loadIdentity();
	}

	GLMatrix::multMatrix(_localMat);

	GLDebug::showError();
}

void Node::inverseTranform()
{
	GLMatrix::multMatrix(_localInverseMat);

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
		SAFE_RELEASE(*oIt);
		_children.push_back((*oIt));
		oIt++;
	}
}


// 还未对旋转后坐标进行计算
void Node::calRealSpaceInfo()
{
	calRealSpaceByMatrix();
}

void Node::calRealSpaceByMatrix()
{
	math::Matrix44 matScale;
	matScale.setScale(getScale());
	math::Matrix44 matRotate;
	matRotate.setRotate(_obRotation);
	math::Matrix44 matTranslate;
	matTranslate.setTranslate(_obPosition);

	//PRINT("Scale\n%s\n", matScale.toString().c_str());
	//PRINT("Rotate\n%s\n", matRotate.toString().c_str());
	//PRINT("Translate\n%s\n", matTranslate.toString().c_str());

	_localMat = matTranslate * matRotate * matScale;
	_localInverseMat = _localMat.getInverse();

	//PRINT("mat\n%s\n", _mat44.toString().c_str());

	Node* temp = this;
	std::vector<math::Matrix44> vecMat;
	do
	{
		vecMat.insert(vecMat.begin(), temp->getLocalMatrix());
		if (!temp->isRelativeWithParent())
		{
			break;
		}
		else
		{
			temp = temp->getParent();
		}
	} while (temp != NULL);

	math::Matrix44 ret;
	for (auto &item : vecMat)
	{
		ret = item * ret;
	}

	_worldMat = ret;
}

void Node::onSpaceChange()
{
	this->notify(ENP_SPACE);
}

void Node::onBodyChange()
{
	this->notify(ENP_SPACE);
}

void Node::onChildrenChange()
{
	this->notify(ENP_NODE);
}

const math::Matrix44& Node::getWorldMatrix()
{
	return _worldMat;
}

const math::Matrix44& Node::getLocalMatrix()
{
	return _localMat;
}

void Node::drawNode()
{
	this->draw();

	GLDebug::showError();
}

void Node::notify(int id)
{
	_notify->addMark(id);
	setDirty(true);
}

void render::Node::notifyToAll(int id)
{
	this->notify(id);

	for (auto it = _children.begin(); it != _children.end(); it++)
	{
		(*it)->notifyToAll(id);
	}
}