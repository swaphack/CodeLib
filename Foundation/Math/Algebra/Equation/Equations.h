#pragma once

#include "Basic/Array.h"
#include "Number/Number.h"

#include <vector>

namespace math
{
	class Equation;
	/**
	*	������
	*/
	class Equations
	{
	public:
		Equations();
		virtual ~Equations();
	public:
		void addEquation(const Equation& equation);
		void removeEquation(const Equation& equation);

	public:
		/**
		*	������Ľ�
		*/
		std::vector<Number> getSolution();
	protected:
	private:
	};
}