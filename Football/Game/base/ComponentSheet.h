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
		*	@param pszType �������
		*/
		Component* getChild(const char* pszType);
		/**
		*	������
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pComponent ���
		*/
		bool addChild(Component* pComponent);
		/**
		*	������
		*	����Ѵ��ڣ�����false���Ҳ����
		*	@param pszType �������
		*	@param pComponent ���
		*/
		bool addChild(const char* pszType, Component* pComponent);
		/**
		*	�Ƴ����
		*	ɾ��������Դ
		*	@param pszType �������
		*/
		void removeChild(const char* pszType);
		/**
		*	�Ƴ��������
		*/
		void removeAllChildren();
		/**
		*	����
		*/
		void foreach(const std::function<void(Component*)>& handler);
		/**
		*	��¡
		*/
		ComponentSheet* clone();
		/**
		*	���ø��ڵ�
		*/
		void setParent(Component* parent);
		/**
		*	��ȡ���ڵ�
		*/
		Component* getParent();
	private:
		// ���ڵ�
		Component* m_pParent = nullptr;
		// �ӽڵ�
		std::map<std::string, Component*> m_mapChildren;
	};
}