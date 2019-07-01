#pragma once

#include "Identity.h"
#include "Property.h"
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
	virtual const char* getType() const { return typeid(*this).name(); }

		// ������¡����,ÿ���̳��඼�������
#define CREATE_COMPONENT_CLONE(T) \
	public:\
	virtual T* clone() \
	{\
		T* pComponent = new T(); \
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
			value = addComponent<Type>(); \
		} \
		return value; \
	}
		/**
		*	���������ȡ����
		*	@param Type �������
		*	@param FunName ��������
		*/
#define GET_COMPONENT_FUNCTION(Type, FunName) \
	public:\
	Type* get##FunName() \
	{ \
	Type* value = getComponent<Type>(); \
	return value; \
	}

		// ��x����ַ��������x�Ǻ�Ҳ��չ����
#define TO_STRING(x)   #x
		/**
		*	���������ȡ���Ժ��������Է���, ����Ϊʵ������
		*	@param FunName ��������
		*	@param Type ����
		*/
#define CREATE_COMPONENT_PROPERTY(Type, FunName) \
	public:\
	void set##FunName(const Type& value)\
	{ \
		std::string key = TO_STRING(FunName); \
		getProperty()->setValue(key, value);\
	} \
	Type get##FunName() \
	{ \
		Type value;\
		std::string key = TO_STRING(FunName); \
		getProperty()->getValue(key, value); \
		return value; \
	}
		/**
		*	���������ȡ���Ժ��������Է���, ����Ϊʵ������
		*	@param FunName ��������
		*	@param Type ����
		*/
#define CREATE_COMPONENT_PROPERTY_ENUM(Type, FunName) \
	public:\
	void set##FunName(const Type& value)\
	{ \
		std::string key = TO_STRING(FunName); \
		getProperty()->setValue(key, (int16_t)value);\
	} \
	Type get##FunName() \
	{ \
		int16_t value;\
		std::string key = TO_STRING(FunName); \
		getProperty()->getValue(key, value); \
		return (Type)value; \
	}
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
		bool copyTo(Component* pComponent);
		/**
		*	���������Ϣ
		*/
		bool copy(Component* pComponent);

		/**
		*	��ȡ���
		*/
		template<typename T>
		T* getComponent();
		/**
		*	������
		*/
		template<typename T>
		T* addComponent();
	protected:
		/**
		*	��ȡ����б�
		*/
		ComponentSheet* getComponentSheet();
		/**
		*	��ȡ����
		*/
		Property* getProperty();
	private:
		// ����б�
		ComponentSheet* m_pComponentSheet = nullptr;
		// ����
		Property* m_pProperty = nullptr;
	};

	template<typename T>
	T* Component::getComponent()
	{
		const char* name = typeid(T).name();
		if (name == nullptr)
		{
			return nullptr;
		}

		Component* pComponent = getComponent(name);
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}


	template<typename T>
	T* Component::addComponent()
	{
		T* ptr = getComponent<T>();
		if (ptr != nullptr)
		{
			return ptr;
		}
		ptr = new T();
		if (addComponent(ptr))
		{
			return ptr;
		}
		delete ptr;
		return nullptr;
	}
}