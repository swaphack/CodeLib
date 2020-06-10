#pragma once

#include <vector>
#include <map>
#include <string>

namespace sys
{
	class FilePath
	{
	public:
		FilePath();
		virtual ~FilePath();
	public:
		// ��ȡ�ļ�·��
		std::string getFilePath(const std::string& filename, bool bIngoreEmpty = true);
		// ��ȡ�ļ�����
		bool getFileData(const std::string& filename, std::string& data);
		// ��������·��
		void setSearchPath(const std::vector<std::string>& paths);
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
}