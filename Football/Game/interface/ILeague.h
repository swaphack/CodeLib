#pragma once

namespace game
{
	class ITeam;
	class IRank;
	class ISchedule;

	/**
	*	联赛
	*/
	class ILeague
	{
	public:
		virtual ~ILeague() {}
	public:
		/**
		*	编号
		*/
		virtual int getID() const = 0;
		/**
		*	所在国家
		*/
		virtual int getCountryID() const = 0;
		/**
		*	联赛等级
		*/
		virtual int level() const = 0;
		/**
		*	参加队伍数
		*/
		virtual int count() const = 0;
		/**
		*	获取队伍
		*/
		virtual const ITeam* getTeam(int nID) const = 0;
		/**
		*	添加队伍
		*/
		virtual void addTeam(ITeam* pTeam) = 0;
		/**
		*	移除队伍
		*/
		virtual void removeTeam(int nID) = 0;
		/**
		*	获取排名
		*/
		virtual const IRank* getRank() const = 0;
		/**
		*	获取赛程
		*/
		virtual const ISchedule* getSchedule() const = 0;
	};
}