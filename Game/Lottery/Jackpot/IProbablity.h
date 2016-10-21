#pragma once

namespace lottery
{
	/**
	*	����
	*/
	struct ProbablityDetail
	{
		// ����ֵ
		float Value;
		// ��������
		int Index;
	};

	// ����
	class IProbablity
	{
	public:
		virtual ~IProbablity() {}
	public:
		// ��ȡ��������
		virtual int pick(float fProbablity) = 0;
		/**
		*	��Ӹ���
		*	@param nIndex ����
		*	@param fProbablity ����
		*/
		virtual void addIndex(int nIndex, float fProbablity) = 0;
		/**
		*	�Ƴ�����
		*	@param nIndex ����
		*/
		virtual void removeIndex(int nIndex) = 0;
		/**
		*	��ո�����Ϣ
		*/
		virtual void clear() = 0;
	};
}