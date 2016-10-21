#pragma once

namespace lottery
{
	/**
	*	概率
	*/
	struct ProbablityDetail
	{
		// 概率值
		float Value;
		// 奖励索引
		int Index;
	};

	// 概率
	class IProbablity
	{
	public:
		virtual ~IProbablity() {}
	public:
		// 抽取奖励索引
		virtual int pick(float fProbablity) = 0;
		/**
		*	添加概率
		*	@param nIndex 索引
		*	@param fProbablity 概率
		*/
		virtual void addIndex(int nIndex, float fProbablity) = 0;
		/**
		*	移除概率
		*	@param nIndex 索引
		*/
		virtual void removeIndex(int nIndex) = 0;
		/**
		*	清空概率信息
		*/
		virtual void clear() = 0;
	};
}