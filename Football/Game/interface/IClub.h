#pragma once

namespace game
{
	class IPlayer;
	class ICoach;
	class IPerson;
	class ITeam;
	class Finance;
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
		*	����
		*/
		virtual int getName() = 0;
		/**
		*	���ڹ���
		*/
		virtual int getCountry() = 0;
		/**
		*	���ֲ�����
		*/
		virtual Finance* getFinance() = 0;
		/**
		*	��Ӷ
		*	@param nPersonID Ա��
		*	@param pContract ��ͬ
		*/
		virtual bool hireEmployee(int nPersonID, IContract* pContract) = 0;
		/**
		*	���
		*	@param nPersonID Ա��
		*/
		virtual bool fireEmployee(int nPersonID) = 0;
		/**
		*	����Ա����ţ���ȡԱ����Ϣ
		*	@param nEmployeeID Ա��
		*/
		virtual IPerson* getEmployee(int nEmployeeID) = 0;
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
		virtual IContract* getContract(int nEmployeeID) = 0;
		/**
		*	���ɶ���
		*/
		virtual ITeam* generateTeam() = 0;
		/**
		*	�Ƴ�����
		*/
		virtual bool purgeTeam(ITeam* pTeam) = 0;
		/**
		*	���Ҷ���
		*/
		virtual const ITeam* findTeam(int nTeamID) = 0;
	};
}