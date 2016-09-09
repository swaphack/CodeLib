#pragma once

#include <vector>

namespace game
{
	class IPerson;
	class IClub;
	class IContract;
	class IConditionSheet;

	/**
	*	转会市场
	*/
	class ITransferMarket
	{
	public:
		virtual ~ITransferMarket() {}
	public:
		/**
		*	挂牌到市场
		*	@param condition 挂牌条件
		*/
		virtual bool onSale(IPerson* pPerson, IConditionSheet* condition) const = 0;
		/**
		*	从市场上移除
		*/
		virtual bool offShelf(IPerson* pPerson) const = 0;
		/**
		*	查询
		*	@param condition 搜索条件
		*	@param targets 搜索结果
		*/
		virtual bool findPerson(const IConditionSheet* condition, std::vector<IPerson*>& targets) const = 0;
		/**
		*	达成协议
		*/
		virtual bool makeDeal(int nClubID, int nPersonID, IContract* pContract) = 0;
	};
}