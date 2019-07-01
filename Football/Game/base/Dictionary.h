#pragma once

#include "Identity.h"
#include <functional>
#include <cassert>
#include <list>

namespace game
{
	/**
	*	�ֵ�
	*	������ͷ�
	*/
	template<typename Key, typename Value>
	class Dictionary
	{
	protected:
		struct Node
		{
			Key key;
			Value value;
			Node* leftChild = nullptr;
			Node* rightChild = nullptr;
			/**
			*	���
			*/
			bool equals(const Key& id)
			{
				return key == id;
			}
			/**
			*	����
			*/
			bool moreThan(const Key& id)
			{
				return key > id;
			}
			/**
			*	С��
			*/
			bool lessThan(const Key& id)
			{
				return key < id;
			}

			Node(const Key& key, const Value& value)
				:key(key), value(value)
			{}
		};
	public:
		Dictionary();
		virtual ~Dictionary();
	public:
		/*
		*	�����
		*/
		void add(const Key& id, const Value& value);

		/*
		*	�Ƴ���
		*/
		void remove(const Key& id);
		/*
		*	������
		*/
		Value* find(const Key& id);
		/*
		*	���
		*/
		void clear();
		/*
		*	����
		*/
		uint64_t count();
		/*
		*	����
		*/
		void foreach(const std::function<void(const Value&)>& func);
	protected:
		/*
		*	����
		*/
		void foreach(Node* pNode, const std::function<void(Node*)>& func);
		/**
		*	���ֵ
		*/
		virtual void destoryValue(Value value) {}
		/**
		*	����ڵ�
		*/
		void destory(Node* pNode);
	private:
		// ���ڵ� ������
		Node* m_pRoot = nullptr;
		// �ڵ�����
		uint64_t m_nCount = 0;
	};

	template<typename Key, typename Value>
	Value* Dictionary<Key, Value>::find(const Key& id)
	{
		if (m_pRoot == nullptr)
		{
			return nullptr;
		}

		Node* pNode = m_pRoot;
		while (pNode)
		{
			if (pNode->equals(id))
			{
				return &pNode->value;
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


	template<typename Key, typename Value>
	void Dictionary<Key, Value>::foreach(Node* pNode, const std::function<void(Node*)>& func)
	{
		if (pNode == nullptr || func == nullptr)
		{
			return;
		}
		func(pNode);
		foreach(pNode->leftChild, func);
		foreach(pNode->rightChild, func);
	}

	template<typename Key, typename Value>
	void Dictionary<Key, Value>::foreach(const std::function<void(const Value&)>& func)
	{
		if (func == nullptr)
		{
			return;
		}
		foreach(m_pRoot, [func](Node* pNode){
			func(pNode->value);
		});
	}

	template<typename Key, typename Value>
	uint64_t Dictionary<Key, Value>::count()
	{
		return m_nCount;
	}

	template<typename Key, typename Value>
	void Dictionary<Key, Value>::clear()
	{
		if (m_pRoot == nullptr)
		{
			return;
		}

		std::list<Node*> lstNode;
		this->foreach(m_pRoot, [&lstNode](Node* pNode){
			lstNode.push_back(pNode);
		});

		for (auto it = lstNode.begin(); it != lstNode.end(); it++)
		{
			destory(*it);
		}

		m_pRoot = nullptr;
	}

	template<typename Key, typename Value>
	void Dictionary<Key, Value>::remove(const Key& id)
	{
		if (m_pRoot == nullptr)
		{
			return;
		}

		Node* pNode = m_pRoot;
		Node* pLastNode = m_pRoot;
		while (true)
		{
			if (pNode == nullptr)
			{
				break;
			}
			if (pNode->equals(id))
			{
				if (pLastNode->leftChild == pNode)
				{// ���֧
					Node* pLeftNode = pNode->leftChild;
					Node* pRightNode = pNode->rightChild;
					if (pLeftNode)
					{
						pLastNode->leftChild = pLeftNode;
						auto pTempNode = pLeftNode;
						while (pTempNode)
						{
							if (pTempNode->rightChild == nullptr)
							{
								pTempNode->rightChild = pRightNode;
								break;
							}
							else
							{
								pTempNode = pTempNode->rightChild;
							}
						}
					}
					else
					{
						pLastNode->leftChild = pRightNode;
					}
				}
				else if (pLastNode->rightChild == pNode)
				{// �ҷ�֧
					Node* pLeftNode = pNode->leftChild;
					Node* pRightNode = pNode->rightChild;
					if (pRightNode)
					{
						pLastNode->rightChild = pRightNode;
						auto pTempNode = pRightNode;
						while (pTempNode)
						{
							if (pTempNode->leftChild == nullptr)
							{
								pTempNode->leftChild = pLeftNode;
								break;
							}
							else
							{
								pTempNode = pTempNode->leftChild;
							}
						}
					}
					else
					{
						pLastNode->rightChild = pLeftNode;
					}
				}
				m_nCount--;
				if (m_nCount == 0)
				{
					m_pRoot = nullptr;
				}
				destory(pNode);
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

	template<typename Key, typename Value>
	void Dictionary<Key, Value>::add(const Key& id, const Value& value)
	{
		if (m_pRoot == nullptr)
		{
			m_pRoot = new Node(id, value);
			m_nCount++;
			return;
		}

		Node* pNode = m_pRoot;
		while (true)
		{
			if (pNode->moreThan(id))
			{
				if (pNode->leftChild == nullptr)
				{
					pNode->leftChild = new Node(id, value);
					m_nCount++;
					break;
				}
				else
				{
					pNode = pNode->leftChild;
				}
			}
			else if (pNode->lessThan(id))
			{
				if (pNode->rightChild == nullptr)
				{
					pNode->rightChild = new Node(id, value);
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
				assert(pNode->value != value);
				assert(!pNode->equals(id));
			}
		}
	}

	template<typename Key, typename Value>
	Dictionary<Key, Value>::~Dictionary()
	{
		this->clear();
	}

	template<typename Key, typename Value>
	Dictionary<Key, Value>::Dictionary()
	{

	}

	template<typename Key, typename Value>
	void Dictionary<Key, Value>::destory(Node* pNode)
	{
		destoryValue(pNode->value);
		delete pNode;
	}
}