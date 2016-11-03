#pragma once

#include <vector>

namespace game
{
	class IMatchDetailedList;

	/**
	*	��������
	*/
	class ISchedule
	{
	public:
		virtual ~ISchedule() {}
	public:
		/**
		*	��ȡָ��ʱ��ı���
		*/
		virtual bool getMatchsByTime(int time, std::vector<IMatchDetailedList>& matchDetailedList);
		/**
		*	��ȡָ������ı�������
		*/
		virtual bool getMatchByTeam(int teamID, std::vector<IMatchDetailedList>& matchDetailedList);
	};
}