#pragma once

namespace game
{
	struct Point;
	struct Line;
	struct Circle;
	struct Rectangle;

	class IFieldSide;

	/**
	*	比赛场地
	*		 left			right
	*	 -- -- -- -- -- -- -- -- -- --
	*   |			   |			  |
	*   |			   |			  |
	*   |			   |			  |
	*   |			   |			  |
	*   |			   |			  |
	*	 -- -- -- -- -- -- -- -- -- --
	*
	*/
	class IField
	{
	public:
		virtual ~IField() {}
	public:
		/**
		*	获取宽度
		*/
		virtual float getWidth() const = 0;
		/**
		*	获取高度
		*/
		virtual float getHeight() const = 0;
		/**
		*	中线
		*/
		virtual Line getHalfWayLine() = 0;
		/**
		*	开球区
		*/
		virtual Circle getKickOffCircle() = 0;
		/**
		*	上边线
		*/
		virtual Line getUpByLine() = 0;
		/**
		*	下边线
		*/
		virtual Line getDownByLine() = 0;

		/**
		*	左底线
		*/
		virtual Line getLeftEndLine() = 0;
		/**
		*	左禁区
		*/
		virtual Rectangle getLeftPenaltyArea() = 0;
		/**
		*	左球门区
		*/
		virtual Rectangle getLeftGoalArea() = 0;
		/**
		*	左球门线
		*/
		virtual Line getLeftGoalLine() = 0;
		/**
		*	左点球点
		*/
		virtual Point getLeftPenaltyMark() = 0;
		/**
		*	左上角角球区
		*/
		virtual Rectangle getLeftUpCornerArea() = 0;
		/**
		*	左下角角球区
		*/
		virtual Rectangle getLeftDownCornerArea() = 0;


		/**
		*	右底线
		*/
		virtual Line getRightEndLine() = 0;
		/**
		*	右禁区
		*/
		virtual Rectangle getRightPenaltyArea() = 0;
		/**
		*	右点球点
		*/
		virtual Point getRightPenaltyMark() = 0;
		/**
		*	右上角角球区
		*/
		virtual Rectangle getRightUpCornerArea() = 0;
		/**
		*	右下角角球区
		*/
		virtual Rectangle getRightDownCornerArea() = 0;
		/**
		*	右球门区
		*/
		virtual Rectangle getRightGoalArea() = 0;
		/**
		*	右球门线
		*/
		virtual Line getRightGoalLine() = 0;
	};
}