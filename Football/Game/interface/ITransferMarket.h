#pragma once

#include <vector>

namespace game
{
	class IPerson;
	class IClub;
	class IContract;
	class IConditionSheet;

	/**
	*	ת���г�
	*/
	class ITransferMarket
	{
	public:
		virtual ~ITransferMarket() {}
	public:
		/**
		*	���Ƶ��г�
		*	@param condition ��������
		*/
		virtual bool onSale(IPerson* pPerson, IConditionSheet* condition) const = 0;
		/**
		*	���г����Ƴ�
		*/
		virtual bool offShelf(IPerson* pPerson) const = 0;
		/**
		*	��ѯ
		*	@param condition ��������
		*	@param targets �������
		*/
		virtual bool findPerson(const IConditionSheet* condition, std::vector<IPerson*>& targets) const = 0;
		/**
		*	���Э��
		*/
		virtual bool makeDeal(int nClubID, int nPersonID, IContract* pContract) = 0;
	};
}