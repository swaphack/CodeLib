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
	*	ÿ���̳��������ʵ�� CREATE_COMPONENT_PROPERTY|CREATE_COMPONENT_PROPERTY
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
#define GET_COMPONENT_FUNCTION2(Type, FunName) \
	public:\
	Type* get##FunName() \
		{ \
	Type* value = getComponent<Type>(); \
	return value; \
		}

		/**
		*	���������ȡ���Ժ��������Է���, ����Ϊʵ������
		*	@param FunName ��������
		*	@param Type ����
		*/
#define CREATE_COMPONENT_PROPERTY(FunName, Type) \
	public:\
	void set##FunName(Type value) { _##FunName = value; } \
	Type get##FunName() { return _##FunName; } \
	private: \
	Type _##FunName;


	public:
		Component();
		virtual ~Component();
	public:
		/**
		*	��������ȡ�������
		*/
		CREATE_COMPONENT_TYPE();
		/**
		*	��������ȡ���������
		*/
		CREATE_COMPONENT_CLONE(Component);
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
		*	�Ƴ����
		*/
		void removeComponent(Component* pComponent);
		/**
		*	��ȡ���
		*/
		Component* getComponent(const char* name);
		/**
		*	�Ƴ��������
		*/
		void removeAllComponents();

		/**
		*	������Ϣ��Ŀ�����
		*/
		virtual bool copyTo(Component* pComponent);
		/**
		*	���������Ϣ
		*/
		virtual bool copy(Component* pComponent);
	protected:
		/**
		*	��ȡ����б�
		*/
		ComponentSheet* getComponentSheet();
	private:
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