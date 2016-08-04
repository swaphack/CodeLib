#pragma once
#include "system.h"

#include <vector>
#include <map>

namespace render
{
	class FilePath
	{
	public:
		FilePath();
		virtual ~FilePath();
	public:
		// ��ȡ�ļ�·��
		const char* getFilePath(const char* filename);
		// ��ȡ�ļ�����
		bool getFileData(const char* filename, std::string& data);
		// ��������·��
		void setSearchPath(std::vector<std::string> paths);
		// ��ȡ����·��
		const std::vector<std::string>& getSearchPath();
		// ��������ѻ����·��
		void clearAllFilepaths();
	private:
		// ����·��
		std::vector<std::string> _searchPaths;
		// ����·�� �ļ�����->·��
		std::map<std::string, std::string> _filePathCache;
	};

	#define G_FILEPATH sys::Instance<FilePath>::getInstance()
}