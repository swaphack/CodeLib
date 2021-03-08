#pragma once

#include "system.h"
#include "ui.h"

namespace ue
{
	// 选择文件
#define PANEL_SELECT_FILE "PANEL_SELECT_FILE"
	// 选中根节点
#define PANEL_SELECT_ROOT "PANEL_SELECT_ROOT"
	// 选中视图控件项
#define PANEL_SELECT_VIEW_WIDGET "PANEL_SELECT_VIEW_WIDGET"
	// 选中树节点
#define PANEL_SELECT_NODE_TREE "PANEL_SELECT_NODE_TREE"
	// 保存文件
#define PANEL_SAVE_FILE "PANEL_SAVE_FILE"
	// 选中控件项
#define PANEL_SELECT_CONTROL_WIDGET "PANEL_SELECT_CONTROL_WIDGET"

	class UIDesignView;
	class UIDesignNodeTree;

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
		*	派发选中文件
		*/
		void setSelectFile(const std::string& filepath);
		/**
		*	派发选中节点
		*/
		void setSelectNode(render::Node* node);
		/**
		*	派发选中节点树节点
		*/
		void setSelectTreeNode(const std::vector<int>& vecIndex);
		/**
		*	派发根节点
		*/
		void setRoot(render::Node* node);
		/**
		*	派发选中控件数
		*/
		void setSelectControlWidget(render::Node* node);
		/**
		*	保存文件
		*/
		void saveFile();
	public:
		/**
		*	文件界面视图
		*/
		void setViewPanel(UIDesignView* panel);
		/**
		*	文件界面视图
		*/
		UIDesignView* getViewPanel() const;
		/**
		*	节点树
		*/
		void setNodeTreePanel(UIDesignNodeTree* panel);
		/**
		*	节点树
		*/
		UIDesignNodeTree* getNodeTreePanel() const;
	private:
		/**
		*	文件界面视图
		*/
		UIDesignView* m_pDesignView = nullptr;
		/**
		*	节点树
		*/
		UIDesignNodeTree* m_pDesignNodeTree = nullptr;
	};

#define G_PANELEVT sys::Instance<PanelEvent>::getInstance()
}
