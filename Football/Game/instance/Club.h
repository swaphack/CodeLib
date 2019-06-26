#pragma once

#include "Component.h"
#include "../interface/IClub.h"
#include "../enum/eProperty.h"

namespace game
{
	/**
	*	���ֲ�
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
		*	����
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Name, Name);
		/**
		*	���ڹ���
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Country, Country);
		/**
		*	���ֲ�����
		*/
		CREATE_COMPONENT_FUNCTION2(Finance, Finance);
		/**
		*	��Ӷ
		*	@param nPersonID Ա��
		*	@param pContract ��ͬ
		*/
		virtual bool hireEmployee(int nPersonID, IContract* pContract);
		/**
		*	���
		*	@param nPersonID Ա��
		*/
		virtual bool fireEmployee(int nPersonID);
		/**
		*	����Ա����ţ���ȡԱ����Ϣ
		*	@param nEmployeeID Ա��
		*/
		virtual IPerson* getEmployee(int nEmployeeID);
		/**
		*	���һ��Э��
		*/
		virtual void addContract(IContract* pContract);
		/**
		*	�Ƴ�һ��Э��
		*/
		virtual void removeContract(IContract* pContract);
		/**
		*	��ȡԱ��Э��
		*	@param nEmployeeID Ա��
		*/
		virtual IContract* getContract(int nEmployeeID);
		/**
		*	���ɶ���
		*/
		virtual ITeam* generateTeam();
		/**
		*	�Ƴ�����
		*/
		virtual bool purgeTeam(ITeam* pTeam);
		/**
		*	���Ҷ���
		*/
		virtual const ITeam* findTeam(int nTeamID);
	protected:
		 
	};
}