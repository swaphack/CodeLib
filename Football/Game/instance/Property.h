#pragma once

#include <functional>

namespace game
{
	typedef std::function<void(int type, float newValue, float lastValue)> PropertyHandler;

	class Property
	{
	public:
		Property();
		~Property();
	public:
		/**
		*	设置属性类型
		*/
		void setType(int nType);
		/**
		*	属性类型
		*/
		int getType() const;
		/**
		*	设置属性值
		*/
		void setValue(float fValue);
		/**
		*	获取属性值
		*/
		float getValue() const;
		/**
		*	改变属性值
		*/
		void addValue(float value);
		/**
		*	设置属性改变时的通知
		*/
		void setChangedHandler(PropertyHandler handler);
		/**
		*	属性改变时的通知
		*/
		PropertyHandler getChangedHandler();
		/**
		*	克隆
		*/
		Property* clone();
	protected:
		/**
		*	通知属性改变
		*/
		void onChangedHandler(float newValue);
	private:
		int m_nType;
		float m_nValue;
		PropertyHandler m_pHandler;
	};
}