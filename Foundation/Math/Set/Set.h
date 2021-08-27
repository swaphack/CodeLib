#pragma once

#include "Set.h"

#include "Element.h"

namespace math
{
	/**
	*	����
	*/
	class Set : public Element
	{
	public:
		Set() 
		{
		}
		virtual ~Set() 
		{
		}
	public:
		/**
		*	�Ƿ����Ԫ��
		*/
		virtual bool contains(const Element&value) const
		{
			return false;
		}
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isEmpty() const
		{
			return true;
		}
		/**
		*	�Ӽ�
		*	��ǰ��������Ԫ�ض��ڼ��� value ��
		*/
		bool isSubSetOrEqual(const Set& value) const
		{
			return true;
		}
		/**
		*	���Ӽ�
		*	��ǰ���ϵ�����Ԫ�ض��ڼ��� value �У������������ϲ���ͬ
		*/
		bool isSubSet(const Set& value) const
		{
			return false;
		}
		/**
		*	����
		*	���� value ������Ԫ�ض��ڵ�ǰ����
		*/
		bool isSupSetOrEqual(const Set& value) const
		{
			return false;
		}
		/**
		*	�泬��
		*	���� value �е�����Ԫ�ض��ڵ�ǰ�����У������������ϲ���ͬ
		*/
		bool isSupSet(const Set& value) const
		{
			return false;
		}
		/**
		*	����
		*/
		Set getUnionSet(const Set& value) const
		{
			return value;
		}
		/**
		*	����
		*/
		Set getIntersectSet(const Set& value) const
		{
			return *this;
		}
		/**
		*	����
		*	�ų�����Ŀ���Ԫ��
		*/
		Set getComplementarySet(const Set& value) const
		{
			return *this;
		}
		/**
		*	���
		* 
		*	��̺���S��ȡ����һ������
		*	S(a) = a U {a}
		* 
		*	a + 0 = a
		*	a + S(b) = S(a+b)
		*/
		Set getSuccessor() const
		{
			return *this;
		}
	public:
		bool operator==(const Set& value) const
		{
			return false;
		}
		bool operator!=(const Set& value) const
		{
			return true;
		}
	public:
		/**
		*	�ռ�
		*/
		const static Set* None()
		{
			static Set sNoneSet;
			return &sNoneSet;
		}
	private:

	};
}