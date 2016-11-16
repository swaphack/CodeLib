#pragma once

#include "Component.h"

#include "../interface/IPerson.h"
#include "../enum/eProperty.h"

#include "Body.h"
#include "Mind.h"

namespace game
{
	/**
	*	人
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
		*	名称
		*/
		CREATE_COMPONENT_PROPERTY2(eNoramlProperty_Name, Name, int);
		/**
		*	性别
		*/
		CREATE_COMPONENT_PROPERTY2(eNoramlProperty_Gender, Gender, int);
		/**
		*	出生日期
		*/
		CREATE_COMPONENT_PROPERTY2(eNoramlProperty_Birthday, BirthDay, int);
		/**
		*	国籍
		*/
		CREATE_COMPONENT_PROPERTY2(eNoramlProperty_Country, Country, int);
		/**
		*	所属俱乐部
		*/
		CREATE_COMPONENT_PROPERTY2(eNoramlProperty_Club, Club, int);
		/**
		*	所属队伍
		*/
		CREATE_COMPONENT_PROPERTY2(eNoramlProperty_Team, Team, int);
		/**
		*	身躯
		*/
		CREATE_COMPONENT_FUNCTION2(Body, Body);
		/**
		*	大脑
		*/
		CREATE_COMPONENT_FUNCTION2(Mind, Mind);
	};
}