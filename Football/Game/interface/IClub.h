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
	class IClub
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
		*	@param nPersonID Ա��
		*	@param pContract ��ͬ
		*/
		virtual bool hireEmployee(int nPersonID, IContract* pContract) const = 0;
		/**
		*	���
		*	@param nPersonID Ա��
		*/
		virtual bool fireEmployee(int nPersonID) const = 0;
		/**
		*	����Ա����ţ���ȡԱ����Ϣ
		*	@param nEmployeeID Ա��
		*/
		virtual const IPerson* getEmployee(int nEmployeeID) const = 0;
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
		*	@param nEmployeeID Ա��
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