#pragma once

namespace lottery
{
	class IJackpot;
	class IProbablity;
	struct Item;

	// �齱
	class IDraw
	{
	public:
		virtual ~IDraw() {}
	public:
		// ���ý���
		virtual void setJackpot(IJackpot* pJackpot) = 0;
		// ��ȡ����
		virtual IJackpot* getJackpot() = 0;
		// ���ø���
		virtual void setProbablity(IProbablity* pPropbablity) = 0;
		// ���ø���
		virtual IProbablity* getProbablity() = 0;
		// �齱
		virtual const ItemDetail* pick(float fProbablity) = 0;
	};
}