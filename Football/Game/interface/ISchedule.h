#pragma once

#include "Identity.h"

#include <vector>

namespace game
{
	class IMatchDetailedList;

	/**
	*	比赛赛程
	*/
	class ISchedule : public Identity
	{
	public:
		virtual ~ISchedule() {}
	public:
		/**
		*	获取指定时间的比赛
		*/
		virtual bool getMatchList(int time, std::vector<IMatchDetailedList>& matchDetailedList);
	};
}