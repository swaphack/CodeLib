#pragma once

#include "Basic/Array.h"
#include "Number/Number.h"

#include <vector>

namespace math
{
	class Equation;
	/**
	*	方程组
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
		*	方程组的解
		*/
		std::vector<Number> getSolution();
	protected:
	private:
	};
}