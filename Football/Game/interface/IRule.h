#pragma once

namespace game
{
	class IAction;
	class IScene;
	class IBall;
	class IPlayer;
	class IField;
	class ITeam;
	/**
	*	比赛规则
	*/
	class IRule
	{
	public:
		virtual ~IRule() {}
	public:
		/**
		*	动作是否犯规
		*	@param action 动作描述
		*	@param action 触犯条例
		*/
		virtual bool isBreakRule(const IScene* pScene, int& nBreakRule) const = 0;
		/**
		*	检查上阵人数是否足够
		*	@param ITeam 队伍
		*/
		virtual bool isEnoughLineUpPlayer(const ITeam* pTeam) const = 0;
		/**
		*	超出边线
		*	@param pBall 球
		*	@param pField 比赛场地
		*	@param pLastPlayer 最后接触球的球员
		*/
		virtual bool isOutByLine(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
		/**
		*	超出底线
		*	@param pBall 球
		*	@param pField 比赛场地
		*	@param pLastPlayer 最后接触球的球员
		*/
		virtual bool isOutEndLine(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
		/**
		*	越位
		*	@param pBall 球
		*	@param pField 比赛场地
		*	@param pLastPlayer 最后接触球的球员
		*/
		virtual bool isOffSide(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
		/**
		*	进球
		*	@param pBall 球
		*	@param pField 比赛场地
		*	@param pLastPlayer 最后接触球的球员
		*/
		virtual bool isGoal(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
	};
}