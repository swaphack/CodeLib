#pragma once

namespace game
{
	class PropertySheet;
	class ComponentSheet;
	class IBody;
	class IAction;
	class IMind;

	/**
	*	人
	*/
	class IPerson
	{
	public:
		virtual ~IPerson() {}
	public:
		/**
		*	姓名编号
		*/
		virtual int getName() = 0;
		/**
		*	性别
		*/
		virtual int getGender() = 0;
		/**
		*	出生日期
		*/
		virtual int getBirthDay() = 0;
		/**
		*	国籍
		*/
		virtual int getCountry() = 0;
		/**
		*	所属俱乐部
		*/
		virtual int getClub() = 0;
		/**
		*	所属队伍
		*/
		virtual int getTeam() = 0;
		/**
		*	身躯
		*/
		virtual IBody* getBody() = 0;
		/**
		*	大脑
		*/
		virtual IMind* getMind() = 0;
	};
}