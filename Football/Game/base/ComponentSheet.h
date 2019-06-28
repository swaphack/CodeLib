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
		*/
		template<typename T>
		T* getComponent();

		/**
		*	获取组件
		*	@param pszType 组件类型
		*/
		Component* getComponent(const char* pszType);
		/**
		*	添加组件
		*	如果已存在，返回false并且不添加
		*	@param pComponent 组件
		*/
		bool addComponent(Component* pComponent);
		/**
		*	添加组件
		*	如果已存在，返回false并且不添加
		*	@param pszType 组件类型
		*	@param pComponent 组件
		*/
		bool addComponent(const char* pszType, Component* pComponent);
		/**
		*	移除组件
		*	删除旧有资源
		*	@param pszType 组件类型
		*/
		void removeComponent(const char* pszType);
		/**
		*	移除所有组件
		*/
		void removeAllComponents();
		/**
		*	遍历
		*/
		void foreach(std::function<void(Component*)> handler);
		/**
		*	克隆
		*/
		ComponentSheet* clone();
	private:
		std::map<std::string, Component*> m_mComponents;
	};

	template<typename T>
	T* ComponentSheet::getComponent()
	{
		const char* name = typeid(T).name();

		Component* pComponent = getComponent(name); 
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}
}