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
		// 获取文件路径
		std::string getFilePath(const std::string& filename, bool bIngoreEmpty = true);
		// 获取文件数据
		bool getFileData(const std::string& filename, std::string& data);
		// 设置搜索路径
		void setSearchPath(const std::vector<std::string>& paths);
		// 获取搜索路径
		const std::vector<std::string>& getSearchPath();
		// 清空所有已缓存的路径
		void clearAllFilepaths();
	private:
		// 搜索路径
		std::vector<std::string> _searchPaths;
		// 缓存路径 文件名称->路径
		std::map<std::string, std::string> _filePathCache;
	};
}