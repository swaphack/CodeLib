#pragma once

#include "Set/Set.h"

namespace math
{
	/**
	*	ֵ��
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
		*	�Ƿ����Ԫ��
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