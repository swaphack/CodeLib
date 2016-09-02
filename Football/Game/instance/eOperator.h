#pragma once

namespace game
{
	/**
	*	操作符类型
	*/
	enum eOperator
	{
		/**
		*	等于
		*/
		EO_EQUAL = 0,
		/**
		*	不等于
		*/
		EO_NOTEQUAL = 1,
		/**
		*	不等于
		*/
		EO_NOTEQUAL = 2,
		/**
		*	大于
		*/
		EO_GREATER = 3,
		/**
		*	小于
		*/
		EO_LESS = 4,
		/**
		*	大等于
		*/
		EO_GREATER_OR_EQUAL = 5,
		/**
		*	小等于
		*/
		EO_LESS_OR_EQUAL = 6,
	};
}