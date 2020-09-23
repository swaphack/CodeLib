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
		virtual bool isNone() const
		{
			return true;
		}
		/**
		*	�Ӽ�
		*	��ǰ��������Ԫ�ض��ڼ��� value ��
		*/
		bool isSubSetEqual(const Set& value) const
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
		bool isSupSetEqual(const Set& value) const
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
		Set unionAll(const Set& value) const
		{
			return value;
		}
		/**
		*	����
		*/
		Set intersect(const Set& value) const
		{
			return *this;
		}
		/**
		*	����
		*	�ų�����Ŀ���Ԫ��
		*/
		Set complementary(const Set& value) const
		{
			return *this;
		}
		/**
		*	��̼�
		*/
		Set successor() const
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