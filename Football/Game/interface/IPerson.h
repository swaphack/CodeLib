#pragma once

#include "Identity.h"

namespace game
{
	class IPropertySheet;
	/**
	*	人
	*/
	class IPerson : public Identity
	{
	public:
		virtual ~IPerson() {}
	public:
		/**
		*	性别
		*/
		virtual int getGender() const = 0;
		/**
		*	出生日期
		*/
		virtual int getBirthDay() const = 0;
		/**
		*	国籍
		*/
		virtual int getCountryID() const = 0;
		/**
		*	所属俱乐部
		*/
		virtual int getClubID() const = 0;
		/**
		*	所属队伍
		*/
		virtual int getTeamID() const = 0;
		/**
		*	获取属性
		*/
		virtual const IPropertySheet* getProperty() const = 0;
	};
}