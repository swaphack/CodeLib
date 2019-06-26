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
		*	����
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Name, Name, int);
		/**
		*	�Ա�
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Gender, Gender, int);
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Birthday, BirthDay, int);
		/**
		*	����
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Country, Country, int);
		/**
		*	�������ֲ�
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Club, Club, int);
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY(AttributeType::Team, Team, int);
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