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
		virtual int getType() = 0;
		/**
		*	值
		*/
		virtual float getValue() = 0;
	};
}