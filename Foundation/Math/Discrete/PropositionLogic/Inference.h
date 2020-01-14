#pragma once

#include "Basic/Collection/NodeCache.h"

namespace math
{
	class Proposition;

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
		*	添加条件
		*/
		void addCondition(Proposition* condition);
		/**
		*	移除条件
		*/
		void removeCondtion(Proposition* condition);
		/**
		*	移除所有
		*/
		void removeAllCondtions();
	public:
		std::set<Proposition*> getResult();
	private:
		/**
		*	条件
		*/
		std::set<Proposition*> _condtions;
	};
}