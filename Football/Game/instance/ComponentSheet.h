#pragma once

#include <functional>
#include <map>
#include <string>
#include <typeinfo>

namespace game
{
	class Component;

	class ComponentSheet
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
		Component* getComponent(const char* pszType);
		/**
		*	������
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pComponent ���
		*/
		bool addComponent(Component* pComponent);
		/**
		*	������
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pszType �������
		*	@param pComponent ���
		*/
		bool addComponent(const char* pszType, Component* pComponent);
		/**
		*	�Ƴ����
		*	ɾ��������Դ
		*	@param pszType �������
		*/
		void removeComponent(const char* pszType);
		/**
		*	�Ƴ��������
		*/
		void removeAllComponents();
		/**
		*	����
		*/
		void foreach(std::function<void(Component*)> handler);
		/**
		*	��¡
		*/
		ComponentSheet* clone();
	private:
		std::map<std::string, Component*> m_mComponents;
	};

	template<typename T>
	T* ComponentSheet::getComponent()
	{
		const char* name = typeid(T).name();

		Component* pComponent = getComponent(name); 
		if (pComponent == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(pComponent);
	}
}