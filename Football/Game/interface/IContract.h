#pragma once

namespace game
{
	class IPropertySheet;

	/**
	*	合同
	*/
	class IContract
	{
	public:
		virtual ~IContract() {}
	public:
		/**
		*	俱乐部
		*/
		virtual int getClubID() = 0;
		/**
		*	员工
		*/
		virtual int getPersonID() = 0;
		/**
		*	协定条件
		*/
		virtual const IPropertySheet* getAgreement() = 0;
	};
}