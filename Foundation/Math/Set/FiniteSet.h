#pragma once

#include <set>
#include <cstdint>

#include "Set.h"

namespace math
{
	/**
	*	���
	*	��ö��
	*/
	class FiniteSet : public Set
	{
	public:
		FiniteSet();
		FiniteSet(const FiniteSet& value);
		virtual ~FiniteSet();
	public:
		/**
		*	�Ƿ����Ԫ��
		*/
		virtual bool contains(const Element& value) const;
	public:
		/**
		*	���Ԫ��
		*/
		void addElement(const Element& value);
		/**
		*	�Ƴ�Ԫ��
		*/
		void removeElement(const Element& value);
		/**
		*	�Ƴ�����Ԫ��
		*/
		void removeAllElements();
		/**
		*	����Ԫ��
		*/
		const std::set<Element>& getAllElements() const;
		/**
		*	Ԫ�ظ���
		*/
		int32_t getCount() const;
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isNone() const;
		/**
		*	�Ӽ�
		*	�Ƿ���Ŀ����Ӽ�
		*	��ǰ��������Ԫ�ض��ڼ��� value ��
		*/
		bool isSubSetEqual(const FiniteSet& value) const;
		/**
		*	���Ӽ�
		*	�Ƿ���Ŀ������Ӽ�
		*	��ǰ���ϵ�����Ԫ�ض��ڼ��� value �У������������ϲ���ͬ
		*/
		bool isSubSet(const FiniteSet& value) const;
		/**
		*	����
		*	�Ƿ���Ŀ��ĳ���
		*	���� value ������Ԫ�ض��ڵ�ǰ����
		*/
		bool isSupSetEqual(const FiniteSet& value) const;
		/**
		*	�泬��
		*	�Ƿ���Ŀ����泬��
		*	���� value �е�����Ԫ�ض��ڵ�ǰ�����У������������ϲ���ͬ
		*/
		bool isSupSet(const FiniteSet& value) const;
		/**
		*	����
		*/
		FiniteSet unionAll(const FiniteSet& value) const;
		/**
		*	����
		*/
		FiniteSet intersect(const FiniteSet& value) const;
		/**
		*	����
		*	�ų�����Ŀ���Ԫ��
		*/
		FiniteSet complementary(const FiniteSet& value) const;
		/**
		*	��̼�
		*	�ų�����Ŀ���Ԫ��
		*/
		FiniteSet successor() const;
	public:
		FiniteSet operator+(const Element& value) const;
		FiniteSet operator-(const Element& value) const;
		FiniteSet& operator+=(const Element& value);
		FiniteSet& operator-=(const Element& value);
	public:
		FiniteSet& operator=(const FiniteSet& value);
		bool operator==(const FiniteSet& value) const;
		bool operator!=(const FiniteSet& value) const;
	public:
	private:
		/**
		*	Ԫ��
		*/
		std::set<Element> _elements;
	};
}