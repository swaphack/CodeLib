#pragma once

namespace game
{
	class PropertySheet;
	class ComponentSheet;
	/**
	*	���
	*/
	class IComponent
	{
	public:
		virtual ~IComponent() {}
	public:
		/**
		*	�������
		*/
		virtual const char* getType() = 0;
		/**
		*	��ȡ�����б�
		*/
		virtual PropertySheet* getPropertySheet() = 0;
		/**
		*	��ȡ����б�
		*/
		virtual ComponentSheet* getComponentSheet() = 0;
		/**
		*	��¡
		*/
		virtual IComponent* clone() = 0;
		/**
		*	������Ϣ��Ŀ�����
		*/
		virtual bool copyTo(IComponent*) = 0;
		/**
		*	���������Ϣ
		*/
		virtual bool copy(IComponent* pComponent) = 0;
	};
}