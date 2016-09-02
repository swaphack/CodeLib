#pragma once

namespace game
{
	class IProperty;

	/**
	*	属性列表
	*/
	class IPropertySheet
	{
	public:
		virtual ~IPropertySheet() {}
	public:
		/**
		*	获取属性
		*/
		virtual const IProperty* getProperty(int nPropertyType) const = 0;
		/**
		*	添加属性
		*/
		virtual void addProperty(IProperty* pProperty) = 0;
		/**
		*	移除属性
		*/
		virtual void removeProperty(int nPropertyType) = 0;
	};
}