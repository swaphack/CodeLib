#pragma once

namespace game
{
	class PropertySheet;
	class ComponentSheet;
	class IBody;
	class IAction;

	/**
	*	人
	*/
	class IPerson
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
		*	身体，用于动作表现
		*/
		virtual IBody* getBody() = 0;
		/**
		*	执行动作
		*/
		virtual bool runAction(IAction* pAction) = 0;
	};
}