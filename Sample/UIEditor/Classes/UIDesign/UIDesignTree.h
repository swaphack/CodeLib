#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// 节点树
	class UIDesignTree : public Panel
	{
	public:
		UIDesignTree();
		virtual ~UIDesignTree();
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
		void setNode(const Node* pNode);
	protected:
		/**
		*	更新目录栏
		*/
		void updateRootPanel();
		/**
		*	更新目录栏
		*/
		void updateRootList(ui::CtrlListView* layout, const Node* pNode, int layer = 0);
	private:
		/**
		*	改变对折信息
		*/
		void onChangeFoldState(const std::string& name);
		/**
		*	目录是否对折
		*/
		bool isDirFolded(const std::string& name);
	private:
		/**
		*	创建目录名字
		*/
		ui::CtrlButton* createHasChildrenNode(int height, const std::string& name, const std::string& fullpath);
		/**
		*	创建文件名字
		*/
		ui::CtrlButton* createNoChildrenNode(int height, const std::string& name, const std::string& fullpath);
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 35;
		// 根目录
		std::string _root;
		// 对折信息
		std::map<std::string, bool> _dirFoldInfo;

		ui::CtrlListView* _listview = nullptr;
	};
}
