#pragma once

#include "../interface/ITransferMarket.h"

#include "ConditionSheet.h"
#include "PropertySheet.h"

#include <map>

namespace game
{
	/**
	*	ת���г�
	*/
	class TransferMarket : public ITransferMarket
	{
	protected:
		typedef struct PersonSale
		{
			// ��Ա
			int PersonID;
			// ��������
			IConditionSheet* Condition;
			// �������ֲ�
			int ClubID;

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
		virtual bool onSale(int nPersonID, IConditionSheet* pCondition, int nClubID = -1);
		/**
		*	���г����Ƴ�
		*	@param nPersonID ��Ա
		*/
		virtual bool offShelf(int nPersonID);
		/**
		*	���ҷ�����������Ա
		*	@param pCondition ��������
		*	@param targets �������
		*/
		virtual bool findPerson(const PropertySheet* pCondition, std::vector<int>& targets) const;
		/**
		*	���
		*/
		virtual void clear();
	private:
		// ��Ա���˳�������
		std::map<int, PersonSale*> m_mOnSalePerson;
	};
}