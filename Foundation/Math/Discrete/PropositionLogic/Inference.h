#pragma once

#include "Basic/Collection/NodeCache.h"

namespace math
{
	class Proposition;

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
		*	�������
		*/
		void addCondition(Proposition* condition);
		/**
		*	�Ƴ�����
		*/
		void removeCondtion(Proposition* condition);
		/**
		*	�Ƴ�����
		*/
		void removeAllCondtions();
	public:
		std::set<Proposition*> getResult();
	private:
		/**
		*	����
		*/
		std::set<Proposition*> _condtions;
	};
}