#pragma once

#include "Basic/Collection/NodeCache.h"
#include "Proposition.h"
#include "PrimaryProposition.h"
#include "BooleanProposition.h"

namespace math
{
	/**
	*	等价例子
	*/
	class EquivalenceSample
	{
	public:
		EquivalenceSample();
		virtual ~EquivalenceSample();
	public:
		/**
		*	是否是永真命题
		*/
		bool isTautologyProposition(CompoundProposition* proposition);
		/**
		*	是否是矛盾命题
		*/
		bool isContradictoryProposition(CompoundProposition* proposition);
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&T = p;
	*/
	class EquivalenceRule0 : public EquivalenceSample
	{
	public:
		EquivalenceRule0();
		virtual ~EquivalenceRule0();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|F = p;
	*/
	class EquivalenceRule1 : public EquivalenceSample
	{
	public:
		EquivalenceRule1();
		virtual ~EquivalenceRule1();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|T = T;
	*/
	class EquivalenceRule2 : public EquivalenceSample
	{
	public:
		EquivalenceRule2();
		virtual ~EquivalenceRule2();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&F = F;
	*/
	class EquivalenceRule3 : public EquivalenceSample
	{
	public:
		EquivalenceRule3();
		virtual ~EquivalenceRule3();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|p = p;
	*/
	class EquivalenceRule4 : public EquivalenceSample
	{
	public:
		EquivalenceRule4();
		virtual ~EquivalenceRule4();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&p = p;
	*/
	class EquivalenceRule5 : public EquivalenceSample
	{
	public:
		EquivalenceRule5();
		virtual ~EquivalenceRule5();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	!!p = p;
	*/
	class EquivalenceRule6 : public EquivalenceSample
	{
	public:
		EquivalenceRule6();
		virtual ~EquivalenceRule6();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|q = q|p;
	*/
	class EquivalenceRule7 : public EquivalenceSample
	{
	public:
		EquivalenceRule7();
		virtual ~EquivalenceRule7();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&q = q&p;
	*/
	class EquivalenceRule8 : public EquivalenceSample
	{
	public:
		EquivalenceRule8();
		virtual ~EquivalenceRule8();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p|q)|r = p|(q|r);
	*/
	class EquivalenceRule9 : public EquivalenceSample
	{
	public:
		EquivalenceRule9();
		virtual ~EquivalenceRule9();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p&q)&r = p&(q&r);
	*/
	class EquivalenceRule10 : public EquivalenceSample
	{
	public:
		EquivalenceRule10();
		virtual ~EquivalenceRule10();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p | (q&r) = (p|q) & (p|r);
	*/
	class EquivalenceRule11 : public EquivalenceSample
	{
	public:
		EquivalenceRule11();
		virtual ~EquivalenceRule11();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p & (q|r) = (p&q) | (p&r);
	*/
	class EquivalenceRule12 : public EquivalenceSample
	{
	public:
		EquivalenceRule12();
		virtual ~EquivalenceRule12();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p&q) = (!p) | (!q);
	*/
	class EquivalenceRule13 : public EquivalenceSample
	{
	public:
		EquivalenceRule13();
		virtual ~EquivalenceRule13();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p|q) = (!p) & (!q);
	*/
	class EquivalenceRule14 : public EquivalenceSample
	{
	public:
		EquivalenceRule14();
		virtual ~EquivalenceRule14();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|(p&q) = q;
	*/
	class EquivalenceRule15 : public EquivalenceSample
	{
	public:
		EquivalenceRule15();
		virtual ~EquivalenceRule15();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&(p|q) = q;
	*/
	class EquivalenceRule16 : public EquivalenceSample
	{
	public:
		EquivalenceRule16();
		virtual ~EquivalenceRule16();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&(!p) = F;
	*/
	class EquivalenceRule17 : public EquivalenceSample
	{
	public:
		EquivalenceRule17();
		virtual ~EquivalenceRule17();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|(!p) = T;
	*/
	class EquivalenceRule18 : public EquivalenceSample
	{
	public:
		EquivalenceRule18();
		virtual ~EquivalenceRule18();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p->q = !p | q;
	*/
	class EquivalenceRule19 : public EquivalenceSample
	{
	public:
		EquivalenceRule19();
		virtual ~EquivalenceRule19();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p->q = !q -> !p;
	*/
	class EquivalenceRule20 : public EquivalenceSample
	{
	public:
		EquivalenceRule20();
		virtual ~EquivalenceRule20();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p | q = !p -> q;
	*/
	class EquivalenceRule21 : public EquivalenceSample
	{
	public:
		EquivalenceRule21();
		virtual ~EquivalenceRule21();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p & q = !(p -> !q);
	*/
	class EquivalenceRule22 : public EquivalenceSample
	{
	public:
		EquivalenceRule22();
		virtual ~EquivalenceRule22();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p -> q) = p & !q;
	*/
	class EquivalenceRule23 : public EquivalenceSample
	{
	public:
		EquivalenceRule23();
		virtual ~EquivalenceRule23();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->q) & (p->r) = p->(q & r)
	*/
	class EquivalenceRule24 : public EquivalenceSample
	{
	public:
		EquivalenceRule24();
		virtual ~EquivalenceRule24();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->r) & (p->r) = (p | q)->r
	*/
	class EquivalenceRule25 : public EquivalenceSample
	{
	public:
		EquivalenceRule25();
		virtual ~EquivalenceRule25();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->q) | (p->r) = p->(q | r)
	*/
	class EquivalenceRule26 : public EquivalenceSample
	{
	public:
		EquivalenceRule26();
		virtual ~EquivalenceRule26();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->r) | (p->r) = (p & q)->r
	*/
	class EquivalenceRule27 : public EquivalenceSample
	{
	public:
		EquivalenceRule27();
		virtual ~EquivalenceRule27();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p<->q = (p->q) & (q->p)
	*/
	class EquivalenceRule28 : public EquivalenceSample
	{
	public:
		EquivalenceRule28();
		virtual ~EquivalenceRule28();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p<->q = !p<->!q
	*/
	class EquivalenceRule29 : public EquivalenceSample
	{
	public:
		EquivalenceRule29();
		virtual ~EquivalenceRule29();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p<->q = (p & q) | (!p & !q)
	*/
	class EquivalenceRule30 : public EquivalenceSample
	{
	public:
		EquivalenceRule30();
		virtual ~EquivalenceRule30();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p<->q) = p<->!q
	*/
	class EquivalenceRule31 : public EquivalenceSample
	{
	public:
		EquivalenceRule31();
		virtual ~EquivalenceRule31();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p<->q) = q<->p
	*/
	class EquivalenceRule32 : public EquivalenceSample
	{
	public:
		EquivalenceRule32();
		virtual ~EquivalenceRule32();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p|q)|r = q|(p|r);
	*/
	class EquivalenceRule33 : public EquivalenceSample
	{
	public:
		EquivalenceRule33();
		virtual ~EquivalenceRule33();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p&q)&r = q&(p&r);
	*/
	class EquivalenceRule34 : public EquivalenceSample
	{
	public:
		EquivalenceRule34();
		virtual ~EquivalenceRule34();
	public:
		/**
		*	获取等价式
		*/
		virtual Proposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
}