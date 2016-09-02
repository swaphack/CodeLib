#pragma once

#include "Identity.h"

namespace game
{
	class IPlayer;
	class ICoach;
	class IPerson;
	class ITeam;
	class IFinance;

	/**
	*	���ֲ�
	*/
	class IClub : public Identity
	{
	public:
		virtual ~IClub() {}
	public:
		/**
		*	���ڹ���
		*/
		virtual int getCountryID() const = 0;
		/**
		*	���ֲ�����
		*/
		virtual const IFinance* getFinance() const = 0;
		/**
		*	��Ӷ
		*/
		virtual bool hireEmployee(IPerson* pPerson) const = 0;
		/**
		*	���
		*/
		virtual bool fireEmployee(IPerson* pPerson) const = 0;
		/**
		*	��ȡԱ�������ݱ��
		*/
		virtual const IPerson* getEmployee(int nPersonID) const = 0;
		/**
		*	���ɶ���
		*/
		virtual ITeam* generateTeam() const = 0;
		/**
		*	�Ƴ�����
		*/
		virtual bool purgeTeam(ITeam* pTeam) const = 0;
		/**
		*	���Ҷ���
		*/
		virtual const ITeam* findTeam(int nTeamID) const = 0;
	};
}