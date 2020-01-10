#pragma once

#include "Number/Decimal.h"
#include "base.h"

namespace math
{
	/**
	*	界限
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
	*	小于
	*/
	class LessThan : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	小于等于
	*/
	class LessOrEqual : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	大于
	*/
	class MoreThan : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	大于等于
	*/
	class MoreOrEqual : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	等于
	*/
	class Equal : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	不等于
	*/
	class NotEqual : public Boundary
	{
	public:
		virtual bool math(const Decimal& value);
	};
}