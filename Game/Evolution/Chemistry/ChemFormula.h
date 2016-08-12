#pragma once

#include "ChemInput.h"
#include "ChemCondition.h"
#include "ChemOutput.h"
#include "ChemEffect.h"

namespace nature
{
	/** 
	*	化学公式
	*	电荷守恒：反应前后各离子电荷总数相等
	*	反应前 正电荷+负电荷=反应后 正电荷+负电荷
	*	物料守恒：在相同条件下,在可逆反应中,对于同一条件下的反应,只要加入的物质折算到反应物,各物质质量相同,则将会达到同一个平衡体系.
	*	质量(质子)守恒：反应前各物质总质量=反应后各物质总质量
	*	反应前各“原子”的种类和数目=反应后各“原子”的种类和数目
	*
	*	两个重要公式
	*	从有机到无机C6H12O6＋6O2(酶)＝6CO2＋6H2O
	*	从无机到有机CO2+H2O（ 光照、酶、 叶绿体）==(CH2O)+O2
	*/
	class ChemFormula
	{
	private:
		ChemFormula();
		virtual ~ChemFormula();
	public:
		static ChemFormula* getInstance();
		static void purgeInstance();
	public:
		/**
		*	反应
		*/
		bool reaction(const ChemInput&, const ChemCondition&, ChemOutput&, ChemEffect&);
		/**
		*	添加一个新的公式
		*	例如：2H2 + O2 = 2H2O;
		*/ 
		void addFormula(const char* formula);
	private:
		static ChemFormula* s_pChemFormula;
	};
}