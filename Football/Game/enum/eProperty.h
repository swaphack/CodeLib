#pragma once

namespace game
{

	/**
	*	属性
	*/
	enum class AttributeType : int
	{
		/**
		*	名称
		*/
		Name,
		/**
		*	性别
		*/
		Gender,
		/**
		*	出生日期
		*/
		Birthday,
		/**
		*	国籍
		*/
		Country,
		/**
		*	城市
		*/
		City,
		/**
		*	所属俱乐部
		*/
		Club,
		/**
		*	所属队伍
		*/
		Team,
		/**
		*	最大值
		*/
		Max,
	};

	/**
	*	空间属性
	*/
	enum class SpaceType : int
	{
		/**
		*	坐标x
		*/
		PositionX,
		/**
		*	坐标y
		*/
		PositionY,
		/**
		*	坐标z
		*/
		PositionZ,
		/**
		*	长度
		*/
		Length,
		/**
		*	宽度
		*/
		Width,
		/**
		*	高度
		*/
		Height,
		/**
		*	最大值
		*/
		Max,
	};
}