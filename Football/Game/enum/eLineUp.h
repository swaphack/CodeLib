#pragma once

namespace game
{
	/**
	上阵情况
	*/
	enum eLineUp
	{
		/**
		*	等待上场
		*/
		ELU_WAIT = 0,
		/**
		*	上场
		*/
		ELU_PLAY = 1,
		/**
		*	替换下来
		*/
		ELU_REPLACE = 2,
		/**
		*	红牌驱逐下场
		*/
		ELU_EXPULSION = 4,
	};
}