#pragma once

namespace game
{
	class PropertySheet;
	class ComponentSheet;
	class IBody;
	class IAction;
	class IMind;

	/**
	*	��
	*/
	class IPerson
	{
	public:
		virtual ~IPerson() {}
	public:
		/**
		*	�������
		*/
		virtual int getName() = 0;
		/**
		*	�Ա�
		*/
		virtual int getGender() = 0;
		/**
		*	��������
		*/
		virtual int getBirthDay() = 0;
		/**
		*	����
		*/
		virtual int getCountry() = 0;
		/**
		*	�������ֲ�
		*/
		virtual int getClub() = 0;
		/**
		*	��������
		*/
		virtual int getTeam() = 0;
		/**
		*	����
		*/
		virtual IBody* getBody() = 0;
		/**
		*	����
		*/
		virtual IMind* getMind() = 0;
	};
}