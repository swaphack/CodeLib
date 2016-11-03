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
	*	俱乐部
	*/
	class IClub
	{
	public:
		virtual ~IClub() {}
	public:
		/**
		*	所在国家
		*/
		virtual int getCountryID() const = 0;
		/**
		*	俱乐部财政
		*/
		virtual const IFinance* getFinance() const = 0;
		/**
		*	雇佣
		*	@param nPersonID 员工
		*	@param pContract 合同
		*/
		virtual bool hireEmployee(int nPersonID, IContract* pContract) const = 0;
		/**
		*	解雇
		*	@param nPersonID 员工
		*/
		virtual bool fireEmployee(int nPersonID) const = 0;
		/**
		*	根据员工编号，获取员工信息
		*	@param nEmployeeID 员工
		*/
		virtual const IPerson* getEmployee(int nEmployeeID) const = 0;
		/**
		*	添加一份协议
		*/
		virtual void addContract(IContract* pContract) = 0;
		/**
		*	移除一份协议
		*/
		virtual void removeContract(IContract* pContract) = 0;
		/**
		*	获取员工协议
		*	@param nEmployeeID 员工
		*/
		virtual const IContract* getContract(int nEmployeeID) const = 0;
		/**
		*	生成队伍
		*/
		virtual ITeam* generateTeam() const = 0;
		/**
		*	移除队伍
		*/
		virtual bool purgeTeam(ITeam* pTeam) const = 0;
		/**
		*	查找队伍
		*/
		virtual const ITeam* findTeam(int nTeamID) const = 0;
	};
}