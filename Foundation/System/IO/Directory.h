#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	// 目录
	class Directory
	{
	public:
		static void getDirectory(const std::string& fullpath, std::string& dir);

		// 创建文件
		static int32_t createFile(const std::string& filename);
		// 删除文件
		static int32_t deleteFile(const std::string& filename);
		// 重命名文件
		static int32_t renameFile(const std::string& oldFilename, const std::string& newFilename);

		// 创建文件夹
		static int32_t createDirectory(const std::string& dirname);
		// 删除文件夹
		static int32_t deleteDirectory(const std::string& dirname);
		// 重命名文件夹
		static int32_t renameDirectory(const std::string& oldDirname, const std::string& newDirname);

		// 获取当前目录
		static void getCurrentDirectory(std::string& dir);
		// 设置当前目录
		static int32_t setCurrentDirectory(const std::string& name);
	protected:
	private:
	};
}