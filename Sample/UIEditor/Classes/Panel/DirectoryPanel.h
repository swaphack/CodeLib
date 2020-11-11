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
		// 更新目录栏
		void updateDirectoryPanel();
	private:
		// 根目录
		std::string _root;
		// 目录信息
		DirDetail _dirDetail;
	};
}
