#pragma once

#include "Identity.h"
#include <map>
#include <functional>

namespace game
{
	/**
	*	�б�
	*/
	template<typename T>
	class List
	{
	protected:
		struct Node
		{
			T value;
			Node* next = nullptr;

			Node(const T& value)
				:value(value)
			{
			}
			/**
			*	���
			*/
			bool equals(const T& value)
			{
				return this->value == value;
			}
		};
	public:
		List();
		virtual ~List();
	public:
		void add(const T& value);
		/**
		*	�Ƴ�
		*/
		void remove(const T& value);
		/**
		*	�Ƴ�
		*/
		void removeAt(uint32_t index);
		/**
		*	����
		*/
		virtual T& operator[](uint32_t index);
		/**
		*	���
		*/
		void clear();
		/**
		*	����
		*/
		uint64_t count();
		/**
		*	����
		*/
		void foreach(const std::function<void(const T&)>& func);
	protected:
		/**
		*	����
		*/
		void foreach(Node* pNode, const std::function<void(Node*)>& func);
		/**
		*	���ֵ
		*/
		virtual void destoryValue(T value) {}
		/**
		*	����ڵ�
		*/
		void destory(Node* pNode);
	private:
		// ���ڵ� ����
		Node* m_pRoot = nullptr;
		// �ڵ�����
		uint64_t m_nCount = 0;
	};

	template<typename T>
	void List<T>::foreach(Node* pNode, const std::function<void(Node*)>& func)
	{
		if (pNode == nullptr || func == nullptr)
		{
			return;
		}
		func(pNode);
		foreach(pNode->next, func);
	}

	template<typename T>
	void List<T>::foreach(const std::function<void(const T&)>& func)
	{
		if (func == nullptr)
		{
			return;
		}
		foreach(m_pRoot, [func](Node* pNode){
			func(pNode->value);
		});
	}

	template<typename T>
	void List<T>::destory(Node* pNode)
	{
		destoryValue(pNode->value);
		delete pNode;
	}

	template<typename T>
	uint64_t List<T>::count()
	{
		return m_nCount;
	}

	template<typename T>
	void List<T>::clear()
	{
		Node* pNode = m_pRoot;
		while (pNode)
		{
			Node* pTemp = pNode->next;
			destory(pNode);
			pNode = pTemp;
		}

		m_pRoot = nullptr;
		m_nCount = 0;
	}

	template<typename T>
	T& List<T>::operator[](uint32_t index)
	{
		assert(index < m_nCount);

		Node* pNode = m_pRoot;
		for (uint32_t i = 0; i < index; i++)
		{
			pNode = pNode->next;
		}

		return pNode->value;
	}

	template<typename T>
	void List<T>::removeAt(uint32_t index)
	{
		assert(index < m_nCount);

		Node* pNode = m_pRoot;
		Node* pLastNode = nullptr;
		for (uint32_t i = 0; i < index; i++)
		{
			pLastNode = pNode;
			pNode = pNode->next;
		}

		if (pLastNode == nullptr)
		{
			m_pRoot = pNode->next;
		}
		else
		{
			pLastNode->next = pNode->next;
		}

		destory(pNode);
		m_nCount--;
	}

	template<typename T>
	void List<T>::remove(const T& value)
	{
		Node* pNode = m_pRoot;
		Node* pLastNode = nullptr;
		while (pNode)
		{
			if (pNode->equals(value))
			{
				if (pLastNode == nullptr)
				{
					m_pRoot = pNode->next;
				}
				else
				{
					pLastNode->next = pNode->next;
				}
				destory(pNode);
				m_nCount--;
				break;
			}
			else
			{
				pLastNode = pNode;
				pNode = pNode->next;
			}
		}
	}

	template<typename T>
	void List<T>::add(const T& value)
	{
		if (m_pRoot == nullptr)
		{
			m_pRoot = new Node(value);
			m_nCount++;
			return;
		}

		Node* pNode = m_pRoot;
		while (pNode)
		{
			if (pNode->next == nullptr)
			{
				Node* pTemp = new Node(value);
				pNode->next = pTemp;
				m_nCount++;
				break;
			}
			else
			{
				pNode = pNode->next;
			}
		}
		
	}

	template<typename T>
	List<T>::~List()
	{

	}

	template<typename T>
	List<T>::List()
	{
		this->clear();
	}

}