#pragma once

#include "Identity.h"

#include <vector>

namespace game
{
	class IMatchDetailedList;

	/**
	*	��������
	*/
	class ISchedule : public Identity
	{
	public:
		virtual ~ISchedule() {}
	public:
		/**
		*	��ȡָ��ʱ��ı���
		*/
		virtual bool getMatchList(int time, std::vector<IMatchDetailedList>& matchDetailedList);
	};
}