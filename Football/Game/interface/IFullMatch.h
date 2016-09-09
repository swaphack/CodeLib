#pragma once

#include "Identity.h"

namespace game
{
	class ITeam;
	class IRule;
	class IField;
	class IPartMatch;
	/**
	*	全场比赛
	*/
	class IFullMatch : public Identity
	{
	public:
		virtual ~IFullMatch() {}
	public:
		/**
		*	上半程
		*/
		virtual const IPartMatch* getFirstHalfMatch();
		/**
		*	下半程
		*/
		virtual const IPartMatch* getSecondHalfMatch();
		/**
		*	加时
		*/
		virtual const IPartMatch* getExtraMatch();
		/**
		*	主队
		*/
		virtual const ITeam* getHostTeam() const = 0;
		/**
		*	客队
		*/
		virtual const ITeam* getVisiterTeam() const = 0;
		/**
		*	比赛场地
		*/
		virtual const IField* getField() const = 0;
		/**
		*	获取队伍
		*/
		virtual const ITeam* getTeamByID(int nTeamID) const = 0;
		/**
		*	比赛总时间
		*/
		virtual float getFullTime() const = 0;
		/**
		*	比赛是否结束
		*/
		virtual bool isMatchOver() const = 0;
		/**
		*	胜利队伍
		*/
		virtual int getWinTeamID() const = 0;
		/**
		*	失败队伍
		*/
		virtual int getLostTeamID() const = 0;
		/**
		*	主队分数
		*/
		virtual int getHostScore() const = 0;
		/**
		*	客队分数
		*/
		virtual int getVisiterScore() const = 0;
		/**
		*	主队点球分数
		*/
		virtual int getHostPenaltyScore() const = 0;
		/**
		*	客队点球分数
		*/
		virtual int getVisiterPenaltyScore() const = 0;
	};
}