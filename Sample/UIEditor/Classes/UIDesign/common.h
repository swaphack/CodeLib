#pragma once

#include <string>
#include <vector>
#include "system.h"

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
		void setRoot(const std::string& root)
		{
			this->clear();

			fullpath = root;

			name = sys::Directory::getDirName(root);

			sys::Directory dir;
			dir.setRoot(root);

			files = dir.getFiles();

			if (!dir.getSubDirs().empty())
			{
				for (const auto& item : dir.getSubDirs())
				{
					DirDetail subDir;
					subDir.setRoot(root + "/" + item);
					subDirs.push_back(subDir);
				}
			}
		}
		// 清空
		void clear()
		{
			subDirs.clear();
			files.clear();
		}
	};

	/**
	*	目录列表
	*/
	struct DirList
	{

	};
}