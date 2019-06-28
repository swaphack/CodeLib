#pragma once

#include "../base/Component.h"
#include "../enum/eProperty.h"
#include "../enum/eGender.h"
#include <stdint.h>

namespace game
{
	/**
	*	人
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
		*	名称
		*/
		CREATE_COMPONENT_PROPERTY(std::string, Name);
		/**
		*	性别
		*/
		CREATE_COMPONENT_PROPERTY_ENUM(eGender, Gender);
		/**
		*	出生日期
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, BirthDay);
		/**
		*	国籍
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, Country);
		/**
		*	所属俱乐部
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, Club);
		/**
		*	所属队伍
		*/
		CREATE_COMPONENT_PROPERTY(int64_t, Team);
	};
}