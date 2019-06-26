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
		PropertyComponent();
		virtual ~PropertyComponent();
	public:
		/**
		*	设置属性值
		*/
		void setValue(int key, float value);
		/**
		*	获取属性值
		*/
		float getValue(int key);
		/**
		*	设置属性值
		*/
		void setChangedHandler(int key, PropertyHandler handler);
	public:

	protected:
		PropertySheet* getPropertySheet();
	private:
		PropertySheet m_PropertySheet;
	};
}