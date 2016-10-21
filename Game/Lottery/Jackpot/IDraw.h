#pragma once

namespace lottery
{
	class IJackpot;
	class IProbablity;
	struct Item;

	// 抽奖
	class IDraw
	{
	public:
		virtual ~IDraw() {}
	public:
		// 设置奖池
		virtual void setJackpot(IJackpot* pJackpot) = 0;
		// 获取奖池
		virtual IJackpot* getJackpot() = 0;
		// 设置概率
		virtual void setProbablity(IProbablity* pPropbablity) = 0;
		// 设置概率
		virtual IProbablity* getProbablity() = 0;
		// 抽奖
		virtual const ItemDetail* pick(float fProbablity) = 0;
	};
}