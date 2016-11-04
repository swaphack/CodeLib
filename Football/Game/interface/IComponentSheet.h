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
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pComponent ���
		*/
		virtual bool addComponent(IComponent* pComponent) = 0;
		/**
		*	������
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pszType �������
		*	@param pComponent ���
		*/
		virtual bool addComponent(const char* pszType, IComponent* pComponent) = 0;
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