#pragma once

namespace lottery
{
	// ��Ʒ
	struct ItemDetail
	{
		int ItemID;
		int ItemCount;
	};

	// ����
	class IJackpot
	{
	public:
		virtual ~IJackpot() {}
	public:
		// ��ȡ����
		virtual const ItemDetail* pick(int nIndex) = 0;
		/**
		*	�����Ʒ
		*	@param nIndex ����
		*	@param nItemID ��Ʒ���
		*	@param nItemCount ��Ʒ����
		*/
		virtual void addReward(int nIndex, int nItemID, int nItemCount) = 0;
		/**
		*	�Ƴ���Ʒ
		*	@param nIndex ����
		*/
		virtual void removeReward(int nIndex) = 0;
		/**
		*	�����Ʒ
		*/
		virtual void clear() = 0;
	};
}