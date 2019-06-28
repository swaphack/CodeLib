#pragma once

#include "../base/ConditionSheet.h"
#include "../base/PropertySheet.h"

#include <map>
#include <cstdint>

namespace game
{
	/**
	*	转会市场
	*/
	class TransferMarket
	{
	protected:
		typedef struct PersonSale
		{
			// 人员
			uint64_t PersonID;
			// 所属俱乐部
			uint64_t ClubID;
			// 挂牌条件
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
		*	挂牌到市场
		*	@param nPersonID 人员
		*	@param pCondition 挂牌条件
		*	@param nClubID 所属俱乐部
		*/
		bool onSale(uint64_t nPersonID, ConditionSheet* pCondition, uint64_t nClubID = -1);
		/**
		*	从市场上移除
		*	@param nPersonID 人员
		*/
		bool offShelf(uint64_t nPersonID);
		/**
		*	超找符合条件的人员
		*	@param pCondition 搜索条件
		*	@param targets 搜索结果
		*/
		bool findPerson(const PropertySheet* pCondition, std::vector<int>& targets) const;
		/**
		*	清空
		*/
		void clear();
	private:
		// 球员个人出售条件
		std::map<int, PersonSale*> m_mOnSalePerson;
	};
}