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
		Set();
		virtual ~Set();
	public:
		/**
		*	�Ƿ����Ԫ��
		*/
		virtual bool contains(const Element&value) const;
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isNone() const;
		/**
		*	�Ӽ�
		*	��ǰ��������Ԫ�ض��ڼ��� value ��
		*/
		bool isSubSetEqual(const Set& value) const;
		/**
		*	���Ӽ�
		*	��ǰ���ϵ�����Ԫ�ض��ڼ��� value �У������������ϲ���ͬ
		*/
		bool isSubSet(const Set& value) const;
		/**
		*	����
		*	���� value ������Ԫ�ض��ڵ�ǰ����
		*/
		bool isSupSetEqual(const Set& value) const;
		/**
		*	�泬��
		*	���� value �е�����Ԫ�ض��ڵ�ǰ�����У������������ϲ���ͬ
		*/
		bool isSupSet(const Set& value) const;
		/**
		*	����
		*/
		Set unionAll(const Set& value) const;
		/**
		*	����
		*/
		Set intersect(const Set& value) const;
		/**
		*	����
		*	�ų�����Ŀ���Ԫ��
		*/
		Set complementary(const Set& value) const;
		/**
		*	��̼�
		*/
		Set successor() const;
	public:
		/**
		*	�ռ�
		*/
		const static Set* None();
	};
}