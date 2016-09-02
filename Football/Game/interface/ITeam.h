#pragma once

#include "Identity.h"

namespace game
{
	class IPlayer;
	class ICoach;
	class IFormation;
	class ILineUp;

	/**
	*	比赛队伍
	*/
	class ITeam : public Identity
	{
	public:
		virtual ~ITeam() {}
	public:
		/**
		*	所属俱乐部
		*/
		virtual int getClubID() const = 0;
		/**
		*	所属联赛
		*/
		virtual int getLeagueID() const = 0;
		/**
		*	获取阵型
		*/
		virtual const IFormation* getFormation(int nID) const = 0;
		/**
		*	获取上阵信息
		*/
		virtual const ILineUp* getLineUp() const = 0;
		/**
		*	获取运动员
		*/
		virtual const IPlayer* getPlayer(int nID) const = 0;
		/**
		*	添加运动员
		*/
		virtual void addPlayer(IPlayer* pPlayer) = 0;
		/**
		*	移除运动员
		*/
		virtual void removePlayer(int nID) const = 0;
		/**
		*	获取教练
		*/
		virtual const ICoach* getCoach(int nID) const = 0;
		/**
		*	添加教练
		*/
		virtual void addCoach(ICoach* pCoach) = 0;
		/**
		*	移除教练
		*/
		virtual void removeCoach(int nID) const = 0;
	};
}