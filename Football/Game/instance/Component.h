#pragma once

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
	class Component : public Identity
	{
	public:
		// �����������,ÿ���̳��඼�������
#define CREATE_COMPONENT_TYPE() \
	public:\
	virtual const char* getType() { return typeid(*this).name(); }

		// ������¡����,ÿ���̳��඼�������
#define CREATE_COMPONENT_CLONE(T) \
	public:\
	virtual Component* clone() \
	{\
	Component* pComponent = new T(); \
	copyTo(pComponent); \
	return pComponent; \
	}

		/** 
		*	���������ȡ���Ժ��������Է���, ����Ϊʵ������
		*	@param Enum ö��
		*	@param FunName ��������
		*	@param Type ����
		*/
#define CREATE_COMPONENT_PROPERTY2(Enum, FunName, Type) \
	public:\
	void set##FunName(Type value) { setPropertyValue((int)Enum, (Type)(value)); } \
	virtual Type get##FunName() { return (Type)(getPropertyValue((int)Enum)); }

		/**
		*	�����������, Ĭ��float����
		*	@param Enum ö��
		*	@param FunName ��������
		*/
#define CREATE_COMPONENT_PROPERTY(Enum, FunName) CREATE_COMPONENT_PROPERTY2(Enum, FunName, float)

		/**
		*	���������ȡ������������ʱ������һ���µ�
		*	@param Type �������
		*	@param FunName ��������
		*/
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
		/**
		*	���������ȡ����
		*	@param Type �������
		*	@param FunName ��������
		*/
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
		*	��ȡ����ֵ
		*/
		float getPropertyValue(int key);
		/**
		*	��������ֵ
		*/
		void setPropertyValue(int key, float value);
		/**
		*	��������ֵ
		*/
		void setPropertyChangedHandler(int key, PropertyHandler handler);

		/**
		*	��ȡ���
		*/
		template<typename T>
		T* getComponent();
		/**
		*	����µ����
		*/
		bool addComponent(Component* pComponent);
		/**
		*	��ȡ���
		*/
		Component* getComponent(const char* name);

		/**
		*	������Ϣ��Ŀ�����
		*/
		bool copyTo(Component* pComponent);
		/**
		*	���������Ϣ
		*/
		bool copy(Component* pComponent);
	protected:
		/**
		*	��ȡ�����б�
		*/
		PropertySheet* getPropertySheet();
		/**
		*	��ȡ����б�
		*/
		ComponentSheet* getComponentSheet();
	private:
		// �����б�
		PropertySheet* m_pPropertySheet;
		// ����б�
		ComponentSheet* m_pComponentSheet;
	};

	template<typename T>
	T* Component::getComponent()
	{
		const char* name = typeid(T).name();
		if (name == nullptr)
		{
			return nullptr;
		}

		Component* pComponent = getComponentSheet()->getComponent(name);
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}

	// 	template float Person::getValue<ePersonProperty>(ePersonProperty key);
	// 
	// 	template void Person::setValue<ePersonProperty>(ePersonProperty key, float value);
}