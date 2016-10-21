#pragma once

#include "Item.h"
#include "IJackpot.h"
#include "IProbablity.h"
#include "IDraw.h"

#include <vector>
#include <map>

namespace lottery
{
	// ���أ�ÿ����һ�Σ�ֻ�Ǳ��һ�½����飬���Ƴ�
	class Jackpot : public IJackpot
	{
	public:
		Jackpot();
		virtual ~Jackpot();
	public:
		// ��ȡ����
		virtual const ItemDetail* pick(int nIndex);

		virtual void addReward(int nIndex, int nItemID, int nItemCount);

		virtual void removeReward(int nIndex);

		virtual void clear();
	private:
		// ����
		std::map<int, ItemDetail> m_dictReward;
	};

	//////////////////////////////////////////////////////////////////////////

	// ����
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
		// ԭʼ����
		std::map<int, float> m_mapSrcProbablity;
		// �ɼ�����
		std::vector<ProbablityDetail> m_vecDestProbablity;
		// �Ƿ����²ɼ�
		bool m_bDirty;
	};

	//////////////////////////////////////////////////////////////////////////

	// �齱
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