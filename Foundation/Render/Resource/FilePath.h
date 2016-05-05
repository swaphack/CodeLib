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
		// 获取文件路径
		const char* getFilePath(const char* filename);
		// 获取文件数据
		char* getFileData(const char* filename, long& count);
		// 设置搜索路径
		void setSearchPath(std::vector<std::string> paths);
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

	#define G_FILEPATH sys::Instance<FilePath>::getInstance()
}