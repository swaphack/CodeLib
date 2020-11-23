#pragma once

#include <string>
#include <cstdint>
#include <vector>

namespace sys
{
	// 目录
	class Directory
	{
	public:
		// 获取目录
		static void getDirectory(const std::string& fullpath, std::string& dir);
		// 获取所有文件
		static void getAllFiles(const std::string& dir, std::vector<std::string>& files);
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
		// 获取目录名字
		static std::string getDirName(const std::string& fullpath, bool containsFormat = true);
	public:
		Directory();
		virtual ~Directory();
	public:
		/**
		*	设置目录路径
		*/
		void setRoot(const std::string root);
		/**
		*	获取目录路径
		*/
		const std::string& getRoot() const;
	public:
		/**
		*	获取目录下文件
		*/
		const std::vector<std::string>& getFiles() const;
		/**
		*	获取目录子目录
		*/
		const std::vector<std::string>& getSubDirs() const;
		/**
		*	加载信息
		*/
		void load();
	private:
		// 根路径
		std::string _root;
		// 文件
		std::vector<std::string> _files;
		// 子目录
		std::vector<std::string> _sudDirs;
	};
}
