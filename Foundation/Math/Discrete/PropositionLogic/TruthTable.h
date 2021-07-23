#pragma once

#include <map>
#include <cstdint>

namespace math
{
	class CompoundProposition;

	/**
	*	真值表
	*/
	class TruthTable
	{
	public:
		/**
		*	用一组数据测试结果
		*/
		static bool testResult(CompoundProposition* proposition, const std::map<uint64_t, bool>& idValue);
		/**
		*	两个命题是否等价
		*/
		static bool isTwoPropositionsEqual(CompoundProposition* a, CompoundProposition* b);
		/**
		*	永真式
		*/
		static bool isTautologyProposition(CompoundProposition* a);
		/**
		*	矛盾式
		*/
		static bool isContradictoryProposition(CompoundProposition* a);
	};
}