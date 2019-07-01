#pragma once

#include "Identity.h"
#include "Property.h"
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
	virtual const char* getType() const { return typeid(*this).name(); }

		// 创建克隆方法,每个继承类都必须调用
#define CREATE_COMPONENT_CLONE(T) \
	public:\
	virtual T* clone() \
	{\
		T* pComponent = new T(); \
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
			value = addComponent<Type>(); \
		} \
		return value; \
	}
		/**
		*	创建组件获取方法
		*	@param Type 组件类型
		*	@param FunName 函数名称
		*/
#define GET_COMPONENT_FUNCTION(Type, FunName) \
	public:\
	Type* get##FunName() \
	{ \
	Type* value = getComponent<Type>(); \
	return value; \
	}

		// 将x变成字符串（如果x是宏也不展开）
#define TO_STRING(x)   #x
		/**
		*	创建组件获取属性和设置属性方法, 保存为实数类型
		*	@param FunName 函数名称
		*	@param Type 类型
		*/
#define CREATE_COMPONENT_PROPERTY(Type, FunName) \
	public:\
	void set##FunName(const Type& value)\
	{ \
		std::string key = TO_STRING(FunName); \
		getProperty()->setValue(key, value);\
	} \
	Type get##FunName() \
	{ \
		Type value;\
		std::string key = TO_STRING(FunName); \
		getProperty()->getValue(key, value); \
		return value; \
	}
		/**
		*	创建组件获取属性和设置属性方法, 保存为实数类型
		*	@param FunName 函数名称
		*	@param Type 类型
		*/
#define CREATE_COMPONENT_PROPERTY_ENUM(Type, FunName) \
	public:\
	void set##FunName(const Type& value)\
	{ \
		std::string key = TO_STRING(FunName); \
		getProperty()->setValue(key, (int16_t)value);\
	} \
	Type get##FunName() \
	{ \
		int16_t value;\
		std::string key = TO_STRING(FunName); \
		getProperty()->getValue(key, value); \
		return (Type)value; \
	}
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
		bool copyTo(Component* pComponent);
		/**
		*	复制组件信息
		*/
		bool copy(Component* pComponent);

		/**
		*	获取组件
		*/
		template<typename T>
		T* getComponent();
		/**
		*	添加组件
		*/
		template<typename T>
		T* addComponent();
	protected:
		/**
		*	获取组件列表
		*/
		ComponentSheet* getComponentSheet();
		/**
		*	获取属性
		*/
		Property* getProperty();
	private:
		// 组件列表
		ComponentSheet* m_pComponentSheet = nullptr;
		// 属性
		Property* m_pProperty = nullptr;
	};

	template<typename T>
	T* Component::getComponent()
	{
		const char* name = typeid(T).name();
		if (name == nullptr)
		{
			return nullptr;
		}

		Component* pComponent = getComponent(name);
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}


	template<typename T>
	T* Component::addComponent()
	{
		T* ptr = getComponent<T>();
		if (ptr != nullptr)
		{
			return ptr;
		}
		ptr = new T();
		if (addComponent(ptr))
		{
			return ptr;
		}
		delete ptr;
		return nullptr;
	}
}