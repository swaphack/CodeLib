#pragma once

#include <vector>

namespace game
{
	/**
	*	上阵信息
	*/
	class ILineUp
	{
	public:
		virtual ~ILineUp() {}
	public:
		/**
		*	设置球员状态
		*/
		virtual void setPlayerStatus(int nPlayerID, int nStatus) = 0;
		/**
		*	获取球员状态
		*/
		virtual int getPlayerStatus(int nPlayerID) const = 0;
		/**
		*	获取指定状态的球员
		*/
		virtual void getPlayerByStatus(int nStatus, std::vector<int>& vPlayerIDs) const = 0;
		/**
		*	获取上阵球员
		*/
		virtual const std::vector<int>& getPlayIDs() const = 0;
		/**
		*	获取可上阵球员
		*/
		virtual const std::vector<int>& getWaitIDs() const = 0;
	};
}