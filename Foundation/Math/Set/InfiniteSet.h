#pragma once

#include "Set.h"
#include "Function/Function.h"
#include "Basic/base.h"
#include "Basic/Interval.h"

namespace math
{
	/**
	*	无穷集
	*	不可枚举
	*	一般用区间表示
	*/
	template<typename T>
	class InfiniteSet : public Set
	{
	public:
		InfiniteSet()
		{

		}
		InfiniteSet(const InfiniteSet& value)
		{
			_interval = value.getInterval();
		}
		InfiniteSet(const Interval<T>& value)
		{
			_interval = value;
		}
		virtual ~InfiniteSet()
		{

		}
	public:
		/**
		*	是否包含元素
		*/
		virtual bool contains(const T& value) const
		{
			return _interval.contains(value);
		}
	public:
		/**
		*	是否为空
		*/
		virtual bool isEmpty() const
		{
			return _interval.isEmpty();
		}
		/**
		*	并集
		*/
		InfiniteSet getUnionSet(const InfiniteSet& value) const
		{
			return InfiniteSet(_interval.getUnionInterval(value.getInterval()));
		}
		/**
		*	交集
		*/
		InfiniteSet getIntersectSet(const InfiniteSet& value) const
		{
			return InfiniteSet(_interval.getIntersectInterval(value.getInterval()));
		}
		/**
		*	补集
		*	排除包含目标的元素
		*/
		std::vector<InfiniteSet> getComplementarySet(const InfiniteSet& value) const 
		{
			std::vector<InfiniteSet> sets;
			std::vector<Interval<T>> values = _interval.getComplementaryInterval(value.getInterval());
			if (values.size() == 0) return sets;

			for (auto item : values)
			{
				sets.push_back(InfiniteSet(item));
			}

			return sets;
		}
		/**
		*	后继集
		*/
		InfiniteSet getSuccessor() const
		{
			return *this;
		}
	public:
		const Interval<T>& getInterval() const
		{
			return _interval;
		}
	private:
		Interval<T> _interval;
	};
}