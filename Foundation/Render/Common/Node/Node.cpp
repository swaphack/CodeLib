#include "Node.h"
#include "../Touch/TouchProxy.h"
#include <algorithm>
#include "Graphic/import.h"

using namespace render;

//////////////////////////////////////////////////////////////////////////

#define USE_MATRIX true

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
	_bUseMatrix = USE_MATRIX;

	this->setVisible(true);

	_notify = new Notify();
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
		Tool::calRect(math::Vector3(), _volume, _anchor, _rectVertex);
		
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

	_children.addObject(node);

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

	_children.removeObject(node);

	onChildrenChange();
}

void Node::removeAllChildren()
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
	onChildrenChange();
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

Node* Node::getFirstChild()
{
	if (_children.count() == 0)
	{
		return nullptr;
	}

	return static_cast<Node*>(*_children.begin());
}

std::vector<sys::Object*>::iterator Node::beginChild()
{
	return _children.begin();
}

std::vector<sys::Object*>::iterator Node::endChild()
{
	return _children.end();
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

	// 数值计算
	if (isDirty())
	{
		this->initSelf();

		setDirty(false);
	}

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

const RectVertex& Node::getRectVertex()
{
	return _rectVertex;
}

void Node::draw()
{

}

void Node::updateTranform()
{
	if (_bUseMatrix)
	{
		G_DRAWCOMMANDER->addCommand(DCSpaceMatrix::create(_mat44, _bRelative));
	}
	else
	{
		G_DRAWCOMMANDER->addCommand(DCSpace::create(_obPosition, _scale, _rotation, _bRelative));
	}
	
}

void Node::updateSelf()
{
	this->updateTranform();
}

void Node::initSelf()
{
	_notify->notify();
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
	if (_bUseMatrix)
	{
		calRealSpaceByMatrix();
	}
	else
	{
		calRealSpaceByValue();
	}
}

void Node::calRealSpaceByValue()
{
	Node* temp = this;
	math::Vector3 position;
	math::Vector3 scale = math::Vector3(1, 1, 1);
	math::Volume volume = _volume;
	do
	{
		position += temp->getPosition();
		scale *= temp->getScale();

		if (!temp->isRelativeWithParent())
		{
			break;
		}
		else
		{
			temp = temp->getParent();
		}
	} while (temp != NULL);
	volume *= scale;

	Tool::calRealRect(position, volume, _anchor, _realSpaceVertex);

	_realBodySpace.position = position;
	_realBodySpace.volume = volume;
}

void Node::calRealSpaceByMatrix()
{
	math::Matrix44 matScale;
	matScale.setScale(getScale());
	math::Matrix44 matRotate;
	matRotate.setRotate(_obRotation);
	math::Matrix44 matTranslate;
	matTranslate.setTranslate(_obPosition);

	//printf("Scale\n%s\n", matScale.toString().c_str());
	//printf("Rotate\n%s\n", matRotate.toString().c_str());
	//printf("Translate\n%s\n", matTranslate.toString().c_str());

	_mat44 = matTranslate * matRotate * matScale;

	//printf("mat\n%s\n", _mat44.toString().c_str());

	Node* temp = this;
	std::vector<math::Matrix44> vecMat;
	do
	{
		vecMat.insert(vecMat.begin(), temp->getMatrix());
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

	_realMat44 = ret;
}

void Node::onSpaceChange()
{
	setDirty(true);
	_notify->addMark(ENP_SPACE);
}

void Node::onBodyChange()
{
	setDirty(true);
	_notify->addMark(ENP_SPACE);
}

void Node::onChildrenChange()
{
	setDirty(true);
	_notify->addMark(ENP_NODE);
}

const math::Matrix44& Node::getRealMatrix()
{
	return _realMat44;
}

const math::Matrix44& Node::getMatrix()
{
	return _mat44;
}
