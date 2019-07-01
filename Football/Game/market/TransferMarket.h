#pragma once

#include <map>
#include <cstdint>
#include <vector>

namespace game
{
	class DataTable;
	class ConditionSheet;

	/**
	*	ת���г�
	*/
	class TransferMarket
	{
	protected:
		/**
		*	������Ʒ
		*/
		typedef struct SaleItem
		{
			// ��Ա
			uint64_t PersonID = 0;
			// �������ֲ�
			uint64_t ClubID = 0;
			// ��������
			ConditionSheet* Condition = nullptr;

			SaleItem();
			virtual ~SaleItem();
		};
	public:
		TransferMarket();
		virtual ~TransferMarket();
	public:
		/**
		*	���Ƶ��г�
		*	@param nPersonID ��Ա
		*	@param pCondition ��������
		*	@param nClubID �������ֲ�
		*/
		bool onSale(uint64_t nPersonID, ConditionSheet* pCondition, uint64_t nClubID = 0);
		/**
		*	���г����Ƴ�
		*	@param nPersonID ��Ա
		*/
		bool offShelf(uint64_t nPersonID);
		/**
		*	���ҷ�����������Ա
		*	@param pCondition ��������
		*	@param targets �������
		*/
		bool findPerson(const DataTable* pCondition, std::vector<uint64_t>& targets) const;
		/**
		*	���
		*/
		void clear();
	private:
		// ��Ա���˳�������
		std::map<uint64_t, SaleItem*> m_mOnSalePerson;
	};
}