#pragma once

#include "Identity.h"

namespace game
{
	class IPropertySheet;

	/**
	*	合同
	*/
	class IContract : public Identity
	{
	public:
		virtual ~IContract() {}
	public:
		/**
		*	俱乐部
		*/
		virtual int getClubID() const = 0;
		/**
		*	员工
		*/
		virtual int getPersonID() const = 0;
		/**
		*	协定条件
		*/
		virtual const IPropertySheet* getAgreement() const = 0;
	};
}