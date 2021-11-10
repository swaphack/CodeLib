#pragma once

#include <string>
#include <vector>
#include "system.h"

namespace ue
{


	/**
	*	��Ŀ¼��Ϣ
	*/
	struct SimpleDirInfo
	{
	public:
		// ����
		std::string name;
		// ·��
		std::string fullpath;
		// ���� 0-Ŀ¼��1-�ļ�
		int type = 0;
	};

	/**
	*	Ŀ¼��Ϣ
	*/
	struct DirDetail
	{
	public:
		// ����
		std::string name;
		// ·��
		std::string fullpath;
		// Ŀ¼
		std::vector<DirDetail> subDirs;
		// �ļ�
		std::vector<std::string> files;
	public:
		// ���ø�Ŀ¼
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
		// ���
		void clear()
		{
			subDirs.clear();
			files.clear();
		}
	};
	/**
	*	Ŀ¼�б�
	*/
	struct DirList
	{
		// ���ø�Ŀ¼
		static void getAllFiles(const std::string& root, std::vector<SimpleDirInfo>& vecDirInfo)
		{
			SimpleDirInfo info;
			info.fullpath = root;
			info.name = sys::Directory::getDirName(root);
			info.type = 0;
			vecDirInfo.push_back(info);

			// Ŀ¼
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