#pragma once

namespace game
{
	class IPlayer;

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
		*	获取运动员
		*/
		virtual const IPlayer* getPlayer(int nIndex) const = 0;
		/**
		*	设置上阵运动员
		*/
		virtual bool putPlayer(int nIndex, IPlayer* pPlayer) = 0;
		/**
		*	移除上阵运动员
		*/
		virtual bool movePlayer(int nIndex) = 0;
	};
}