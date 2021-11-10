#pragma once

#include <string>
#include <vector>
#include "system.h"

namespace ue
{


	/**
	*	简单目录信息
	*/
	struct SimpleDirInfo
	{
	public:
		// 名字
		std::string name;
		// 路径
		std::string fullpath;
		// 类型 0-目录，1-文件
		int type = 0;
	};

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
		// 设置根目录
		static void getAllFiles(const std::string& root, std::vector<SimpleDirInfo>& vecDirInfo)
		{
			SimpleDirInfo info;
			info.fullpath = root;
			info.name = sys::Directory::getDirName(root);
			info.type = 0;
			vecDirInfo.push_back(info);

			// 目录
			std::vector<DirDetail> subDirs;
			std::vector<std::string> files;

			sys::Directory dir;
			dir.setRoot(root);

			if (!dir.getSubDirs().empty())
			{
				for (const auto& item : dir.getSubDirs())
				{
					getAllFiles(root + "/" + item, vecDirInfo);
				}
			}

			for (const auto& item : dir.getFiles())
			{
				info.fullpath = root + "/" + item;
				info.name = item;
				info.type = 1;
				vecDirInfo.push_back(info);
			}
		}
	};
}