#pragma once

namespace game
{

	/**
	*	场上位置
	*/
	enum ePosition
	{
		EP_NONE,
		/**
		*	守门员
		*/
		EP_GOALKEEPER,
		/**
		*	左后卫
		*/
		EP_LEFT_BACK,
		/**
		*	右后卫
		*/
		EP_RIGHT_BACK,
		/**
		*	中卫
		*/
		EP_CENTER_BACK,
		/**
		*	左前卫
		*/
		EP_LEFT_MIDFIELDER,
		/**
		*	右前卫
		*/
		EP_RIGHT_MIDFIELDER,
		/**
		*	前卫
		*/
		EP_MIDFIELDER,
		/**
		*	前腰
		*/
		EP_ATTACKING_MIDFIELDER,
		/**
		*	后腰
		*/
		EP_DEFENDING_MIDFIELDER,
		/**
		*	左内锋
		*/
		EP_INSIDE_LEFT_FORWARD,
		/**
		*	右内锋
		*/
		EP_INSIDE_RIGHT_FORWARD,
		/**
		*	左边锋
		*/
		EP_OUTSIDE_LEFT_FORWARD,
		/**
		*	右边锋
		*/
		EP_OUTSIDE_RIGHT_FORWARD,
		/**
		*	影子前锋
		*/
		EP_SECOND_STRIKER,
		/**
		*	中锋
		*/
		EP_STRIKER,
	}
}