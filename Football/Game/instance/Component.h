#pragma once

#include "../interface/IComponent.h"

#include "Identity.h"
#include "PropertySheet.h"
#include "ComponentSheet.h"

#include <typeinfo>

namespace game
{
	/**
	*	���
	*	ÿ���̳��඼������� CREATE_COMPONENT_TYPE CREATE_COMPONENT_CLONE
	*	ÿ���̳��������ʵ�� CREATE_COMPONENT_PROPERTY|CREATE_COMPONENT_PROPERTY2
	*	ÿ���̳�����µ���� CREATE_COMPONENT_FUNCTION
	*/
	class Component : public IComponent
	{
	public:
		// �����������,ÿ���̳��඼�������
#define CREATE_COMPONENT_TYPE() \
	public:\
	virtual const char* getType() { return typeid(*this).name(); }

		// ������¡����,ÿ���̳��඼�������
#define CREATE_COMPONENT_CLONE(T) \
	public:\
	virtual IComponent* clone() \
	{\
	IComponent* pComponent = new T(); \
	copyTo(pComponent); \
	return pComponent; \
	}

		// �����������, �Զ���ʵ������
#define CREATE_COMPONENT_PROPERTY2(Enum, FunName, Type) \
	public:\
	void set##FunName(Type value) { setPropertyValue((int)Enum, (Type)(value)); } \
	virtual Type get##FunName() { return (Type)(getPropertyValue((int)Enum)); }

		// �����������, Ĭ��float����
#define CREATE_COMPONENT_PROPERTY(Enum, FunName) CREATE_COMPONENT_PROPERTY2(Enum, FunName, float)

		// �����������
#define CREATE_COMPONENT_FUNCTION(Type, FunName) \
	public:\
	Type* get##FunName() \
	{ \
		Type* value = getComponent<Type>(); \
		if (!value) \
		{ \
			value = new Type(); \
			addComponent(value); \
		} \
		return value; \
	}
		// �����������
#define CREATE_COMPONENT_FUNCTION2(Type, FunName) \
	public:\
	Type* get##FunName() \
	{ \
	Type* value = getComponent<Type>(); \
	return value; \
	}

	public:
		Component();
		virtual ~Component();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Component);
		/**
		*	��ȡ�����б�
		*/
		virtual PropertySheet* getPropertySheet();
		/**
		*	��ȡ����б�
		*/
		virtual ComponentSheet* getComponentSheet();
		/**
		*	��ȡ���
		*/
		template<typename T>
		T* getComponent();
		/**
		*	������Ϣ��Ŀ�����
		*/
		virtual bool copyTo(IComponent* pComponent);
		/**
		*	���������Ϣ
		*/
		virtual bool copy(IComponent* pComponent);
		/**
		*	����µĿ�¡���
		*/
		bool addCloneComponent(IComponent* pComponent);
		/**
		*	����µ����
		*/
		bool addComponent(IComponent* pComponent);
		/**
		*	��ȡ���
		*/
		IComponent* getComponent(const char* name);
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

	// 	template float Person::getValue<ePersonProperty>(ePersonProperty key);
	// 
	// 	template void Person::setValue<ePersonProperty>(ePersonProperty key, float value);
}