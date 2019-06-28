#pragma once

namespace game
{
	/**
	*	等级
	*/
	class ILevel
	{
	public:
		virtual ~ILevel() {}
	public:
		/**
		*	获取当前等级
		*/
		virtual int getLevel() const = 0;
		/**
		*	获取当前经验
		*/
		virtual int getExperience() const = 0;
		/**
		*	是否可以升级
		*/
		virtual bool canUpgrade() const = 0;
		/**
		*	获取剩余升级所需经验
		*/
		virtual int getRemainUpgradeExp() const = 0;
		/**
		*	获取下一级升级所需经验
		*/
		virtual int getNextUpgradeExp() const = 0;
		/**
		*	升级
		*/
		virtual bool upgrade() = 0;
		/**
		*	增加经验
		*/
		virtual bool addExperience(int value) = 0;
	};
}