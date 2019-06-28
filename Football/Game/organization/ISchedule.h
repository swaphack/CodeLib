#pragma once

#include <vector>

namespace game
{
	class IMatchDetailedList;

	/**
	*	比赛赛程
	*/
	class ISchedule
	{
	public:
		virtual ~ISchedule() {}
	public:
		/**
		*	获取指定时间的比赛
		*/
		virtual bool getMatchsByTime(int time, std::vector<IMatchDetailedList>& matchDetailedList);
		/**
		*	获取指定队伍的比赛赛程
		*/
		virtual bool getMatchByTeam(int teamID, std::vector<IMatchDetailedList>& matchDetailedList);
	};
}