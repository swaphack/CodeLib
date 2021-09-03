#pragma once

namespace sys
{
	/**
	*	数值类型
	*/
	enum class NumberType
	{
		/**
		*	无关联
		*/
		None = -1,
		/**
		*	固定
		*/
		Fixed,
		/**
		*	百分比
		*/
		Percent,
	};
}