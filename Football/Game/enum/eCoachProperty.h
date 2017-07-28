#pragma once

namespace game
{
	/**
	*	教练属性
	*/
	enum eCoachProperty
	{
		/**
		*	进攻训练
		*/
		ECP_ATTACKING,
		/**
		*	防守训练
		*/
		ECP_DEFENDING,
		/**
		*	体能训练
		*/
		ECP_FITNESS,
		/**
		*	守门训练
		*/
		ECP_GOALKEEPERS,
		/**
		*	人员管理
		*/
		ECP_MAN_MANAGEMENT,
		/**
		*	心理训练
		*/
		ECP_MENTAL,
		/**
		*	战术训练
		*/
		ECP_TACTICAL,
		/**
		*	技术训练
		*/
		ECP_TECHNICAL,
		/**
		*	青年训练
		*/
		ECP_WORKING_WITH_YOUNGSTERS,
		/**
		*	适应性
		*/
		ECP_ADAPTABILITY,
		/**
		*	决心
		*/
		ECP_DETERMINATION,
		/**
		*	判断球员能力
		*/
		ECP_JUDGING_PLAYER_ABILITY,
		/**
		*	判断球员潜力
		*/
		ECP_JUDGING_PLAYER_POTENTIAL,
		/**
		*	纪律性
		*/
		ECP_LEVEL_OF_DISCIPLINE,
		/**
		*	激励
		*/
		ECP_MOTIVATING,
		/**
		*	医疗知识
		*/
		ECP_PHYSIOTHERAPY,
		/**
		*	战术知识
		*/
		ECP_TACTICALKNOWLEDGE,

		ECP_MAX,
	};
}