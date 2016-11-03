#pragma once

#include <functional>

namespace game
{
	class IComponent;

	/**
	*	����б�
	*/
	class IComponentSheet
	{
	public:
		virtual ~IComponentSheet() {}
	public:
		/**
		*	��ȡ���
		*	@param pszType �������
		*/
		virtual IComponent* getComponent(const char* pszType) = 0;
		/**
		*	������
		*	@param pComponent ���
		*/
		virtual void addComponent(IComponent* pComponent) = 0;
		/**
		*	�Ƴ����
		*	@param pszType �������
		*/
		virtual void removeComponent(const char* pszType) = 0;
		/**
		*	�Ƴ��������
		*/
		virtual void removeAllComponents() = 0;
		/**
		*	����
		*/
		virtual void foreach(std::function<void(IComponent*)> handler) = 0;
		/**
		*	��¡
		*/
		virtual IComponentSheet* clone() = 0;
	};
}