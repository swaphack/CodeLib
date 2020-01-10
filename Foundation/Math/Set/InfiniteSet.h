#pragma once

#include "Set.h"
#include "Function/Function.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	无穷集
	*	不可枚举
	*	一般用函数表示
	*/
	class InfiniteSet : public Set
	{
	public:
		InfiniteSet();
		InfiniteSet(const InfiniteSet& value);
		virtual ~InfiniteSet();
	public:
		/**
		*	定义域
		*/
		CREATE_CLASS_MEMBER(Domain, Domain);
		/**
		*	控制函数
		*/
		CREATE_CLASS_MEMBER(Function, Function);
	public:
		/**
		*	是否包含元素
		*/
		virtual bool contains(const Element* value) const;
	public:
		/**
		*	是否为空
		*/
		virtual bool isNone() const;
		/**
		*	并集
		*/
		InfiniteSet unionAll(const InfiniteSet& value) const;
		/**
		*	交集
		*/
		InfiniteSet intersect(const InfiniteSet& value) const;
		/**
		*	补集
		*	排除包含目标的元素
		*/
		InfiniteSet complementary(const InfiniteSet& value) const;
		/**
		*	后继集
		*/
		InfiniteSet successor() const;
	};
}