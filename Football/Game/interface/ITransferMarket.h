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
	*	转会市场
	*/
	class ITransferMarket
	{
	public:
		virtual ~ITransferMarket() {}
	public:
		/**
		*	挂牌到市场
		*	@param nPersonID 人员
		*	@param pCondition 挂牌条件
		*	@param nClubID 所属俱乐部
		*/
		virtual bool onSale(int nPersonID, ConditionSheet* pCondition, int nClubID = -1) = 0;
		/**
		*	从市场上移除
		*	@param nPersonID 人员
		*/
		virtual bool offShelf(int nPersonID) = 0;
		/**
		*	查询
		*	@param pCondition 搜索条件
		*	@param targets 搜索结果
		*/
		virtual bool findPerson(const PropertySheet* pCondition, std::vector<int>& targets) const = 0;
		/**
		*	清空
		*/
		virtual void clear() = 0;
	};
}