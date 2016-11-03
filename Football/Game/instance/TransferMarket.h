#pragma once

#include "../interface/ITransferMarket.h"

#include "ConditionSheet.h"
#include "PropertySheet.h"

#include <map>

namespace game
{
	/**
	*	转会市场
	*/
	class TransferMarket : public ITransferMarket
	{
	protected:
		typedef struct PersonSale
		{
			// 人员
			int PersonID;
			// 挂牌条件
			IConditionSheet* Condition;
			// 所属俱乐部
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
		*	挂牌到市场
		*	@param nPersonID 人员
		*	@param pCondition 挂牌条件
		*	@param nClubID 所属俱乐部
		*/
		virtual bool onSale(int nPersonID, IConditionSheet* pCondition, int nClubID = -1);
		/**
		*	从市场上移除
		*	@param nPersonID 人员
		*/
		virtual bool offShelf(int nPersonID);
		/**
		*	超找符合条件的人员
		*	@param pCondition 搜索条件
		*	@param targets 搜索结果
		*/
		virtual bool findPerson(const PropertySheet* pCondition, std::vector<int>& targets) const;
		/**
		*	清空
		*/
		virtual void clear();
	private:
		// 球员个人出售条件
		std::map<int, PersonSale*> m_mOnSalePerson;
	};
}