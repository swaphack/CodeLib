#pragma once

#include "Identity.h"

namespace game
{
	class ITeam;
	class IRule;
	class IField;
	class IMatchPart;
	/**
	*	比赛
	*/
	class IMatch : public Identity
	{
	public:
		virtual ~IMatch() {}
	public:
		/**
		*	上半程
		*/
		virtual const IMatchPart* getFirstHalfMatch();
		/**
		*	下半程
		*/
		virtual const IMatchPart* getSecondHalfMatch();
		/**
		*	加时
		*/
		virtual const IMatchPart* getExtraTimeMatch();
		/**
		*	胜利队伍
		*/
		virtual int getWinTeamID() const = 0;
		/**
		*	失败队伍
		*/
		virtual int getLostTeamID() const = 0;
		/**
		*	比赛场地
		*/
		virtual const IField* getField() const = 0;
		/**
		*	主队
		*/
		virtual const ITeam* getHostTeam() const = 0;
		/**
		*	客队
		*/
		virtual const ITeam* getVisitersTeam() const = 0;
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
	};
}