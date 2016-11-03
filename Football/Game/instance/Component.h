#pragma once

#include "../interface/IComponent.h"

#include "Identity.h"
#include "PropertySheet.h"
#include "ComponentSheet.h"

#include <typeinfo>

namespace game
{
	// 获取组件类型
#define GET_COMPONENT_TYPE(T) typeid(T).name()

	// 创建组件类型
#define CREATE_COMPONENT_TYPE() \
	virtual const char* getType() { return GET_COMPONENT_TYPE(*this); }

	class Component : public IComponent
	{
	public:
		Component();
		virtual ~Component();
	public:
		CREATE_COMPONENT_TYPE();

		/**
		*	获取属性列表
		*/
		virtual PropertySheet* getPropertySheet();
		/**
		*	获取组件列表
		*/
		virtual ComponentSheet* getComponentSheet();
		/**
		*	添加组件
		*/
		void addComponent(IComponent* pComponent);
		/**
		*	获取组件
		*/
		template<typename T>
		T* getComponent();
		/**
		*	克隆
		*/
		virtual IComponent* clone();
	protected:
		/**
		*	设置属性值
		*/
		void setPropertyValue(int key, float value);
		/**
		*	设置属性值
		*/
		void setPropertyChangedHandler(int key, PropertyHandler handler);
		/**
		*	获取属性值
		*/
		float getPropertyValue(int key);
	private:
		// 属性列表
		PropertySheet* m_pPropertySheet;
		// 组件列表
		ComponentSheet* m_pComponentSheet;
	};

	template<typename T>
	T* Component::getComponent()
	{
		return getComponentSheet()->getComponent<T>();
	}
}