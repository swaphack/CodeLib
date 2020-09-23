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
		virtual bool isNone() const
		{
			return true;
		}
		/**
		*	子集
		*	当前集合所有元素都在集合 value 中
		*/
		bool isSubSetEqual(const Set& value) const
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
		bool isSupSetEqual(const Set& value) const
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
		Set unionAll(const Set& value) const
		{
			return value;
		}
		/**
		*	交集
		*/
		Set intersect(const Set& value) const
		{
			return *this;
		}
		/**
		*	补集
		*	排除包含目标的元素
		*/
		Set complementary(const Set& value) const
		{
			return *this;
		}
		/**
		*	后继集
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