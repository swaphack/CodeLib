#pragma once

#include "Basic/Collection/NodeCache.h"
#include "Proposition.h"
#include "PrimaryProposition.h"
#include "BooleanProposition.h"

#include <string>

namespace math
{
	class CompoundProposition;
	/**
	*	�ȼ�����
	*/
	class EquivalenceSample
	{
	public:
		EquivalenceSample();
		virtual ~EquivalenceSample();
	public:
		/**
		*	�Ƿ�����������
		*/
		bool isTautologyProposition(CompoundProposition* proposition);
		/**
		*	�Ƿ���ì������
		*/
		bool isContradictoryProposition(CompoundProposition* proposition);
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "";  }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&T = p;
	*/
	class EquivalenceSample0 : public EquivalenceSample
	{
	public:
		EquivalenceSample0();
		virtual ~EquivalenceSample0();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & T = p"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|F = p;
	*/
	class EquivalenceSample1 : public EquivalenceSample
	{
	public:
		EquivalenceSample1();
		virtual ~EquivalenceSample1();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | F = p"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|T = T;
	*/
	class EquivalenceSample2 : public EquivalenceSample
	{
	public:
		EquivalenceSample2();
		virtual ~EquivalenceSample2();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | T = T"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&F = F;
	*/
	class EquivalenceSample3 : public EquivalenceSample
	{
	public:
		EquivalenceSample3();
		virtual ~EquivalenceSample3();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & F = F"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|p = p;
	*/
	class EquivalenceSample4 : public EquivalenceSample
	{
	public:
		EquivalenceSample4();
		virtual ~EquivalenceSample4();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | p = p"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&p = p;
	*/
	class EquivalenceSample5 : public EquivalenceSample
	{
	public:
		EquivalenceSample5();
		virtual ~EquivalenceSample5();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & p = p"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	!!p = p;
	*/
	class EquivalenceSample6 : public EquivalenceSample
	{
	public:
		EquivalenceSample6();
		virtual ~EquivalenceSample6();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "!!p = p"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|q = q|p;
	*/
	class EquivalenceSample7 : public EquivalenceSample
	{
	public:
		EquivalenceSample7();
		virtual ~EquivalenceSample7();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | q = q | p"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&q = q&p;
	*/
	class EquivalenceSample8 : public EquivalenceSample
	{
	public:
		EquivalenceSample8();
		virtual ~EquivalenceSample8();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & q = q & p"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p|q)|r = p|(q|r);
	*/
	class EquivalenceSample9 : public EquivalenceSample
	{
	public:
		EquivalenceSample9();
		virtual ~EquivalenceSample9();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p | q) | r = p | (q | r)"; }
	};
	
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p&q)&r = p&(q&r);
	*/
	class EquivalenceSample10 : public EquivalenceSample
	{
	public:
		EquivalenceSample10();
		virtual ~EquivalenceSample10();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p & q) & r = p & (q & r)"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p | (q&r) = (p|q) & (p|r);
	*/
	class EquivalenceSample11 : public EquivalenceSample
	{
	public:
		EquivalenceSample11();
		virtual ~EquivalenceSample11();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | (q & r) = (p | q) & (p | r)"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p & (q|r) = (p&q) | (p&r);
	*/
	class EquivalenceSample12 : public EquivalenceSample
	{
	public:
		EquivalenceSample12();
		virtual ~EquivalenceSample12();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & (q | r) = (p & q) | (p & r)"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p&q) = (!p) | (!q);
	*/
	class EquivalenceSample13 : public EquivalenceSample
	{
	public:
		EquivalenceSample13();
		virtual ~EquivalenceSample13();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "!(p & q) = (!p) | (!q)"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p|q) = (!p) & (!q);
	*/
	class EquivalenceSample14 : public EquivalenceSample
	{
	public:
		EquivalenceSample14();
		virtual ~EquivalenceSample14();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "!(p | q) = (!p) & (!q)"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|(p&q) = q;
	*/
	class EquivalenceSample15 : public EquivalenceSample
	{
	public:
		EquivalenceSample15();
		virtual ~EquivalenceSample15();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | (p & q) = q"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&(p|q) = q;
	*/
	class EquivalenceSample16 : public EquivalenceSample
	{
	public:
		EquivalenceSample16();
		virtual ~EquivalenceSample16();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & (p | q) = q"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p&(!p) = F;
	*/
	class EquivalenceSample17 : public EquivalenceSample
	{
	public:
		EquivalenceSample17();
		virtual ~EquivalenceSample17();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & (!p) = F"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p|(!p) = T;
	*/
	class EquivalenceSample18 : public EquivalenceSample
	{
	public:
		EquivalenceSample18();
		virtual ~EquivalenceSample18();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | (!p) = T"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p->q = !p | q;
	*/
	class EquivalenceSample19 : public EquivalenceSample
	{
	public:
		EquivalenceSample19();
		virtual ~EquivalenceSample19();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p -> q = !p | q"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p->q = !q -> !p;
	*/
	class EquivalenceSample20 : public EquivalenceSample
	{
	public:
		EquivalenceSample20();
		virtual ~EquivalenceSample20();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p -> q = !q -> !p"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p | q = !p -> q;
	*/
	class EquivalenceSample21 : public EquivalenceSample
	{
	public:
		EquivalenceSample21();
		virtual ~EquivalenceSample21();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p | q = !p -> q"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p & q = !(p ->(!q));
	*/
	class EquivalenceSample22 : public EquivalenceSample
	{
	public:
		EquivalenceSample22();
		virtual ~EquivalenceSample22();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p & q = !(p -> (!q))"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p->q) = p & (!q);
	*/
	class EquivalenceSample23 : public EquivalenceSample
	{
	public:
		EquivalenceSample23();
		virtual ~EquivalenceSample23();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "!(p -> q) = p & (!q)"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->q) & (p->r) = p->(q&r)
	*/
	class EquivalenceSample24 : public EquivalenceSample
	{
	public:
		EquivalenceSample24();
		virtual ~EquivalenceSample24();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p -> q) & (p -> r) = p -> (q & r)"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->r) & (p->r) = (p|q)->r
	*/
	class EquivalenceSample25 : public EquivalenceSample
	{
	public:
		EquivalenceSample25();
		virtual ~EquivalenceSample25();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p -> r) & (p -> r) = (p | q) -> r"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->q) | (p->r) = p->(q|r)
	*/
	class EquivalenceSample26 : public EquivalenceSample
	{
	public:
		EquivalenceSample26();
		virtual ~EquivalenceSample26();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p -> q) | (p -> r) = p -> (q | r)"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p->r) | (p->r) = (p&q)->r
	*/
	class EquivalenceSample27 : public EquivalenceSample
	{
	public:
		EquivalenceSample27();
		virtual ~EquivalenceSample27();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p -> r) | (p -> r) = (p & q) -> r"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p<->q = (p->q) & (q->p)
	*/
	class EquivalenceSample28 : public EquivalenceSample
	{
	public:
		EquivalenceSample28();
		virtual ~EquivalenceSample28();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p <-> q = (p -> q) & (q -> p)"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p<->q = (!p)<->(!q)
	*/
	class EquivalenceSample29 : public EquivalenceSample
	{
	public:
		EquivalenceSample29();
		virtual ~EquivalenceSample29();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p <-> q = (!p) <-> (!q)"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	p<->q = (p&q) | ((!p) & (!q))
	*/
	class EquivalenceSample30 : public EquivalenceSample
	{
	public:
		EquivalenceSample30();
		virtual ~EquivalenceSample30();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p <-> q = (p & q) | ((!p) & (!q))"; }
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(p<->q) = p<->(!q)
	*/
	class EquivalenceSample31 : public EquivalenceSample
	{
	public:
		EquivalenceSample31();
		virtual ~EquivalenceSample31();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "!(p <-> q) = p <-> (!q)"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	p<->q = q<->p
	*/
	class EquivalenceSample32 : public EquivalenceSample
	{
	public:
		EquivalenceSample32();
		virtual ~EquivalenceSample32();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "p <-> q = q <-> p"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p|q)|r = q|(p|r);
	*/
	class EquivalenceSample33 : public EquivalenceSample
	{
	public:
		EquivalenceSample33();
		virtual ~EquivalenceSample33();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p | q) | r = q | (p | r)"; }
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	(p&q)&r = q&(p&r);
	*/
	class EquivalenceSample34 : public EquivalenceSample
	{
	public:
		EquivalenceSample34();
		virtual ~EquivalenceSample34();
	public:
		/**
		*	��ȡ�ȼ�ʽ
		*/
		virtual Proposition* getEquivalenceProposition(CompoundProposition* proposition);
		/**
		*	����
		*/
		virtual std::string toString() { return "(p & q) & r = q & (p & r)"; }
	};
}