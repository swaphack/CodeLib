#pragma once

#include "../interface/IComponentSheet.h"
#include "Component.h"

#include <functional>
#include <map>
#include <string>
#include <typeinfo>

namespace game
{
	class ComponentSheet : public IComponentSheet
	{
	public:
		ComponentSheet();
		virtual ~ComponentSheet();
	public:
		/**
		*	��ȡ���
		*/
		template<typename T>
		T* getComponent();

		/**
		*	��ȡ���
		*	@param pszType �������
		*/
		virtual IComponent* getComponent(const char* pszType);
		/**
		*	������
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pComponent ���
		*/
		virtual bool addComponent(IComponent* pComponent);
		/**
		*	������
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pszType �������
		*	@param pComponent ���
		*/
		virtual bool addComponent(const char* pszType, IComponent* pComponent);
		/**
		*	�Ƴ����
		*	ɾ��������Դ
		*	@param pszType �������
		*/
		virtual void removeComponent(const char* pszType);
		/**
		*	�Ƴ��������
		*/
		virtual void removeAllComponents();
		/**
		*	����
		*/
		void foreach(std::function<void(IComponent*)> handler);
		/**
		*	��¡
		*/
		virtual IComponentSheet* clone();
	private:
		std::map<std::string, IComponent*> m_mComponents;
	};

	template<typename T>
	T* ComponentSheet::getComponent()
	{
		const char* name = typeid(T).name();

		IComponent* pComponent = getComponent(name); 
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}
}