#include "IdentityContainer.h"
#include <assert.h>
#include <list>

using namespace game;
IdentityContainer::IdentityNode::IdentityNode(Identity* value) :value(value)
{

}

IdentityContainer::IdentityNode::~IdentityNode()
{
	if (value)
	{
		delete value;
	}
}

bool IdentityContainer::IdentityNode::lessThan(uint64_t id)
{
	if (value == nullptr)
	{
		return false;
	}

	return id < value->getID();
}

bool IdentityContainer::IdentityNode::moreThan(uint64_t id)
{
	if (value == nullptr)
	{
		return false;
	}

	return id > value->getID();
}

bool IdentityContainer::IdentityNode::equals(uint64_t id)
{
	if (value == nullptr)
	{
		return false;
	}

	return id == value->getID();
}

//////////////////////////////////////////////////////////////////////////

IdentityContainer::IdentityContainer()
{

}

IdentityContainer::~IdentityContainer()
{
	this->clear();
}

void IdentityContainer::add(Identity* ptrIdentity)
{
	if (ptrIdentity == nullptr)
	{
		return;
	}

	if (m_pRoot == nullptr)
	{
		m_pRoot = new IdentityNode(ptrIdentity);
		m_nCount++;
		return;
	}

	IdentityNode* pNode = m_pRoot;
	while (true)
	{
		if (pNode->moreThan(ptrIdentity->getID()))
		{
			if (pNode->leftChild == nullptr)
			{
				pNode->leftChild = new IdentityNode(ptrIdentity);
				m_nCount++;
				break;
			}
			else
			{
				pNode = pNode->leftChild;
			}
		}
		else if (pNode->lessThan(ptrIdentity->getID()))
		{
			if (pNode->rightChild == nullptr)
			{
				pNode->rightChild = new IdentityNode(ptrIdentity);
				m_nCount++;
				break;
			}
			else
			{
				pNode = pNode->rightChild;
			}
		}
		else
		{
			assert(pNode->value != ptrIdentity);
			assert(!pNode->equals(ptrIdentity->getID()));
		}
	}
}

void IdentityContainer::remove(uint64_t id)
{
	if (m_pRoot == nullptr)
	{
		return;
	}

	IdentityNode* pNode = m_pRoot;
	IdentityNode* pLastNode = nullptr;
	while (true)
	{
		if (pNode == nullptr)
		{
			break;
		}
		if (pNode->equals(id))
		{
			if (pLastNode->leftChild == pNode)
			{// 左分支
				IdentityNode* pLeftNode = pNode->leftChild;
				IdentityNode* pRightNode = pNode->rightChild;
				if (pLeftNode)
				{
					pLastNode->leftChild = pLeftNode;
					while (pLeftNode)
					{
						pLeftNode = pLastNode->rightChild;
						if (pLeftNode->rightChild == nullptr)
						{
							pLeftNode->rightChild = pRightNode;
							break;
						}
					}
				}
				else
				{
					pLastNode->leftChild = pRightNode;
				}
			}
			else if (pLastNode->rightChild == pNode)
			{// 右分支
				IdentityNode* pLeftNode = pNode->leftChild;
				IdentityNode* pRightNode = pNode->rightChild;
				if (pRightNode)
				{
					pLastNode->rightChild = pRightNode;
					while (pRightNode)
					{
						pRightNode = pLastNode->rightChild;
						if (pRightNode->leftChild == nullptr)
						{
							pRightNode->leftChild = pLeftNode;
							break;
						}
					}
				}
				else
				{
					pLastNode->rightChild = pLeftNode;
				}
			}
			m_nCount--;
			break;
		}
		else if (pNode->moreThan(id))
		{
			pLastNode = pNode;
			pNode = pNode->leftChild;
		}
		else if (pNode->lessThan(id))
		{
			pLastNode = pNode;
			pNode = pNode->rightChild;
		}
	}
}

Identity* IdentityContainer::find(uint64_t id)
{
	if (m_pRoot == nullptr)
	{
		return nullptr;
	}

	IdentityNode* pNode = m_pRoot;
	while (pNode)
	{
		if (pNode->equals(id))
		{
			return pNode->value;
		}
		else if (pNode->moreThan(id))
		{
			pNode = pNode->leftChild;
		}
		else if (pNode->lessThan(id))
		{
			pNode = pNode->rightChild;
		}
	}

	return nullptr;
}

void IdentityContainer::clear()
{
	if (m_pRoot == nullptr)
	{
		return;
	}

	std::list<IdentityNode*> lstNode;
	this->foreach(m_pRoot, [&lstNode](IdentityNode* pNode){
		lstNode.push_back(pNode);
	});

	for (auto it = lstNode.begin(); it != lstNode.end(); it++)
	{
		delete (*it);
	}

	m_pRoot = nullptr;
}

uint64_t IdentityContainer::count()
{
	return m_nCount;
}

void IdentityContainer::foreach(const std::function<void(Identity*)>& func)
{
	if (func == nullptr)
	{
		return;
	}
	foreach(m_pRoot, [func](IdentityNode* pNode){
		func(pNode->value);
	});
}

void IdentityContainer::foreach(IdentityNode* pNode, const std::function<void(IdentityNode*)>& func)
{
	if (pNode == nullptr || func == nullptr)
	{
		return;
	}
	func(pNode);
	foreach(pNode->leftChild, func);
	foreach(pNode->rightChild, func);
}
