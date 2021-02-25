#pragma once

#include "system.h"
#include "ui.h"

namespace ue
{
	// 选择布局文件
#define PANEL_SELECT_DESIGN_FILE "PANEL_SELECT_DESIGN_FILE"
	// 选中根节点
#define PANEL_SELECT_ROOT "PANEL_SELECT_ROOT"
	// 选中布局项
#define PANEL_SELECT_WIDGET "PANEL_SELECT_WIDGET"
	// 选中树节点
#define PANEL_SELECT_NODE_TREE "PANEL_SELECT_NODE_TREE"
	// 保存文件
#define PANEL_SAVE_FILE "PANEL_SAVE_FILE"

	/**
	*	事件中心
	*/
	class PanelEvent : public sys::EventCenter
	{
	public:
		PanelEvent();
		virtual ~PanelEvent();
	public:
		/**
		*	派发事件
		*/
		void dispatchEvent(const std::string& name, void* userData);
	public:// 事件派发
		/**
		*	派发设计文件
		*/
		void setDesignFile(const std::string& filepath);
		/**
		*	派发选中节点
		*/
		void setSelectNode(render::Node* node);
		/**
		*	派发选中节点数
		*/
		void setSelectNodeTree(const std::vector<int>& vecIndex);
		/**
		*	派发根节点
		*/
		void setRoot(render::Node* node);
		/**
		*	保存文件
		*/
		void saveFile();
	};

#define G_PANELEVT sys::Instance<PanelEvent>::getInstance()
}
