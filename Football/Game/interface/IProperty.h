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
		virtual int getType() = 0;
		/**
		*	ֵ
		*/
		virtual float getValue() = 0;
	};
}