#pragma once

namespace game
{
	class PropertySheet;
	class ComponentSheet;
	class IBody;
	class IAction;

	/**
	*	��
	*/
	class IPerson
	{
	public:
		virtual ~IPerson() {}
	public:
		/**
		*	�Ա�
		*/
		virtual int getGender() const = 0;
		/**
		*	��������
		*/
		virtual int getBirthDay() const = 0;
		/**
		*	����
		*/
		virtual int getCountryID() const = 0;
		/**
		*	�������ֲ�
		*/
		virtual int getClubID() const = 0;
		/**
		*	��������
		*/
		virtual int getTeamID() const = 0;
		/**
		*	���壬���ڶ�������
		*/
		virtual IBody* getBody() = 0;
		/**
		*	ִ�ж���
		*/
		virtual bool runAction(IAction* pAction) = 0;
	};
}