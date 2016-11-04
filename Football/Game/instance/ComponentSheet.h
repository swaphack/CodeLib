#pragma once

#include "../interface/IComponentSheet.h"
#include "Component.h"

#include <functional>
#include <map>
#include <string>
#include <typeinfo>

namespace game
{
	class ComponentSheet : public IComponentSheet
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
		virtual IComponent* getComponent(const char* pszType);
		/**
		*	添加组件
		*	如果已存在，返回false并且不添加
		*	@param pComponent 组件
		*/
		virtual bool addComponent(IComponent* pComponent);
		/**
		*	添加组件
		*	如果已存在，返回false并且不添加
		*	@param pszType 组件类型
		*	@param pComponent 组件
		*/
		virtual bool addComponent(const char* pszType, IComponent* pComponent);
		/**
		*	移除组件
		*	删除旧有资源
		*	@param pszType 组件类型
		*/
		virtual void removeComponent(const char* pszType);
		/**
		*	移除所有组件
		*/
		virtual void removeAllComponents();
		/**
		*	遍历
		*/
		void foreach(std::function<void(IComponent*)> handler);
		/**
		*	克隆
		*/
		virtual IComponentSheet* clone();
	private:
		std::map<std::string, IComponent*> m_mComponents;
	};

	template<typename T>
	T* ComponentSheet::getComponent()
	{
		const char* name = typeid(T).name();

		IComponent* pComponent = getComponent(name); 
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}
}