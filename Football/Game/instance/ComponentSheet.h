#pragma once

#include "../interface/IComponentSheet.h"
#include "Component.h"

#include <functional>
#include <map>
#include <string>

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
		*/
		virtual void addComponent(IComponent* pComponent);
		/**
		*	�Ƴ����
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
		const char* name = GET_COMPONENT_TYPE(T);

		IComponent* pComponent = getComponent(name); 
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}
}