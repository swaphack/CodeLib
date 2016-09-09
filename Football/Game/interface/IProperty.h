#pragma once

namespace game
{
	/**
	*	����
	*/
	class IProperty
	{
	public:
		virtual ~IProperty() {}
	public:
		/**
		*	��������
		*/
		virtual int getType() const = 0;
		/**
		*	��ȡ����ֵ
		*/
		virtual float getValue() const = 0;
		/**
		*	��������ֵ
		*/
		virtual void setValue() = 0;
	};
}