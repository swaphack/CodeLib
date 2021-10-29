#pragma once

#include "render.h"
#include "Layout/macros.h"
#include "Layout/LayoutItem.h"
namespace ui
{
	class IElement;
	class CtrlWidget;

	// ui加载
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
		*	加载ui配置文件
		*/
		CtrlWidget* loadFile(const std::string& filepath, const math::Size& size);
		/**
		*	保存ui配置文件
		*/
		bool saveFile(CtrlWidget* CtrlWidget, const std::string& filepath, const math::Size& designSize);
	public:
		/**
		*	注册节点解析
		*/
		void registerElementParser(const std::string& name, const CreateElementFunc& func);
		/**
		*	注销节点解析
		*/
		void unregisterElementParser(const std::string& name);
		/**
		*	移除所有节点解析
		*/
		void removeAllElementParsers();
	public:
		/**
		*	注册节点解析
		*/
		void registerWidgetCreator(const std::string& creatorName, const CreateWidgetFunc& func);
		/**
		*	注销节点解析
		*/
		void unregisterWidgetCreator(const std::string& creatorName);
		/**
		*	移除所有节点解析
		*/
		void removeAllWidgetCreators();
		/**
		*	创建控件
		*/
		ui::CtrlWidget* createWidget(const std::string& widgetName);
	public:
		/**
		*	注册控件属性
		*/
		void registerWidgetPropertyCreator(const std::string& creatorName, const CreateWidgetFunc& func);
		/**
		*	注销控件属性
		*/
		void unregisterWidgetPropertyCreator(const std::string& creatorName);
		/**
		*	移除所有控件属性
		*/
		void removeAllWidgetPropertyCreators();
		/**
		*	创建控件属性
		*/
		ui::CtrlWidget* createWidgetProperty(const std::string& widgetName);
	public:
		/**
		*	设计大小
		*/
		const math::Size& getDesignSize() const;
		/**
		*	获取布局方向
		*/
		LayoutDirection getDesignDirection() const;
	public:
		/**
		*	默认字体
		*/
		const std::string& getFontPath() const;
		/**
		*	设置默认字体
		*/
		void setFontPath(const std::string& fontPath);
		/**
		*	默认字体图片路径
		*/
		const std::string& getFontImagePath() const;
		/**
		*	设置默认字体图片路径
		*/
		void setFontImagePath(const std::string& fontImagePath);
	public:
		/**
		*	获取布局
		*/ 
		static ui::LayoutItem* getLayoutItem(ui::CtrlWidget* item);

		/**
		*	获取控件名称
		*/  
		static std::string getLayoutItemName(ui::CtrlWidget* item);

		/**
		*	获取子节点
		*/ 
		static render::Node* getChildByIndex(render::Node* node, int index);
		/**
		*	获取可视子节点
		*/
		static bool getVisibleChildren(const render::Node* node, std::vector<render::Node*>& children);
	protected:
		/**
		*	初始化
		*/
		void init();
		/**
		*	获取节点
		*/
		IElement* getElement(const std::string& name);
	protected:
		//////////////////////////////////////////////////////////////////////////
		// 加载单一节点
		CtrlWidget* initWidget(tinyxml2::XMLElement* xmlNode, const math::Size& parentSize);
		// 加载布局
		bool loadWidget(CtrlWidget* pCtrlWidget, tinyxml2::XMLElement* xmlNode);
		// 加载根元素
		CtrlWidget* loadRoot(tinyxml2::XMLElement* xmlNode, const math::Size& size);
		// 加载界面信息
		void loadInfo(tinyxml2::XMLElement* xmlNode);
		// 加载纹理
		void loadTextures(tinyxml2::XMLElement* xmlNode);
		//////////////////////////////////////////////////////////////////////////
		// 保存布局
		bool saveWidget(CtrlWidget* item, tinyxml2::XMLElement* xmlNode);
		// 保存根元素
		bool saveRoot(CtrlWidget* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, CreateElementFunc> ElementParsers;
		typedef std::map<std::string, CreateWidgetFunc> WidgetCreators;
		typedef std::map<std::string, CreateWidgetFunc> WidgetPropertyCreators;

		// 节点解析集合
		ElementParsers _elementParsers;
		// 控件创建集合
		WidgetCreators _widgetCreators;
		// 控件属性创建集合
		WidgetPropertyCreators _widgetPropertyCreators;
		// 设计大小
		math::Size _designSize;
		// 布局方向
		LayoutDirection _designDirection;
		// 默认字体ttf路径
		std::string _defaultFontPath;
		// 默认字体图片路径
		std::string _defaultFontImagePath;
	}; 

	#define G_UIPROXY ui::UIProxy::getInstance()
}