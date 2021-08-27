#pragma once

#include "Set.h"
#include "Function/Function.h"
#include "Basic/base.h"
#include "Basic/Interval.h"

namespace math
{
	/**
	*	���
	*	����ö��
	*	һ���������ʾ
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
		*	�Ƿ����Ԫ��
		*/
		virtual bool contains(const T& value) const
		{
			return _interval.contains(value);
		}
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isEmpty() const
		{
			return _interval.isEmpty();
		}
		/**
		*	����
		*/
		InfiniteSet getUnionSet(const InfiniteSet& value) const
		{
			return InfiniteSet(_interval.getUnionInterval(value.getInterval()));
		}
		/**
		*	����
		*/
		InfiniteSet getIntersectSet(const InfiniteSet& value) const
		{
			return InfiniteSet(_interval.getIntersectInterval(value.getInterval()));
		}
		/**
		*	����
		*	�ų�����Ŀ���Ԫ��
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
		*	��̼�
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