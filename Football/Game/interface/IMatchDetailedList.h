#pragma once

namespace game
{
	/**
	*	比赛清单
	*/
	class IMatchDetailedList
	{
	public:
		virtual ~IMatchDetailedList() {}
	public:
		/**
		*	开赛时间
		*/
		virtual int getKickOffTime() const = 0;
		/**
		*	比赛场地
		*/
		virtual int getStadiumID() const = 0;
		/**
		*	主队
		*/
		virtual int getHostTeamID() const = 0;
		/**
		*	客队
		*/
		virtual int getVisiterTeamID() const = 0;
	};
}