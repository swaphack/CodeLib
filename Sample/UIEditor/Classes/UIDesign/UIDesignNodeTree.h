#pragma once
#pragma once

#include "Panel/Panel.h"

namespace ue
{

	// 节点树
	class UIDesignNodeTree : public Panel
	{
	public:
		UIDesignNodeTree();
		virtual ~UIDesignNodeTree();
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
	public:
		/**
		*	设置目录
		*/
		void setNode(Node* pNode);
	protected:
		/**
		*	更新目录栏
		*/
		void updateRootPanel(bool cleanFold = false);
		/**
		*	更新目录栏
		*/
		void updateRootList(ui::CtrlListView* layout, const Node* pNode, int layer = 0);
	private:
		/**
		*	改变对折信息
		*/
		void onChangeFoldState(const render::Node* node);
		/**
		*	目录是否对折
		*/
		bool isDirFolded(const render::Node* node);
	private:
		/**
		*	创建目录名字
		*/
		ui::CtrlButton* createHasChildrenNode(int height, const std::string& name, const render::Node* node);
		/**
		*	创建文件名字
		*/
		ui::CtrlButton* createNoChildrenNode(int height, const std::string& name, const render::Node* node);
		
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 20;

		// 对折信息
		std::map<render::Node*, bool> _dirFoldInfo;

		ui::CtrlListView* _listview = nullptr;

		render::Node* _rootNode = nullptr;
	};
}
