#pragma once

namespace game
{

	/**
	*	属性
	*/
	enum eNoramlProperty
	{
		/**
		*	名称
		*/
		eNoramlProperty_Name,
		/**
		*	性别
		*/
		eNoramlProperty_Gender,
		/**
		*	出生日期
		*/
		eNoramlProperty_Birthday,
		/**
		*	国籍
		*/
		eNoramlProperty_Country,
		/**
		*	城市
		*/
		eNoramlProperty_City,
		/**
		*	所属俱乐部
		*/
		eNoramlProperty_Club,
		/**
		*	所属队伍
		*/
		eNoramlProperty_Team,
		/**
		*	最大值
		*/
		eNoramlProperty_Max,
	};

	/**
	*	空间属性
	*/
	enum eSpaceProperty
	{
		/**
		*	坐标x
		*/
		eSpaceProperty_Position_X,
		/**
		*	坐标y
		*/
		eSpaceProperty_Position_Y,
		/**
		*	坐标z
		*/
		eSpaceProperty_Position_Z,
		/**
		*	长度
		*/
		eSpaceProperty_Volume_Length,
		/**
		*	宽度
		*/
		eSpaceProperty_Volume_Width,
		/**
		*	高度
		*/
		eSpaceProperty_Volume_Height,
		/**
		*	最大值
		*/
		eSpaceProperty_Max,
	};
}