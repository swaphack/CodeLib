#pragma once

#include "Component.h"
#include "PropertySheet.h"

namespace game
{
	/**
	*	���Կؼ�
	*/
	class PropertyComponent : Component
	{
	public:
		PropertyComponent();
		virtual ~PropertyComponent();
	public:
		/**
		*	��������ֵ
		*/
		void setValue(int key, float value);
		/**
		*	��ȡ����ֵ
		*/
		float getValue(int key);
		/**
		*	��������ֵ
		*/
		void setChangedHandler(int key, PropertyHandler handler);
	public:

	protected:
		PropertySheet* getPropertySheet();
	private:
		PropertySheet m_PropertySheet;
	};
}