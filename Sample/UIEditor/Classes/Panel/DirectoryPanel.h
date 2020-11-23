#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	目录信息
	*/
	struct DirDetail
	{
	public:
		// 名字
		std::string name;
		// 路径
		std::string fullpath;
		// 目录
		std::vector<DirDetail> subDirs;
		// 文件
		std::vector<std::string> files;
	public:
		// 设置根目录
		void setRoot(const std::string& root);
		// 清空
		void clear();
	};
	// 目录栏
	class DirectoryPanel : public Panel
	{
	public:
		DirectoryPanel();
		virtual ~DirectoryPanel();
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
		void setDirectory(const std::string& root);
	protected:
		/**
		*	更新目录栏
		*/
		void updateRootPanel();
		/**
		*	更新目录栏
		*/
		void updateRootList(ui::Layout* layout, const DirDetail& detail);
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
		ui::LayoutItem* createDirItem(int top, int height, const std::string& name, const std::string& fullpath);
		/**
		*	创建文件名字
		*/
		ui::LayoutItem* createFileItem(int top, int height, const std::string& name);
		/**
		*	创建项
		*/
		ui::LayoutItem* createRootItem(int top, int height, bool isDir, const std::string& name, const std::string& fullpath);
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 30;
		// 根目录
		std::string _root;
		// 目录信息
		DirDetail _dirDetail;
		// 距离顶点位置
		float _top = 0;
		// 对折信息
		std::map<std::string, bool> _dirFoldInfo;

		std::map<std::string, ui::LayoutItem*> _dirItems;
	};
}
