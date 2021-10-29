#pragma once

#include "Basic/base.h"

#include <cstdint>

namespace math
{
	class Set;
	/**
	*	Ԫ��
	*/
	class Element
	{
	public:
		Element();
		virtual ~Element();
	public:
		/**
		*	����
		*/
		bool isBelongTo(const Set& set) const;
		/**
		*	������
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