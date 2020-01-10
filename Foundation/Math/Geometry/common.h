#pragma once

namespace math
{
	/**
	*	实心平面位置关系
	*/
	enum class SolidPositionType
	{
		/**
		*	包含
		*/
		INCLUDE,
		/**
		*	不包含
		*/
		EXCLUDE,
	};

	/**
	*	空心平面位置关系
	*/
	enum class HollowPosiitionType
	{
		/**
		*	包含
		*/
		INCLUDE,
		/**
		*	不包含
		*/
		EXCLUDE,
	};
}