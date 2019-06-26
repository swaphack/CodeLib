#pragma once

#include "Identity.h"
#include "PropertySheet.h"
#include "ComponentSheet.h"

#include <typeinfo>

namespace game
{
	/**
	*	组件
	*	每个继承类都必须添加 CREATE_COMPONENT_TYPE CREATE_COMPONENT_CLONE
	*	每个继承类的属性实现 CREATE_COMPONENT_PROPERTY|CREATE_COMPONENT_PROPERTY
	*	每个继承类的新的组件 CREATE_COMPONENT_FUNCTION
	*/
	class Component : public Identity
	{
	public:
		// 创建组件类型,每个继承类都必须调用
#define CREATE_COMPONENT_TYPE() \
	public:\
	virtual const char* getType() { return typeid(*this).name(); }

		// 创建克隆方法,每个继承类都必须调用
#define CREATE_COMPONENT_CLONE(T) \
	public:\
	virtual Component* clone() \
		{\
	Component* pComponent = new T(); \
	copyTo(pComponent); \
	return pComponent; \
		}
		/**
		*	创建组件获取方法，不存在时，创建一个新的
		*	@param Type 组件类型
		*	@param FunName 函数名称
		*/
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
		/**
		*	创建组件获取方法
		*	@param Type 组件类型
		*	@param FunName 函数名称
		*/
#define GET_COMPONENT_FUNCTION2(Type, FunName) \
	public:\
	Type* get##FunName() \
		{ \
	Type* value = getComponent<Type>(); \
	return value; \
		}

		/**
		*	创建组件获取属性和设置属性方法, 保存为实数类型
		*	@param FunName 函数名称
		*	@param Type 类型
		*/
#define CREATE_COMPONENT_PROPERTY(FunName, Type) \
	public:\
	void set##FunName(Type value) { _##FunName = value; } \
	Type get##FunName() { return _##FunName; } \
	private: \
	Type _##FunName;


	public:
		Component();
		virtual ~Component();
	public:
		/**
		*	创建：获取组件名称
		*/
		CREATE_COMPONENT_TYPE();
		/**
		*	创建：获取组件复制体
		*/
		CREATE_COMPONENT_CLONE(Component);
		/**
		*	获取组件
		*/
		template<typename T>
		T* getComponent();
		/**
		*	添加新的组件
		*/
		bool addComponent(Component* pComponent);
		/**
		*	移除组件
		*/
		void removeComponent(Component* pComponent);
		/**
		*	获取组件
		*/
		Component* getComponent(const char* name);
		/**
		*	移除所有组件
		*/
		void removeAllComponents();

		/**
		*	复制信息到目标组件
		*/
		virtual bool copyTo(Component* pComponent);
		/**
		*	复制组件信息
		*/
		virtual bool copy(Component* pComponent);
	protected:
		/**
		*	获取组件列表
		*/
		ComponentSheet* getComponentSheet();
	private:
		// 组件列表
		ComponentSheet* m_pComponentSheet;
	};

	template<typename T>
	T* Component::getComponent()
	{
		const char* name = typeid(T).name();
		if (name == nullptr)
		{
			return nullptr;
		}

		Component* pComponent = getComponentSheet()->getComponent(name);
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}

	// 	template float Person::getValue<ePersonProperty>(ePersonProperty key);
	// 
	// 	template void Person::setValue<ePersonProperty>(ePersonProperty key, float value);
}