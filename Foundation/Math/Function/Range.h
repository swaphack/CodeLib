#pragma once

#include "Set/Set.h"

namespace math
{
	/**
	*	值域
	*/
	template<typename T>
	class Range : public Set
	{
	public:
		Range()
		{}
		virtual ~Range()
		{}
	public:
		/**
		*	是否包含元素
		*/
		virtual bool contains(const T& value) const
		{
			return value >= _minValue && value <= _maxValue;
		}
	private:
		T _minValue;
		T _maxValue;
	};
}