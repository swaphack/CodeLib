#pragma once

namespace game
{
	struct Interval;

	/**
	*	����	
	*/
	class Constants
	{
	public:
		/**
		*	�򳡳���(m)
		*/
		static const Interval FILED_LENGTH/* = { 90, 120 }*/;
		/**
		*	�򳡿��(m)
		*/
		static const Interval FILED_WIDTH/* = {45,90}*/;
		/**
		*	�����򳡳���(m)
		*/
		static const Interval INTERNATIONAL_FILED_LENGTH/* = { 100, 110 }*/;
		/**
		*	�����򳡿��(m)
		*/
		static const Interval INTERNATIONAL_FILED_WIDTH/* = { 64, 75 }*/;
		/**
		*	���籭�򳡳���
		*/
		static const float WORLDCUP_FILED_LENGTH/* = 105*/;
		/**
		*	���籭�򳡿��(m)
		*/
		static const float WORLDCUP_FILED_WIDTH/* = 68*/;
		/**
		*	���߿��(cm)
		*/
		static const float LINE_WIDTH/* = 12*/;
		/**
		*	�г�Բ�뾶(m)
		*/
		static const float CENTER_CIRCLE_RADIUS/* = 9.15f*/;
		/**
		*	�������뾶(m)
		*/
		static const float CORNER_AREA_RADIUS/* = 1.0f*/;
		/**
		*	���ſ��(m)
		*/
		static const float GOAL_WIDTH/* = 7.32f*/;
		/**
		*	���Ÿ߶�(m)
		*/
		static const float GOAL_HEIGHT/* = 2.44f*/;
		/**
		*	����������(m)
		*/
		static const float GOAL_AREA_LENGTH/* = 5.5f * 2 + 7.32f*/;
		/**
		*	���������(m)
		*/
		static const float GOAL_AREA_WIDTH/* = 5.5f*/;
		/**
		*	����������(m)
		*/
		static const float PENALTY_AREA_LENGTH/* = 16.5f * 2 + 7.32f*/;
		/**
		*	���������(m)
		*/
		static const float PENALTY_AREA_WIDTH/* = 16.5f*/;
		/**
		*	�����λ��(m)
		*/
		static const float PENALTY_MARK_WIDTH/* = 11f*/;
		/**
		*	�����λ��(m)
		*/
		static const float PENALTY_MARK_ARC_RADIUS/* = 9.15f*/;
		/**
		*	�油����
		*/
		static const Interval SUBSTITUTE_COUNT/* = { 3, 7 }*/;
		/**
		*	�������油����
		*/
		static const int ENABLE_LINEUP_SUBSTITUTE_COUNT/* = 3*/;
		/**
		*	�볡����ʱ�䣨min��
		*/
		static const int HALF_MATCH_TIME/* = 45*/;
		/**
		*	�г�ʱ�䣨min��
		*/
		static const int INTERNAL_TIME/* = 15*/;
	};
}