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
		*	���
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, ID, 0);
	public:
		/**
		*	����
		*/
		bool isBelongTo(const Set& set);
		/**
		*	������
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
		*	��̬���
		*/
		static uint64_t _sID;
	};
}