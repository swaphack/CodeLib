#pragma once

namespace game
{

	/**
	*	人物属性
	*/
	enum ePersonProperty
	{
		/**
		*	性别
		*/
		EPP_GENDER,
		/**
		*	出生日期
		*/
		EPP_BIRTHDAY,
		/**
		*	国籍
		*/
		EPP_COUNTRY,
		/**
		*	所属俱乐部
		*/
		EPP_CLUB,
		/**
		*	所属队伍
		*/
		EPP_TEAM,
		/**
		*	最大值
		*/
		EPP_MAX,
	};

	/**
	*	身躯属性
	*/
	enum eBodyProperty
	{
		/**
		*	坐标x
		*/
		EBP_POSITION_X = EPP_MAX,
		/**
		*	坐标y
		*/
		EBP_POSITION_Y,
		/**
		*	坐标z
		*/
		EBP_POSITION_Z,
		/**
		*	长度
		*/
		EBP_VOLUME_LENGTH,
		/**
		*	宽度
		*/
		EBP_VOLUME_WIDTH,
		/**
		*	高度
		*/
		EBP_VOLUME_HEIGHT,
		/**
		*	最大值
		*/
		EBP_MAX,
	};
}