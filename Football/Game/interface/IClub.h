#pragma once

#include "Identity.h"

namespace game
{
	class IPlayer;
	class ICoach;
	class IPerson;
	class ITeam;
	class IFinance;
	class IContract;

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
		*	@param pPerson Ա��
		*	@param pContract Э��
		*/
		virtual bool hireEmployee(IPerson* pPerson, IContract* pContract) const = 0;
		/**
		*	���
		*/
		virtual bool fireEmployee(IPerson* pPerson) const = 0;
		/**
		*	����Ա����ţ���ȡԱ����Ϣ
		*/
		virtual const IPerson* getEmployee(int nPersonID) const = 0;
		/**
		*	���һ��Э��
		*/
		virtual void addContract(IContract* pContract) = 0;
		/**
		*	�Ƴ�һ��Э��
		*/
		virtual void removeContract(IContract* pContract) = 0;
		/**
		*	��ȡԱ��Э��
		*/
		virtual const IContract* getContract(int nEmployeeID) const = 0;
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