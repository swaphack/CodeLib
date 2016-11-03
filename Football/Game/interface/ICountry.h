#pragma once

#include "Identity.h"

namespace game
{
	class ILeague;
	class IClub;
	/**
	*	����
	*/
	class ICountry
	{
	public:
		virtual ~ICountry() {}
	public:
		/**
		*	��������
		*/
		virtual ILeague* generateLeague() const = 0;
		/**
		*	�Ƴ�����
		*/
		virtual bool purgeLeague(ILeague* pLeague) const = 0;
		/**
		*	��������
		*/
		virtual ILeague* findLeague(int nLeagueID) const = 0;
		/**
		*	���ɾ��ֲ�
		*/
		virtual IClub* generateClub() const = 0;
		/**
		*	�Ƴ����ֲ�
		*/
		virtual bool purgeClub(IClub* pClub) const = 0;
		/**
		*	���Ҿ��ֲ�
		*/
		virtual IClub* findClub(int nClubID) const = 0;
	};
}