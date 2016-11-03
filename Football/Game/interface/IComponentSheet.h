#pragma once

#include <functional>

namespace game
{
	class IComponent;

	/**
	*	组件列表
	*/
	class IComponentSheet
	{
	public:
		virtual ~IComponentSheet() {}
	public:
		/**
		*	获取组件
		*	@param pszType 组件类型
		*/
		virtual IComponent* getComponent(const char* pszType) = 0;
		/**
		*	添加组件
		*	@param pComponent 组件
		*/
		virtual void addComponent(IComponent* pComponent) = 0;
		/**
		*	移除组件
		*	@param pszType 组件类型
		*/
		virtual void removeComponent(const char* pszType) = 0;
		/**
		*	移除所有组件
		*/
		virtual void removeAllComponents() = 0;
		/**
		*	遍历
		*/
		virtual void foreach(std::function<void(IComponent*)> handler) = 0;
		/**
		*	克隆
		*/
		virtual IComponentSheet* clone() = 0;
	};
}