#pragma once

#include "Component.h"
#include "PropertySheet.h"

namespace game
{
	/**
	*	属性控件
	*/
	class PropertyComponent : Component
	{
	public:
		/**
		*	创建组件获取属性和设置属性方法, 保存为实数类型
		*	@param Enum 枚举
		*	@param FunName 函数名称
		*	@param Type 类型
		*/
#define CREATE_COMPONENT_PROPERTY2(Enum, FunName, Type) \
	public:\
	void set##FunName(Type value) { setPropertyValue((int)Enum, (Type)(value)); } \
	virtual Type get##FunName() { return (Type)(getPropertyValue((int)Enum)); }

		/**
		*	创建组件属性, 默认float类型
		*	@param Enum 枚举
		*	@param FunName 函数名称
		*/
#define CREATE_COMPONENT_PROPERTY(Enum, FunName) CREATE_COMPONENT_PROPERTY2(Enum, FunName, float)
	public:
		PropertyComponent();
		virtual ~PropertyComponent();
	public:
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
	protected:
		PropertySheet* getPropertySheet();
	private:
		PropertySheet m_PropertySheet;
	};
}