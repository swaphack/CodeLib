#pragma once

namespace game
{
	/**
	*	属性
	*/
	class IProperty
	{
	public:
		virtual ~IProperty() {}
	public:
		/**
		*	属性类型
		*/
		virtual int getType() const = 0;
		/**
		*	获取属性值
		*/
		virtual float getValue() const = 0;
		/**
		*	设置属性值
		*/
		virtual void setValue() = 0;
	};
}