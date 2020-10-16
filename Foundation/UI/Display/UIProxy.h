#pragma once

#include "Layout/macros.h"
#include "render.h"

namespace ui
{
	class IElement;
	class Layout;
	class LayoutItem;

	// ui����
	class UIProxy
	{
	private:
		UIProxy();
		virtual ~UIProxy();
	public:
		static UIProxy* getInstance();
		/**
		*	����ui�����ļ�
		*/
		Layout* loadFile(const std::string& filepath);
		/**
		*	����ui�����ļ�
		*/
		bool saveFile(Layout* layout, const std::string& filepath, const math::Size& designSize);
		/**
		*	ע��ڵ����
		*/
		void registerElementParser(const std::string& name, IElement* parser);
		/**
		*	ע���ڵ����
		*/
		void unregisterElementParser(const std::string& name);
		/**
		*	�Ƴ����нڵ����
		*/
		void removeAllElementParsers();
		/**
		*	��ƴ�С
		*/
		const math::Size& getDesignSize() const;
		/**
		*	��ȡ���ַ���
		*/
		LayoutDirection getDesignDirection() const;
	protected:
		/**
		*	��ʼ��
		*/
		void init();
		/**
		*	��ȡ�ڵ�
		*/
		IElement* getElement(const std::string& name);
	protected:
		//////////////////////////////////////////////////////////////////////////
		// ���ص�һ�ڵ�
		LayoutItem* initLayoutItem(tinyxml2::XMLElement* xmlNode);
		// ���ز���
		bool loadLayout(Layout* pLayout, tinyxml2::XMLElement* xmlNode);
		// ���ظ�Ԫ��
		Layout* loadRoot(tinyxml2::XMLElement* xmlNode);
		//////////////////////////////////////////////////////////////////////////
		// ���沼��
		bool saveLayoutItem(LayoutItem* item, tinyxml2::XMLElement* xmlNode);
		// �����Ԫ��
		bool saveRoot(Layout* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, IElement*> ElementParsers;
		// �ڵ��������
		ElementParsers _elementParsers;
		// ��ƴ�С
		math::Size _designSize;
		// ���ַ���
		LayoutDirection _designDirection;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}