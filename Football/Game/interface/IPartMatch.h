#pragma once

namespace game
{
	class ITeam;
	class IRule;
	class IField;
	class IFieldSide;

	/**
	*	比赛段
	*/
	class IPartMatch
	{
	public:
		virtual ~IPartMatch() {}
	public:
		/**
		*	正常时间
		*/
		virtual float getNormalTime() const = 0;
		/**
		*	补时时间
		*/
		virtual float getAllowanceTime() const = 0;
		/**
		*	比赛是否结束
		*/
		virtual bool isMatchOver() const = 0;
		/**
		*	比赛规则
		*/
		virtual const IRule* getRule() const = 0;
		/**
		*	比赛场地
		*/
		virtual const IField* getField() const = 0;
		/**
		*	左边场地
		*/
		virtual IFieldSide* getLeftSide() = 0;
		/**
		*	右边场地
		*/
		virtual IFieldSide* getRightSide() = 0;
	};
}