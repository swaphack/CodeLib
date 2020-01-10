#pragma once

namespace math 
{
	/**
	*	点与直线的位置关系
	*/
	enum class PointAndLinePositionType
	{
		NONE,
		// 包含
		INCLUDE,
		// 在左边
		EXLUDE_LEFT,
		// 在右边
		EXLUDE_RIGHT,
		
	};

	/**
	*	两直线的位置关系
	*/
	enum class TwoLinesPositionType
	{
		// 平行
		PARALLEL,
		// 相交
		INTERSECT,
	};
}