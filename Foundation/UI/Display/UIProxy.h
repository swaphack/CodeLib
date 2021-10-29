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
		typedef std::function<ui::CtrlWidget* (const std::string& name)> CreateWidgetFunc;

		typedef std::function<IElement* ()> CreateElementFunc;
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
	public:
		/**
		*	ע��ڵ����
		*/
		void registerElementParser(const std::string& name, const CreateElementFunc& func);
		/**
		*	ע���ڵ����
		*/
		void unregisterElementParser(const std::string& name);
		/**
		*	�Ƴ����нڵ����
		*/
		void removeAllElementParsers();
	public:
		/**
		*	ע��ڵ����
		*/
		void registerWidgetCreator(const std::string& creatorName, const CreateWidgetFunc& func);
		/**
		*	ע���ڵ����
		*/
		void unregisterWidgetCreator(const std::string& creatorName);
		/**
		*	�Ƴ����нڵ����
		*/
		void removeAllWidgetCreators();
		/**
		*	�����ؼ�
		*/
		ui::CtrlWidget* createWidget(const std::string& widgetName);
	public:
		/**
		*	ע��ؼ�����
		*/
		void registerWidgetPropertyCreator(const std::string& creatorName, const CreateWidgetFunc& func);
		/**
		*	ע���ؼ�����
		*/
		void unregisterWidgetPropertyCreator(const std::string& creatorName);
		/**
		*	�Ƴ����пؼ�����
		*/
		void removeAllWidgetPropertyCreators();
		/**
		*	�����ؼ�����
		*/
		ui::CtrlWidget* createWidgetProperty(const std::string& widgetName);
	public:
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
		const std::string& getFontPath() const;
		/**
		*	����Ĭ������
		*/
		void setFontPath(const std::string& fontPath);
		/**
		*	Ĭ������ͼƬ·��
		*/
		const std::string& getFontImagePath() const;
		/**
		*	����Ĭ������ͼƬ·��
		*/
		void setFontImagePath(const std::string& fontImagePath);
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
		CtrlWidget* initWidget(tinyxml2::XMLElement* xmlNode, const math::Size& parentSize);
		// ���ز���
		bool loadWidget(CtrlWidget* pCtrlWidget, tinyxml2::XMLElement* xmlNode);
		// ���ظ�Ԫ��
		CtrlWidget* loadRoot(tinyxml2::XMLElement* xmlNode, const math::Size& size);
		// ���ؽ�����Ϣ
		void loadInfo(tinyxml2::XMLElement* xmlNode);
		// ��������
		void loadTextures(tinyxml2::XMLElement* xmlNode);
		//////////////////////////////////////////////////////////////////////////
		// ���沼��
		bool saveWidget(CtrlWidget* item, tinyxml2::XMLElement* xmlNode);
		// �����Ԫ��
		bool saveRoot(CtrlWidget* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, CreateElementFunc> ElementParsers;
		typedef std::map<std::string, CreateWidgetFunc> WidgetCreators;
		typedef std::map<std::string, CreateWidgetFunc> WidgetPropertyCreators;

		// �ڵ��������
		ElementParsers _elementParsers;
		// �ؼ���������
		WidgetCreators _widgetCreators;
		// �ؼ����Դ�������
		WidgetPropertyCreators _widgetPropertyCreators;
		// ��ƴ�С
		math::Size _designSize;
		// ���ַ���
		LayoutDirection _designDirection;
		// Ĭ������ttf·��
		std::string _defaultFontPath;
		// Ĭ������ͼƬ·��
		std::string _defaultFontImagePath;
	}; 

	#define G_UIPROXY ui::UIProxy::getInstance()
}