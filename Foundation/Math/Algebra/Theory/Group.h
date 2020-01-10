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
		virtual Magma doOperatorAdd(const Magma& a) const 
		{ 
			return Magma(); 
		};
	public:
		virtual bool operator==(const Magma& a) 
		{ 
			return true; 
		}
	};

	/**
	*	半群
	*
	*	满足结合律(associative property)的代数结构。V=<S，* >，其中二元运算*是可结合的，即(a*b)*c=a*(b*c)，则称V是半群
	*/
	class Semigroup : public Magma
	{
	public:
		/**
		*	结合律
		*/
		virtual bool doGroupAssociative(const Semigroup& a, const Semigroup& b)
		{
			return this->doOperatorAdd(a).doOperatorAdd(b) == this->doOperatorAdd(a.doOperatorAdd(b));
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
		/**
		*	单位元
		*/
		virtual Monoid identity();
	protected:
	private:
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
		/**
		*	逆元
		*/
		virtual Group reverse() const { return Group(); }
	protected:
	private:
	};

	/**
	*	阿贝尔群(交换群)
	*
	*	阿贝尔群(Abelian Group)在群的基础上，还需满足交换律
	*/
	class AbelianGroup : public Group
	{
	public:
		bool doGroupCommutative(const AbelianGroup& a)
		{
			return this->doOperatorAdd(a) == a.doOperatorAdd(*this);
		}
	};
}