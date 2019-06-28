#pragma once

#include <vector>

namespace game
{
	class IFormation;
	/**
	*	������Ϣ
	*	��Ա״̬�����ȴ��ϳ����ϳ������滻��������������
	*/
	class ILineUp
	{
	public:
		virtual ~ILineUp() {}
	public:
		/**
		*	��ȡ����
		*/
		virtual const IFormation* getFormation() const = 0;
		/**
		*	��ȡ�ϳ���Ա��
		*/
		virtual int getPlayCount() = 0;
		/**
		*	��ȡ�油��Ա��
		*/
		virtual int getSubstituteCount() = 0;
		/**
		*	������Ա״̬
		*/
		virtual void setPlayerStatus(int nPlayerID, int nStatus) = 0;
		/**
		*	��ȡ��Ա״̬
		*/
		virtual int getPlayerStatus(int nPlayerID) const = 0;
		/**
		*	��ȡָ��״̬����Ա
		*/
		virtual void getPlayerByStatus(int nStatus, std::vector<int>& vPlayerIDs) const = 0;
		/**
		*	��ȡ������Ա
		*/
		virtual void getPlayIDs(std::vector<int>& vPlayerIDs) const = 0;
		/**
		*	��ȡ��������Ա
		*/
		virtual void getWaitIDs(std::vector<int>& vPlayerIDs) const = 0;
	};
}