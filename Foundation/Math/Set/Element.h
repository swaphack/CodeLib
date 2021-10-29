#pragma once

#include "Basic/base.h"

#include <cstdint>

namespace math
{
	class Set;
	/**
	*	元素
	*/
	class Element
	{
	public:
		Element();
		virtual ~Element();
	public:
		/**
		*	属于
		*/
		bool isBelongTo(const Set& set) const;
		/**
		*	不属于
		*/
		bool isNotBelongTo(const Set& set) const;
	public:
		bool operator==(const Element& value) const
		{
			return false;
		}
		bool operator!=(const Element& value) const
		{
			return true;
		}
		bool operator<(const Element& value) const
		{
			return false;
		}
		bool operator>(const Element& value) const
		{
			return true;
		}
		bool operator<=(const Element& value) const
		{
			return false;
		}
		bool operator>=(const Element& value) const
		{
			return true;
		}
	};
}