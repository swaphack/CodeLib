#pragma once

#include "Set.h"

#include "Element.h"

namespace math
{
	/**
	*	集合
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
		*	是否包含元素
		*/
		virtual bool contains(const Element&value) const
		{
			return false;
		}
	public:
		/**
		*	是否为空
		*/
		virtual bool isEmpty() const
		{
			return true;
		}
		/**
		*	子集
		*	当前集合所有元素都在集合 value 中
		*/
		bool isSubSetOrEqual(const Set& value) const
		{
			return true;
		}
		/**
		*	真子集
		*	当前集合的所有元素都在集合 value 中，并且两个集合不等同
		*/
		bool isSubSet(const Set& value) const
		{
			return false;
		}
		/**
		*	超集
		*	集合 value 中所有元素都在当前集合
		*/
		bool isSupSetOrEqual(const Set& value) const
		{
			return false;
		}
		/**
		*	真超集
		*	集合 value 中的所有元素都在当前集合中，并且两个集合不等同
		*/
		bool isSupSet(const Set& value) const
		{
			return false;
		}
		/**
		*	并集
		*/
		Set getUnionSet(const Set& value) const
		{
			return value;
		}
		/**
		*	交集
		*/
		Set getIntersectSet(const Set& value) const
		{
			return *this;
		}
		/**
		*	补集
		*	排除包含目标的元素
		*/
		Set getComplementarySet(const Set& value) const
		{
			return *this;
		}
		/**
		*	后继
		* 
		*	后继函数S是取得下一个序数
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
		*	空集
		*/
		const static Set* None()
		{
			static Set sNoneSet;
			return &sNoneSet;
		}
	private:

	};
}