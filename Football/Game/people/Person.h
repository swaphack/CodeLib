#pragma once

#include "../base/Component.h"
#include "../enum/eProperty.h"
#include "../enum/eGender.h"
#include <stdint.h>

namespace game
{
	/**
	*	��
	*/
	class Person : public Component
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
		CREATE_COMPONENT_PROPERTY(std::string, Name);
		/**
		*	�Ա�
		*/
		CREATE_COMPONENT_PROPERTY_ENUM(eGender, Gender);
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, BirthDay);
		/**
		*	����
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, Country);
		/**
		*	�������ֲ�
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, Club);
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, Team);
	};
}