#pragma once

#include "../interface/IComponentSheet.h"
#include "Component.h"

#include <functional>
#include <map>
#include <string>

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
		*/
		virtual void addComponent(IComponent* pComponent);
		/**
		*	移除组件
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
		const char* name = GET_COMPONENT_TYPE(T);

		IComponent* pComponent = getComponent(name); 
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}
}