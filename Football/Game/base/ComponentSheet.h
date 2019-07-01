#pragma once

#include <functional>
#include <map>
#include <string>
#include <typeinfo>

namespace game
{
	class Component;

	class ComponentSheet
	{
	public:
		ComponentSheet();
		virtual ~ComponentSheet();
	public:
		/**
		*	获取组件
		*	@param pszType 组件类型
		*/
		Component* getChild(const char* pszType);
		/**
		*	添加组件
		*	如果已存在，返回false并且不添加
		*	@param pComponent 组件
		*/
		bool addChild(Component* pComponent);
		/**
		*	添加组件
		*	如果已存在，返回false并且不添加
		*	@param pszType 组件类型
		*	@param pComponent 组件
		*/
		bool addChild(const char* pszType, Component* pComponent);
		/**
		*	移除组件
		*	删除旧有资源
		*	@param pszType 组件类型
		*/
		void removeChild(const char* pszType);
		/**
		*	移除所有组件
		*/
		void removeAllChildren();
		/**
		*	遍历
		*/
		void foreach(const std::function<void(Component*)>& handler);
		/**
		*	克隆
		*/
		ComponentSheet* clone();
		/**
		*	设置父节点
		*/
		void setParent(Component* parent);
		/**
		*	获取父节点
		*/
		Component* getParent();
	private:
		// 父节点
		Component* m_pParent = nullptr;
		// 子节点
		std::map<std::string, Component*> m_mapChildren;
	};
}