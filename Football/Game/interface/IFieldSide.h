#pragma once

namespace game
{
	struct Point;
	struct Line;
	struct Circle;
	struct Rectangle;

	class ITeam;

	/**
	*	比赛场面（左右之分）
	*/
	class IFieldSide
	{
	public:
		virtual ~IFieldSide() {}
	public:
		/**
		*	所属队伍
		*/
		virtual int getTeamID() const = 0;
		/**
		*	底线
		*/
		virtual const Line& getEndLine() const = 0;
		/**
		*	球门线
		*/
		virtual const Line& getGoalLine() const = 0;
		/**
		*	球门区
		*/
		virtual const Rectangle getGoalArea() const = 0;
		/**
		*	点球点
		*/
		virtual const Point& getPenaltyMark() const = 0;
		/**
		*	禁区
		*/
		virtual const Rectangle& getPenaltyArea() const = 0;
		/**
		*	左角球区
		*/
		virtual const Rectangle& getLeftCornerArea() const = 0;
		/**
		*	右角球区
		*/
		virtual const Rectangle& getRightCornerArea() const = 0;
		/**
		*	左边线
		*/
		virtual Line getLeftByLine() = 0;
		/**
		*	右边线
		*/
		virtual Line getRightByLine() = 0;
		/**
		*	中线
		*/
		virtual Line getHalfWayLine() = 0;
	};
}