#pragma once

#include "Basic/Collection/NodeCache.h"

#include "Proposition.h"
#include "PrimaryProposition.h"
#include "CompoundProposition.h"
#include "BooleanProposition.h"

namespace math
{
	/**
	*	����
	*/
	class Inference
	{
	public:
		Inference();
		~Inference();
	public:
		/**
		*	�����ڵ�
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		T* createNode()
		{
			return _nodeCache.createNode<T>();
		}
	public:
		/**
		*	���ɷ�ʽ
		*/
		CompoundProposition* createNegativeProposition(Proposition* a);
		/**
		*	������ȡʽ
		*/
		CompoundProposition* createDisjunctiveProposition(Proposition* a, Proposition* b);
		/**
		*	���ɺ�ȡʽ
		*/
		CompoundProposition* createCombinedProposition(Proposition* a, Proposition* b);
	private:
		/**
		*	�ڵ㻺���
		*/
		NodeCache _nodeCache;
	};
}