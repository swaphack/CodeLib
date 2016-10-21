#pragma once

#include "Item.h"
#include "IJackpot.h"
#include "IProbablity.h"
#include "IDraw.h"

#include <vector>
#include <map>

namespace lottery
{
	// 奖池，每抽中一次，只是标记一下奖励组，不移除
	class Jackpot : public IJackpot
	{
	public:
		Jackpot();
		virtual ~Jackpot();
	public:
		// 抽取奖励
		virtual const ItemDetail* pick(int nIndex);

		virtual void addReward(int nIndex, int nItemID, int nItemCount);

		virtual void removeReward(int nIndex);

		virtual void clear();
	private:
		// 奖励
		std::map<int, ItemDetail> m_dictReward;
	};

	//////////////////////////////////////////////////////////////////////////

	// 概率
	class Probablity : public IProbablity
	{
	public:
		Probablity();
		virtual ~Probablity();
	public:
		virtual int pick(float fProbablity);

		virtual void addIndex(int nIndex, float fProbablity);

		virtual void removeIndex(int nIndex);

		virtual void clear();
	private:
		// 原始数据
		std::map<int, float> m_mapSrcProbablity;
		// 采集数据
		std::vector<ProbablityDetail> m_vecDestProbablity;
		// 是否重新采集
		bool m_bDirty;
	};

	//////////////////////////////////////////////////////////////////////////

	// 抽奖
	class Draw : public IDraw
	{
	public:
		Draw();
		virtual ~Draw();
	public:
		virtual void setJackpot(IJackpot* pJackpot);

		virtual IJackpot* getJackpot();

		virtual void setProbablity(IProbablity* pPropbablity);

		virtual IProbablity* getProbablity();

		virtual const ItemDetail* pick(float fProbablity);

		void addReward(float fProbablity, int nItemID, int nItemCount);

		void clear();
	private:
		IJackpot* m_pJackpot;
		IProbablity* m_pProbablity;
		int m_nIndex;
	};
}