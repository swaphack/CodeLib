#pragma once

#include "Component.h"
#include "../interface/IClub.h"
#include "../enum/eProperty.h"

namespace game
{
	/**
	*	俱乐部
	*/
	class Club : public Component, public IClub
	{
	public:
		Club();
		virtual ~Club();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Club);
	public:
		/**
		*	名称
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Name, Name);
		/**
		*	所在国家
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Country, Country);
		/**
		*	俱乐部财政
		*/
		CREATE_COMPONENT_FUNCTION2(Finance, Finance);
		/**
		*	雇佣
		*	@param nPersonID 员工
		*	@param pContract 合同
		*/
		virtual bool hireEmployee(int nPersonID, IContract* pContract);
		/**
		*	解雇
		*	@param nPersonID 员工
		*/
		virtual bool fireEmployee(int nPersonID);
		/**
		*	根据员工编号，获取员工信息
		*	@param nEmployeeID 员工
		*/
		virtual IPerson* getEmployee(int nEmployeeID);
		/**
		*	添加一份协议
		*/
		virtual void addContract(IContract* pContract);
		/**
		*	移除一份协议
		*/
		virtual void removeContract(IContract* pContract);
		/**
		*	获取员工协议
		*	@param nEmployeeID 员工
		*/
		virtual IContract* getContract(int nEmployeeID);
		/**
		*	生成队伍
		*/
		virtual ITeam* generateTeam();
		/**
		*	移除队伍
		*/
		virtual bool purgeTeam(ITeam* pTeam);
		/**
		*	查找队伍
		*/
		virtual const ITeam* findTeam(int nTeamID);
	protected:
		 
	};
}