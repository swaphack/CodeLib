#pragma once

#include <functional>

namespace game
{
	typedef std::function<void(int type, float newValue, float lastValue)> PropertyHandler;

	/**
	*	属性
	*/
	class Property
	{
	public:
		Property();
		~Property();
	public:
		/**
		*	设置属性类型
		*	@see eProperty
		*/
		void setType(int nType);
		/**
		*	属性类型
		*	@see eProperty
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
		*	重置属性值
		*/
		void reset();
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
		// 类型
		int m_nType;
		// 值
		float m_nValue;
		// 属性值改变时处理
		PropertyHandler m_pHandler;
	};
}