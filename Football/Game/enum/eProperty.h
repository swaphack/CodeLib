#pragma once

namespace game
{

	/**
	*	属性
	*/
	enum AttributeType
	{
		/**
		*	名称
		*/
		EAT_Name,
		/**
		*	性别
		*/
		EAT_Gender,
		/**
		*	出生日期
		*/
		EAT_Birthday,
		/**
		*	国籍
		*/
		EAT_Country,
		/**
		*	城市
		*/
		EAT_City,
		/**
		*	所属俱乐部
		*/
		EAT_Club,
		/**
		*	所属队伍
		*/
		EAT_Team,
		/**
		*	最大值
		*/
		EAT_Max,
	};

	/**
	*	空间属性
	*/
	enum SpaceType
	{
		/**
		*	坐标x
		*/
		ESP_PositionX,
		/**
		*	坐标y
		*/
		ESP_PositionY,
		/**
		*	坐标z
		*/
		ESP_PositionZ,
		/**
		*	长度
		*/
		ESP_Length,
		/**
		*	宽度
		*/
		ESP_Width,
		/**
		*	高度
		*/
		ESP_Height,
		/**
		*	最大值
		*/
		ESP_Max,
	};
}