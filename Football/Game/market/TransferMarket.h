#pragma once

#include "../base/ConditionSheet.h"
#include "../base/PropertySheet.h"

#include <map>
#include <cstdint>

namespace game
{
	/**
	*	ת���г�
	*/
	class TransferMarket
	{
	protected:
		typedef struct PersonSale
		{
			// ��Ա
			uint64_t PersonID;
			// �������ֲ�
			uint64_t ClubID;
			// ��������
			ConditionSheet* Condition;

			~PersonSale()
			{
				if (Condition)
				{
					delete Condition;
				}
			}
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
		bool onSale(uint64_t nPersonID, ConditionSheet* pCondition, uint64_t nClubID = -1);
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
		bool findPerson(const PropertySheet* pCondition, std::vector<int>& targets) const;
		/**
		*	���
		*/
		void clear();
	private:
		// ��Ա���˳�������
		std::map<int, PersonSale*> m_mOnSalePerson;
	};
}