#pragma once

#include "Number/Decimal.h"
#include "base.h"

namespace math
{
	/**
	*	����
	*/
	class Boundary
	{
	public:
		Boundary();
		virtual ~Boundary();
	public:
		CREATE_CLASS_MEMBER(Decimal, Value);
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	С��
	*/
	class LessThan : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	С�ڵ���
	*/
	class LessOrEqual : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	����
	*/
	class MoreThan : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	���ڵ���
	*/
	class MoreOrEqual : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	����
	*/
	class Equal : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	������
	*/
	class NotEqual : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
}