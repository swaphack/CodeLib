#pragma once

namespace game
{
	/**
	*	区间类型
	*/
	enum eInterval
	{
		/**
		*	开区间
		*/
		EI_OPEN = 0,
		/**
		*	闭区间
		*/
		EI_CLOSE = 1,
		/**
		*	半开半闭区间
		*/
		EI_OPEN_CLOSE = 2,
		/**
		*	半闭半开区间
		*/
		EI_CLOSE_OPEN = 3,
	};
}