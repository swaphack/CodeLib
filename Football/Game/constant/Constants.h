#pragma once

namespace game
{
	struct Interval;

	/**
	*	常量	
	*/
	class Constants
	{
	public:
		/**
		*	球场长度(m)
		*/
		static const Interval FILED_LENGTH/* = { 90, 120 }*/;
		/**
		*	球场宽度(m)
		*/
		static const Interval FILED_WIDTH/* = {45,90}*/;
		/**
		*	国际球场长度(m)
		*/
		static const Interval INTERNATIONAL_FILED_LENGTH/* = { 100, 110 }*/;
		/**
		*	国际球场宽度(m)
		*/
		static const Interval INTERNATIONAL_FILED_WIDTH/* = { 64, 75 }*/;
		/**
		*	世界杯球场长度
		*/
		static const float WORLDCUP_FILED_LENGTH/* = 105*/;
		/**
		*	世界杯球场宽度(m)
		*/
		static const float WORLDCUP_FILED_WIDTH/* = 68*/;
		/**
		*	画线宽度(cm)
		*/
		static const float LINE_WIDTH/* = 12*/;
		/**
		*	中场圆半径(m)
		*/
		static const float CENTER_CIRCLE_RADIUS/* = 9.15f*/;
		/**
		*	角球区半径(m)
		*/
		static const float CORNER_AREA_RADIUS/* = 1.0f*/;
		/**
		*	球门宽度(m)
		*/
		static const float GOAL_WIDTH/* = 7.32f*/;
		/**
		*	球门高度(m)
		*/
		static const float GOAL_HEIGHT/* = 2.44f*/;
		/**
		*	球门区长度(m)
		*/
		static const float GOAL_AREA_LENGTH/* = 5.5f * 2 + 7.32f*/;
		/**
		*	球门区宽度(m)
		*/
		static const float GOAL_AREA_WIDTH/* = 5.5f*/;
		/**
		*	禁区区长度(m)
		*/
		static const float PENALTY_AREA_LENGTH/* = 16.5f * 2 + 7.32f*/;
		/**
		*	禁区区宽度(m)
		*/
		static const float PENALTY_AREA_WIDTH/* = 16.5f*/;
		/**
		*	点球点位置(m)
		*/
		static const float PENALTY_MARK_WIDTH/* = 11f*/;
		/**
		*	点球点位置(m)
		*/
		static const float PENALTY_MARK_ARC_RADIUS/* = 9.15f*/;
		/**
		*	替补人数
		*/
		static const Interval SUBSTITUTE_COUNT/* = { 3, 7 }*/;
		/**
		*	可上阵替补人数
		*/
		static const int ENABLE_LINEUP_SUBSTITUTE_COUNT/* = 3*/;
		/**
		*	半场比赛时间（min）
		*/
		static const int HALF_MATCH_TIME/* = 45*/;
		/**
		*	中场时间（min）
		*/
		static const int INTERNAL_TIME/* = 15*/;
	};
}