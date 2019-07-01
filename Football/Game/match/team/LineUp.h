#pragma once

#include <vector>
#include "../macros.h"

namespace game
{
	class Formation;
	/**
	*	上阵信息
	*	球员状态包含等待上场，上场，被替换下来，被罚下来
	*/
	class LineUp : public Component
	{
	public:
		/**
		*	在线状态
		*/
		enum LineUpStatus
		{
			ELUS_OnLine,
			ELUS_OffLine,
		};
	public:
		LineUp();
		virtual ~LineUp();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(LineUp);
	public:
		/**
		*	获取阵型
		*/
		const Formation* getFormation() const;
		/**
		*	获取上场球员数
		*/
		int getPlayCount();
		/**
		*	获取替补球员数
		*/
		int getSubstituteCount();
		/**
		*	设置球员状态
		*/
		void setPlayerStatus(uint64_t nPlayerID, int nStatus);
		/**
		*	获取球员状态
		*/
		int getPlayerStatus(uint64_t nPlayerID) const;
		/**
		*	获取指定状态的球员
		*/
		void getPlayerByStatus(int nStatus, std::vector<uint64_t>& vPlayerIDs) const;
		/**
		*	获取上阵球员
		*/
		void getPlayIDs(std::vector<uint64_t>& vPlayerIDs) const;
		/**
		*	获取可上阵球员
		*/
		void getWaitIDs(std::vector<uint64_t>& vPlayerIDs) const;
	};
}