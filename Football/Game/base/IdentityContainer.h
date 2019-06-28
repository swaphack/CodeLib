#pragma once

#include "Identity.h"
#include <map>
#include <functional>

namespace game
{
	/**
	*	id����
	*	����id���ͷ�
	*/
	class IdentityContainer
	{
	private:
		struct IdentityNode
		{
			Identity* value = nullptr;
			IdentityNode* leftChild = nullptr;
			IdentityNode* rightChild = nullptr;
			/**
			*	���
			*/
			bool equals(uint64_t id);
			/**
			*	����
			*/
			bool moreThan(uint64_t id);
			/**
			*	С��
			*/
			bool lessThan(uint64_t id);

			IdentityNode(Identity* value);

			~IdentityNode();
		};
	public:
		IdentityContainer();
		virtual ~IdentityContainer();
	public:
		/*
		*	�����
		*/
		void add(Identity* ptrIdentity);
		/*
		*	�Ƴ���
		*/
		void remove(uint64_t id);
		/*
		*	������
		*/
		Identity* find(uint64_t id);
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
		void foreach(const std::function<void(Identity*)>& func);
	protected:
		/*
		*	����
		*/
		void foreach(IdentityNode* pNode, const std::function<void(IdentityNode*)>& func);
	private:
		// ���ڵ� ������
		IdentityNode* m_pRoot = nullptr;
		uint64_t m_nCount = 0;
	};
}