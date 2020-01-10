#pragma once

#pragma once

#include "Group.h"

namespace math
{
	/**
	*	环
	*
	*	环(ring)在阿贝尔群(也叫交换群)的基础上，添加一种二元运算·(虽叫乘法，但不同于初等代数的乘法)。
	*	一个代数结构是环(R, +, ·)，需要满足环公理(ring axioms)，如(Z,+, ⋅)。
	*
	*	环公理如下：
	*	(1)(R, +)是交换群
	*	封闭性：a + b is another element in the set
	*	结合律：(a + b) + c = a + (b + c)
	*	单位元：加法的单位元为0，a + 0 = a and 0 + a = a
	*	逆  元：加法的逆元为-a，a + (−a) = (−a) + a = 0 (对于所有元素)
	*	交换律：a + b = b + a
	*
	*	(2)(R, ·)是幺半群
	*	结合律：(a ⋅ b) ⋅ c = a ⋅ (b ⋅ c)
	*	单位元：乘法的单位元为1，a ⋅ 1 = a and 1 ⋅ a = a
	*	(3)乘法对加法满足分配律Multiplication distributes over addition
	*	
	*	a ⋅ (b + c) = (a ⋅ b) + (a ⋅ c) for all a, b, c in R (left distributivity)
	*	(b + c) ⋅ a = (b ⋅ a) + (c ⋅ a) for all a, b, c in R (right distributivity)
	*/
	class Ring : public AbelianGroup
	{
	public:
		virtual Ring doRingMul(const Ring& a) const
		{
			return Ring();
		}
	public:
		virtual bool operator!=(const Ring& a)
		{
			return true;
		}
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	交换环(commutative ring)
	*	在环的基础上，二元运算乘法还满足交换律
	*/
	class CommutativeRing : public Ring
	{
	public:
		virtual bool doRingCommutative(const CommutativeRing& a)
		{
			return this->doRingMul(a) == a.doRingMul(*this);
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	整环(integral domain)在交换环的基础上，并满足没有零因子
	*	(如此，集合内任意两个元素乘积均不等于0)
	*/
	class IntegralDomain : public CommutativeRing
	{
	public:
		/**
		*	零因子
		*/
		virtual IntegralDomain zero() 
		{ 
			return IntegralDomain(); 
		}
	public:
		
	public:
		bool doDomainMul(const IntegralDomain& a)
		{
			return this->doRingMul(a) != zero();
		}
	};
}