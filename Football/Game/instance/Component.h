#pragma once

#include "../interface/IComponent.h"

#include "Identity.h"
#include "PropertySheet.h"
#include "ComponentSheet.h"

#include <typeinfo>

namespace game
{
	/**
	*	组件
	*	每个继承类都必须添加 CREATE_COMPONENT_TYPE CREATE_COMPONENT_CLONE
	*	每个继承类的属性实现 CREATE_COMPONENT_PROPERTY|CREATE_COMPONENT_PROPERTY2
	*	每个继承类的新的组件 CREATE_COMPONENT_FUNCTION
	*/
	class Component : public IComponent
	{
	public:
		// 创建组件类型,每个继承类都必须调用
#define CREATE_COMPONENT_TYPE() \
	public:\
	virtual const char* getType() { return typeid(*this).name(); }

		// 创建克隆方法,每个继承类都必须调用
#define CREATE_COMPONENT_CLONE(T) \
	public:\
	virtual IComponent* clone() \
	{\
	IComponent* pComponent = new T(); \
	copyTo(pComponent); \
	return pComponent; \
	}

		// 创建组件属性, 自动义实数类型
#define CREATE_COMPONENT_PROPERTY2(Enum, FunName, Type) \
	public:\
	void set##FunName(Type value) { setPropertyValue((int)Enum, (Type)(value)); } \
	virtual Type get##FunName() { return (Type)(getPropertyValue((int)Enum)); }

		// 创建组件属性, 默认float类型
#define CREATE_COMPONENT_PROPERTY(Enum, FunName) CREATE_COMPONENT_PROPERTY2(Enum, FunName, float)

		// 创建组件方法
#define CREATE_COMPONENT_FUNCTION(Type, FunName) \
	public:\
	Type* get##FunName() \
	{ \
		Type* value = getComponent<Type>(); \
		if (!value) \
		{ \
			value = new Type(); \
			addComponent(value); \
		} \
		return value; \
	}
		// 创建组件方法
#define CREATE_COMPONENT_FUNCTION2(Type, FunName) \
	public:\
	Type* get##FunName() \
	{ \
	Type* value = getComponent<Type>(); \
	return value; \
	}

	public:
		Component();
		virtual ~Component();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Component);
		/**
		*	获取属性列表
		*/
		virtual PropertySheet* getPropertySheet();
		/**
		*	获取组件列表
		*/
		virtual ComponentSheet* getComponentSheet();
		/**
		*	获取组件
		*/
		template<typename T>
		T* getComponent();
		/**
		*	复制信息到目标组件
		*/
		virtual bool copyTo(IComponent* pComponent);
		/**
		*	复制组件信息
		*/
		virtual bool copy(IComponent* pComponent);
		/**
		*	添加新的克隆组件
		*/
		bool addCloneComponent(IComponent* pComponent);
		/**
		*	添加新的组件
		*/
		bool addComponent(IComponent* pComponent);
		/**
		*	获取组件
		*/
		IComponent* getComponent(const char* name);
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

	// 	template float Person::getValue<ePersonProperty>(ePersonProperty key);
	// 
	// 	template void Person::setValue<ePersonProperty>(ePersonProperty key, float value);
}