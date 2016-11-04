#pragma once

#include "Component.h"

#include "../interface/IPerson.h"
#include "../enum/eProperty.h"

#include "Body.h"
#include "Mind.h"

namespace game
{
	/**
	*	��
	*/
	class Person : public Component, public IPerson
	{
	public:
		Person();
		virtual ~Person();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Person);
		/**
		*	�Ա�
		*/
		CREATE_COMPONENT_PROPERTY2(EPP_GENDER, Gender, int);
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY2(EPP_BIRTHDAY, BirthDay, int);
		/**
		*	����
		*/
		CREATE_COMPONENT_PROPERTY2(EPP_COUNTRY, Country, int);
		/**
		*	�������ֲ�
		*/
		CREATE_COMPONENT_PROPERTY2(EPP_CLUB, Club, int);
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY2(EPP_TEAM, Team, int);
		/**
		*	����
		*/
		CREATE_COMPONENT_FUNCTION2(Body, Body);
		/**
		*	����
		*/
		CREATE_COMPONENT_FUNCTION2(Mind, Mind);
	};
}