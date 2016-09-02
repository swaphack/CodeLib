#pragma once

#include <vector>

namespace game
{
	/**
	*	������Ϣ
	*/
	class ILineUp
	{
	public:
		virtual ~ILineUp() {}
	public:
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
		virtual const std::vector<int>& getPlayIDs() const = 0;
		/**
		*	��ȡ��������Ա
		*/
		virtual const std::vector<int>& getWaitIDs() const = 0;
	};
}