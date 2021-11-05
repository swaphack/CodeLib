#pragma once

#include <string>
#include <vector>
#include "system.h"

namespace ue
{
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

	};
}