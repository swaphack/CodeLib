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
		Set();
		virtual ~Set();
	public:
		/**
		*	是否包含元素
		*/
		virtual bool contains(const Element&value) const;
	public:
		/**
		*	是否为空
		*/
		virtual bool isNone() const;
		/**
		*	子集
		*	当前集合所有元素都在集合 value 中
		*/
		bool isSubSetEqual(const Set& value) const;
		/**
		*	真子集
		*	当前集合的所有元素都在集合 value 中，并且两个集合不等同
		*/
		bool isSubSet(const Set& value) const;
		/**
		*	超集
		*	集合 value 中所有元素都在当前集合
		*/
		bool isSupSetEqual(const Set& value) const;
		/**
		*	真超集
		*	集合 value 中的所有元素都在当前集合中，并且两个集合不等同
		*/
		bool isSupSet(const Set& value) const;
		/**
		*	并集
		*/
		Set unionAll(const Set& value) const;
		/**
		*	交集
		*/
		Set intersect(const Set& value) const;
		/**
		*	补集
		*	排除包含目标的元素
		*/
		Set complementary(const Set& value) const;
		/**
		*	后继集
		*/
		Set successor() const;
	public:
		/**
		*	空集
		*/
		const static Set* None();
	};
}