#pragma once

namespace game
{
	class ISystem;
	/**
	*	系统控制器
	*/
	class ISystemController
	{
	public:
		virtual ~ISystemController() {}
	public:
		/**
		*	添加一个新系统
		*/
		virtual void addSystem(ISystem* pSystem) = 0;
		/**
		*	移除一个已有的系统
		*/
		virtual void removeSystem(ISystem* pSystem) = 0;
		/**
		*	更新时间，运转系统
		*/
		virtual void update() = 0;
	};
}