#pragma once

#include "Identity.h"

namespace game
{
	class IPropertySheet;

	/**
	*	��ͬ
	*/
	class IContract : public Identity
	{
	public:
		virtual ~IContract() {}
	public:
		/**
		*	���ֲ�
		*/
		virtual int getClubID() const = 0;
		/**
		*	Ա��
		*/
		virtual int getPersonID() const = 0;
		/**
		*	Э������
		*/
		virtual const IPropertySheet* getAgreement() const = 0;
	};
}