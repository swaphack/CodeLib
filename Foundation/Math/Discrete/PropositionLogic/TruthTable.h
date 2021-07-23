#pragma once

#include <map>
#include <cstdint>

namespace math
{
	class CompoundProposition;

	/**
	*	��ֵ��
	*/
	class TruthTable
	{
	public:
		/**
		*	��һ�����ݲ��Խ��
		*/
		static bool testResult(CompoundProposition* proposition, const std::map<uint64_t, bool>& idValue);
		/**
		*	���������Ƿ�ȼ�
		*/
		static bool isTwoPropositionsEqual(CompoundProposition* a, CompoundProposition* b);
		/**
		*	����ʽ
		*/
		static bool isTautologyProposition(CompoundProposition* a);
		/**
		*	ì��ʽ
		*/
		static bool isContradictoryProposition(CompoundProposition* a);
	};
}