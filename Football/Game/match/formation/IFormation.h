#pragma once

#include <map>

namespace game
{
	class IPlayer;
	/**
	*	位置索引 {索引，(位置,球员）}
	*/
	typedef std::map<int, std::pair<int, int> > IndexPosition;
	/**
	*	阵型
	*/
	class IFormation
	{
	public:
		virtual ~IFormation(){}
	public:
		/**
		*	获取阵型编号
		*/
		virtual int getID() const = 0;
		/**
		*	设置阵型描述
		*/
		virtual void setDescribe(const char* pDescribe) = 0;
		/**
		*	获取阵型描述
		*/
		virtual const char* toDescribe() const = 0;
		/**
		*	获取位置
		*/
		virtual int getPosition(int nIndex) const = 0;
		/**
		*	设置指定位置的球员定位
		*/
		virtual void setPosition(int nIndex, int nPosition) = 0;
		/**
		*	重置指定位置的球员定位
		*/
		virtual void resetPosition(int nIndex) = 0;
		/**
		*	获取运动员
		*/
		virtual int getPlayer(int nIndex) const = 0;
		/**
		*	设置上阵运动员
		*/
		virtual bool putPlayer(int nIndex, int nPlayerID) = 0;
		/**
		*	移除上阵运动员
		*/
		virtual bool movePlayer(int nIndex) = 0;
	};
}