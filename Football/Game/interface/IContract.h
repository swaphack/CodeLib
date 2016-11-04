#pragma once

namespace game
{
	class IPropertySheet;

	/**
	*	��ͬ
	*/
	class IContract
	{
	public:
		virtual ~IContract() {}
	public:
		/**
		*	���ֲ�
		*/
		virtual int getClubID() = 0;
		/**
		*	Ա��
		*/
		virtual int getPersonID() = 0;
		/**
		*	Э������
		*/
		virtual const IPropertySheet* getAgreement() = 0;
	};
}