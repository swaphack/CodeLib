#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	等级
	*/
	class Level : public Component
	{
	public:
		Level();
		virtual ~Level();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Level);
	public:
		/**
		*	获取当前等级
		*/
		CREATE_COMPONENT_PROPERTY(uint16_t, Level);
		/**
		*	获取当前经验
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, Experience);
		/**
		*	当前等级经验
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, LevelExperience);
	public:
		/**
		*	是否可以升级
		*/
		bool canUpgrade();
		/**
		*	获取剩余升级所需经验
		*/
		uint64_t getRemainUpgradeExp();
		/**
		*	升级
		*/
		bool upgrade();
		/**
		*	增加经验
		*/
		bool addExperience(uint64_t value);
	};
}