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
		*	大于
		*/
		EO_GREATER = 2,
		/**
		*	小于
		*/
		EO_LESS = 3,
		/**
		*	大等于
		*/
		EO_GREATER_OR_EQUAL = 4,
		/**
		*	小等于
		*/
		EO_LESS_OR_EQUAL = 5,
	};
}