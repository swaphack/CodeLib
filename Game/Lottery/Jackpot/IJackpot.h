#pragma once

namespace lottery
{
	// 物品
	struct ItemDetail
	{
		int ItemID;
		int ItemCount;
	};

	// 奖池
	class IJackpot
	{
	public:
		virtual ~IJackpot() {}
	public:
		// 抽取奖励
		virtual const ItemDetail* pick(int nIndex) = 0;
		/**
		*	添加物品
		*	@param nIndex 索引
		*	@param nItemID 物品编号
		*	@param nItemCount 物品数量
		*/
		virtual void addReward(int nIndex, int nItemID, int nItemCount) = 0;
		/**
		*	移除物品
		*	@param nIndex 索引
		*/
		virtual void removeReward(int nIndex) = 0;
		/**
		*	清空物品
		*/
		virtual void clear() = 0;
	};
}