#pragma once

#include "Basic/base.h"

#include <cstdint>

namespace math
{
	class Set;
	/**
	*	ÔªËØ
	*/
	class Element
	{
	public:
		Element();
		virtual ~Element();
	public:
		/**
		*	±àºÅ
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, ID, 0);
	public:
		/**
		*	ÊôÓÚ
		*/
		bool isBelongTo(const Set& set);
		/**
		*	²»ÊôÓÚ
		*/
		bool isNotBelongTo(const Set& set);
	public:
		bool operator==(const Element& value) const;
		bool operator!=(const Element& value) const;
		bool operator>=(const Element& value) const;
		bool operator>(const Element& value) const;
		bool operator<(const Element& value) const;
		bool operator<=(const Element& value) const;
	private:
		/**
		*	¾²Ì¬±àºÅ
		*/
		static uint64_t _sID;
	};
}