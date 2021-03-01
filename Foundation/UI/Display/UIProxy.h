#pragma once

#include "render.h"
#include "Layout/macros.h"
#include "Layout/LayoutItem.h"
namespace ui
{
	class IElement;
	class CtrlWidget;

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
		CtrlWidget* loadFile(const std::string& filepath, const math::Size& size);
		/**
		*	����ui�����ļ�
		*/
		bool saveFile(CtrlWidget* CtrlWidget, const std::string& filepath, const math::Size& designSize);
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
	public:
		/**
		*	Ĭ������
		*/
		const std::string& getFontPath();
		/**
		*	����Ĭ������
		*/
		void setFontPath(const std::string& fontPath);
	public:
		/**
		*	��ȡ����
		*/ 
		static ui::LayoutItem* getLayoutItem(ui::CtrlWidget* item);

		/**
		*	��ȡ�ؼ�����
		*/  
		static std::string getLayoutItemName(ui::CtrlWidget* item);

		/**
		*	��ȡ�ӽڵ�
		*/ 
		static render::Node* getChildByIndex(render::Node* node, int index);
		/**
		*	��ȡ�����ӽڵ�
		*/
		static bool getVisibleChildren(const render::Node* node, std::vector<render::Node*>& children);
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
		CtrlWidget* initWidget(tinyxml2::XMLElement* xmlNode);
		// ���ز���
		bool loadWidget(CtrlWidget* pCtrlWidget, tinyxml2::XMLElement* xmlNode);
		// ���ظ�Ԫ��
		CtrlWidget* loadRoot(tinyxml2::XMLElement* xmlNode, const math::Size& size);
		//////////////////////////////////////////////////////////////////////////
		// ���沼��
		bool saveWidget(CtrlWidget* item, tinyxml2::XMLElement* xmlNode);
		// �����Ԫ��
		bool saveRoot(CtrlWidget* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, IElement*> ElementParsers;
		// �ڵ��������
		ElementParsers _elementParsers;
		// ��ƴ�С
		math::Size _designSize;
		// ���ַ���
		LayoutDirection _designDirection;
		// Ĭ������
		std::string _defaultFontPath;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}