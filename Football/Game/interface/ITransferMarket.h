#pragma once

#include <vector>

namespace game
{
	class IPerson;
	class IClub;
	class IContract;
	class ConditionSheet;
	class PropertySheet;

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
		*	@param nPersonID ��Ա
		*	@param pCondition ��������
		*	@param nClubID �������ֲ�
		*/
		virtual bool onSale(int nPersonID, ConditionSheet* pCondition, int nClubID = -1) = 0;
		/**
		*	���г����Ƴ�
		*	@param nPersonID ��Ա
		*/
		virtual bool offShelf(int nPersonID) = 0;
		/**
		*	��ѯ
		*	@param pCondition ��������
		*	@param targets �������
		*/
		virtual bool findPerson(const PropertySheet* pCondition, std::vector<int>& targets) const = 0;
		/**
		*	���
		*/
		virtual void clear() = 0;
	};
}