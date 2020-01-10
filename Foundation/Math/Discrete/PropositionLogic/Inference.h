#pragma once

#include "Basic/Collection/NodeCache.h"

#include "Proposition.h"
#include "PrimaryProposition.h"
#include "CompoundProposition.h"
#include "BooleanProposition.h"

namespace math
{
	/**
	*	推理
	*/
	class Inference
	{
	public:
		Inference();
		~Inference();
	public:
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		T* createNode()
		{
			return _nodeCache.createNode<T>();
		}
	public:
		/**
		*	生成否定式
		*/
		CompoundProposition* createNegativeProposition(Proposition* a);
		/**
		*	生成析取式
		*/
		CompoundProposition* createDisjunctiveProposition(Proposition* a, Proposition* b);
		/**
		*	生成合取式
		*/
		CompoundProposition* createCombinedProposition(Proposition* a, Proposition* b);
	private:
		/**
		*	节点缓存池
		*/
		NodeCache _nodeCache;
	};
}