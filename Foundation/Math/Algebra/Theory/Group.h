#pragma once

namespace math
{
	/**
	*	原群
	*	原群(magma)是一种基本的代数结构，只要满足两元素作二元运算得到新元素仍属于该集合，即封闭性
	*/
	class Magma
	{
	public:
		Magma()
		{

		}
		Magma(const Magma& value)
		{

		}
	public:
		/**
		*	a属于S, b属于S, a*b属于S
		*/
		Magma doOperatorMulti(const Magma& a) const 
		{ 
			return Magma(); 
		};
	};

	/**
	*	半群
	*
	*	满足结合律(associative property)的代数结构。V=<S，* >，其中二元运算*是可结合的，即(a*b)*c=a*(b*c)，则称V是半群
	*/
	class Semigroup : public Magma
	{
	public:
		Semigroup()
		{

		}
		Semigroup(const Magma& value)
		{

		}
		Semigroup(const Semigroup& value)
		{

		}
	public:
		/**
		*	结合
		*	(a*b)*c=a*(b*c)
		*/
		Semigroup doOperatorAssociative(const Semigroup& a, const Semigroup& b)
		{
			return this->doOperatorMulti(a).doOperatorMulti(b);
		}

		bool equal(const Semigroup& a)
		{
			return false;
		}
	};

	/**
	*	幺半群
	*
	*	幺半群(monoid)在半群的基础上，还需要满足有一个单位元
	*/
	class Monoid : public Semigroup
	{
	public:
		Monoid()
		{

		}
		Monoid(const Monoid& value)
		{

		}
	public:
		/**
		*	单位元
		*	a*b=e
		*/
		static Monoid getUnit()
		{
			static Monoid sUnit;
			return sUnit;
		}
	public:
		/**
		*	除以
		*/
		Monoid doOperatorDivide(const Monoid& a) const
		{
			return Monoid();
		};
		/**
		*	倒数
		*	e / a
		*/
		Monoid getReciprocal() const
		{
			return getUnit().doOperatorDivide(*this);
		}
	};

	/**
	*	群
	*
	*	群(group)是两个元素作二元运算得到的一个新元素，需要满足群公理(group axioms)
	*	封闭性：a ∗ b is another element in the set
	*	结合律：(a ∗ b) ∗ c = a ∗ (b ∗ c)
	*	单位元：a ∗ e = a and e ∗ a = a
	*	逆  元：加法的逆元为-a，乘法的逆元为倒数1/a，… (对于所有元素)
	*/
	class Group : public Monoid
	{
	public:
		Group()
		{

		}
	public:
		static Group getZero()
		{
			static Group sGroup;
			return sGroup;
		}
	public:
		/**
		*	减去
		*/
		Group doOperatorSub(const Group& a) const
		{
			return Group();
		};
		/**
		*	逆元
		*/
		Group getNegative() const
		{
			return getZero().doOperatorSub(*this);
		}
	};

	/**
	*	阿贝尔群(交换群)
	*
	*	阿贝尔群(Abelian Group)在群的基础上，还需满足交换律
	*/
	class AbelianGroup : public Group
	{
	public:
		AbelianGroup()
		{

		}
		AbelianGroup(const Magma& value)
		{

		}
		AbelianGroup(const AbelianGroup& value)
		{

		}
	public:
		/**
		*	交换律
		*	a*b = b*a
		*/
		AbelianGroup doGroupCommutative(const AbelianGroup& a) const
		{
			return this->doOperatorMulti(a);
		}

		bool equal(const Semigroup& a) const
		{
			return false;
		}
	};
}