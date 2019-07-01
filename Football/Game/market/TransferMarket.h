#pragma once

#include <map>
#include <cstdint>
#include <vector>

namespace game
{
	class DataTable;
	class ConditionSheet;

	/**
	*	转会市场
	*/
	class TransferMarket
	{
	protected:
		/**
		*	出售物品
		*/
		typedef struct SaleItem
		{
			// 人员
			uint64_t PersonID = 0;
			// 所属俱乐部
			uint64_t ClubID = 0;
			// 挂牌条件
			ConditionSheet* Condition = nullptr;

			SaleItem();
			virtual ~SaleItem();
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
		bool onSale(uint64_t nPersonID, ConditionSheet* pCondition, uint64_t nClubID = 0);
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
		bool findPerson(const DataTable* pCondition, std::vector<uint64_t>& targets) const;
		/**
		*	清空
		*/
		void clear();
	private:
		// 球员个人出售条件
		std::map<uint64_t, SaleItem*> m_mOnSalePerson;
	};
}