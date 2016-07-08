#pragma once
#include <string>

namespace sys
{
	class Directory
	{
	public:
		static void getDirectory(const char* fullpath, std::string& dir);

		// 创建文件
		static int createFile(const char* filename);
		// 删除文件
		static int deleteFile(const char* filename);
		// 重命名文件
		static int renameFile(const char* oldFilename, const char* newFilename);

		// 创建文件夹
		static int createDirectory(const char* dirname);
		// 删除文件夹
		static int deleteDirectory(const char* dirname);
		// 重命名文件夹
		static int renameDirectory(const char* oldDirname, const char* newDirname);

		// 获取当前目录
		static void getCurrentDirectory(std::string& dir);
		// 设置当前目录
		static int setCurrentDirectory(const char* name);
	protected:
	private:
	};
}