#pragma once

#include "Panel/Panel.h"
#include "common.h"

namespace ue
{
	// 目录栏
	class UIDesignDir : public Panel, public ui::TableDataProtocol
	{
	public:
		UIDesignDir();
		virtual ~UIDesignDir();
	public:
		virtual bool init();
	public:
		/**
		*	总数量
		*/
		virtual int getDataCount();
		/**
		*  大小
		*/
		virtual math::Size getDataSize(int index, int& tag);
		/**
		*  控件
		*/
		virtual ui::CtrlWidget* getDataCell(int index, int tag);
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
		void setDirectory(const std::string& root);
	protected:
		/**
		*	更新目录栏
		*/
		void updateRootPanel(bool cleanFold = false);
		/**
		*	更新目录栏
		*/
		void updateRootList(ui::CtrlListView* layout, const DirDetail& detail, int layer = 0);
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
		ui::CtrlButton* createDirItem(int height, const std::string& name, const std::string& fullpath);
		/**
		*	创建文件名字
		*/
		ui::CtrlButton* createFileItem(int height, const std::string& name, const std::string& fullpath);
		/**
		*	获取总的目录（包含文件）数
		*/
		int getTotalDirCount(const DirDetail& detail);
		/**
		*	获取目录（包含文件）信息
		*/
		DirDetail getDirDetail(const DirDetail& detail, int index, int tempCount, bool& bFile);
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 20;
		// 根目录
		std::string _root;
		// 对折信息
		std::map<std::string, bool> _dirFoldInfo;
		// 目录信息
		std::vector<SimpleDirInfo> _simpleDirInfo;
		// 表格
		ui::CtrlTableView* _tableView = nullptr;
	};
}
