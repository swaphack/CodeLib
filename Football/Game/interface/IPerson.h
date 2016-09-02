#pragma once

#include "Identity.h"

namespace game
{
	class IPropertySheet;
	/**
	*	��
	*/
	class IPerson : public Identity
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
		*	��ȡ����
		*/
		virtual const IPropertySheet* getProperty() const = 0;
	};
}