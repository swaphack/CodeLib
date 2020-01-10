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
		*	��һ�����ݲ��Խ��
		*/
		static bool getResult(CompoundProposition* proposition, const std::map<uint64_t, bool>& idValue);
		/**
		*	���������Ƿ�ȼ�
		*/
		static bool isTowPropositionEqual(CompoundProposition* a, CompoundProposition* b);
	protected:
	private:
	};
}