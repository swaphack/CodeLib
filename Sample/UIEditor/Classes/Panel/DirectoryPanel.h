#pragma once

#include "Panel.h"

namespace ue
{
	// 目录栏
	class DirectoryPanel : public Panel
	{
	private:
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
	public:
		DirectoryPanel();
		virtual ~DirectoryPanel();
	public:
		virtual bool init();
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
