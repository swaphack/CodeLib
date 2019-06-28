#pragma once

#include <vector>

namespace game
{
	class IFormation;
	/**
	*	上阵信息
	*	球员状态包含等待上场，上场，被替换下来，被罚下来
	*/
	class ILineUp
	{
	public:
		virtual ~ILineUp() {}
	public:
		/**
		*	获取阵型
		*/
		virtual const IFormation* getFormation() const = 0;
		/**
		*	获取上场球员数
		*/
		virtual int getPlayCount() = 0;
		/**
		*	获取替补球员数
		*/
		virtual int getSubstituteCount() = 0;
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
		virtual void getPlayIDs(std::vector<int>& vPlayerIDs) const = 0;
		/**
		*	获取可上阵球员
		*/
		virtual void getWaitIDs(std::vector<int>& vPlayerIDs) const = 0;
	};
}