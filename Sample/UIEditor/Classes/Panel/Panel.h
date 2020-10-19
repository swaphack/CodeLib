#pragma once

#include "ui.h"

namespace ue
{

#define PANEL_SELECT_TARGET "selectTarget"
#define PANEL_SELECT_FILE "selectFile"
#define PANEL_SELECT_XML "selectXML"

	// 面板
	class Panel : public ui::CtrlFile
	{
	public:
		Panel();
		virtual ~Panel();
	public:
		virtual bool init();
	protected:
		/**
		*	初始化
		*/
		virtual void initUI();
		/**
		*	事件绑定
		*/
		virtual void initEvent();
		/**
		*	初始化文本
		*/
		virtual void initText();
	protected: // 点击
		/**
		*	点击屏幕
		*/ 
		virtual bool onTouchBegan(float x, float y, bool include);
		/**
		*	在屏幕上滑动
		*/  
		virtual bool onTouchMoved(float x, float y, bool include);
		/**
		*	离开屏幕
		*/   
		virtual bool onTouchEnded(float x, float y, bool include);
	protected: // 事件派发
		/**
		*	派发布局项
		*/
		void dispatchItem(ui::LayoutItem* item);
		/**
		*	派发布局项
		*/
		void dispatchFile(ui::CtrlFile* layout);
		/**
		*	派发配置文件
		*/
		void dispatchXml(tinyxml2::XMLElement* doc);
	protected:
		/**
		*	创建文件
		*/
		static ui::LayoutItem* createUIFile(const std::string& filepath);
		/**
		*	创建文件
		*/
		template<typename T>
		static T* createPanel(const std::string& filepath)
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(filepath);
			pFile->autoResize();

			return pFile;
		}
	};
}
