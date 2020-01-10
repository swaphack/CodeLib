#pragma once

#include "Number.h"

namespace math
{
	/**
	*	实数
	*/
	class Real : Number
	{
	public:
		/**
		*	零因子
		*/
		static int zero();
		/**
		*	单位元
		*/
		static int identity();
	protected:
	private:
	};
}