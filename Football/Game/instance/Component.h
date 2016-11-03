#pragma once

#include "../interface/IComponent.h"

#include "Identity.h"
#include "PropertySheet.h"
#include "ComponentSheet.h"

#include <typeinfo>

namespace game
{
	// ��ȡ�������
#define GET_COMPONENT_TYPE(T) typeid(T).name()

	// �����������
#define CREATE_COMPONENT_TYPE() \
	virtual const char* getType() { return GET_COMPONENT_TYPE(*this); }

	class Component : public IComponent
	{
	public:
		Component();
		virtual ~Component();
	public:
		CREATE_COMPONENT_TYPE();

		/**
		*	��ȡ�����б�
		*/
		virtual PropertySheet* getPropertySheet();
		/**
		*	��ȡ����б�
		*/
		virtual ComponentSheet* getComponentSheet();
		/**
		*	������
		*/
		void addComponent(IComponent* pComponent);
		/**
		*	��ȡ���
		*/
		template<typename T>
		T* getComponent();
		/**
		*	��¡
		*/
		virtual IComponent* clone();
	protected:
		/**
		*	��������ֵ
		*/
		void setPropertyValue(int key, float value);
		/**
		*	��������ֵ
		*/
		void setPropertyChangedHandler(int key, PropertyHandler handler);
		/**
		*	��ȡ����ֵ
		*/
		float getPropertyValue(int key);
	private:
		// �����б�
		PropertySheet* m_pPropertySheet;
		// ����б�
		ComponentSheet* m_pComponentSheet;
	};

	template<typename T>
	T* Component::getComponent()
	{
		return getComponentSheet()->getComponent<T>();
	}
}