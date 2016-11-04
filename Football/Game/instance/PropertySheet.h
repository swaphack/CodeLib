#pragma once


#include "Property.h"

#include <map>
#include <functional>

namespace game
{
	class PropertySheet
	{
	public:
		PropertySheet();
		~PropertySheet();
	public:
		/**
		*	获取属性
		*/
		Property* getProperty(int nPropertyType);
		/**
		*	添加属性
		*	添加新的属性前，需判断是否存在
		*/
		void addProperty(Property* pProperty);
		/**
		*	移除属性
		*/
		void removeProperty(int nPropertyType);
		/**
		*	移除所有属性
		*/
		void removeAllProperties();
		/**
		*	遍历
		*/
		void foreach(std::function<void(Property*)> handler);
		/**
		*	克隆
		*/
		PropertySheet* clone();
	private:
		typedef std::map<int, Property*> Properties;

		Properties m_mProperties;
	};
}