#pragma once

#include <map>
#include <cstdint>

namespace math
{
	class CompoundProposition;

	class TruthTable
	{
	public:
		TruthTable();
		~TruthTable();
	public:
		/**
		*	用一组数据测试结果
		*/
		static bool getResult(CompoundProposition* proposition, const std::map<uint64_t, bool>& idValue);
		/**
		*	两个命题是否等价
		*/
		static bool isTowPropositionEqual(CompoundProposition* a, CompoundProposition* b);
	protected:
	private:
	};
}