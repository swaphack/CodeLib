#pragma once

#include <set>
#include <cstdint>

#include "Set.h"

namespace math
{
	/**
	*	有穷集
	*	可枚举
	*/
	class FiniteSet : public Set
	{
	public:
		FiniteSet();
		FiniteSet(const FiniteSet& value);
		virtual ~FiniteSet();
	public:
		/**
		*	是否包含元素
		*/
		virtual bool contains(const Element& value) const;
	public:
		/**
		*	添加元素
		*/
		void addElement(const Element& value);
		/**
		*	移除元素
		*/
		void removeElement(const Element& value);
		/**
		*	移除所有元素
		*/
		void removeAllElements();
		/**
		*	所有元素
		*/
		const std::set<Element>& getAllElements() const;
		/**
		*	元素个数
		*/
		int32_t getCount() const;
	public:
		/**
		*	是否为空
		*/
		virtual bool isNone() const;
		/**
		*	子集
		*	是否是目标的子集
		*	当前集合所有元素都在集合 value 中
		*/
		bool isSubSetEqual(const FiniteSet& value) const;
		/**
		*	真子集
		*	是否是目标的真子集
		*	当前集合的所有元素都在集合 value 中，并且两个集合不等同
		*/
		bool isSubSet(const FiniteSet& value) const;
		/**
		*	超集
		*	是否是目标的超集
		*	集合 value 中所有元素都在当前集合
		*/
		bool isSupSetEqual(const FiniteSet& value) const;
		/**
		*	真超集
		*	是否是目标的真超集
		*	集合 value 中的所有元素都在当前集合中，并且两个集合不等同
		*/
		bool isSupSet(const FiniteSet& value) const;
		/**
		*	并集
		*/
		FiniteSet unionAll(const FiniteSet& value) const;
		/**
		*	交集
		*/
		FiniteSet intersect(const FiniteSet& value) const;
		/**
		*	补集
		*	排除包含目标的元素
		*/
		FiniteSet complementary(const FiniteSet& value) const;
		/**
		*	后继集
		*	排除包含目标的元素
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
		*	元素
		*/
		std::set<Element> _elements;
	};
}