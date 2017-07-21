#pragma once

#include "system.h"
#include "DBTable.h"
#include "DBContent.h"
#include <vector>

namespace db
{
	// 数据结构
	// 创建结构的代码
	class DBStructTemplate
	{
	private:
		/*
		* 创建包含结构的头文件
		*
		* @param filename 头文件名称
		* @param structFileNames 包含的结构文件名称
		*/
		static void createStructCPPFile(const char* filename, const std::map<std::string, DBTable>& structFiles);

		/*
		* 表结构的数据读取
		* 存储文件：{ 表结构数据 }+
		*/
		static void readTableStruct(const char* filename, std::map<std::string, DBTable>& dbTables);

		/*
		* 表结构的数据存储
		* 存储文件：{ 表结构数据 }+
		*/
		static void writeTableStruct(const char* filename, const std::map<std::string, DBTable>& dbTables);
	public:
		/*
		* 创建数据结构
		* 
		*/
		static void createStructCode(std::string headFilename, const DBContent* content);
		/*
		* 保存结构
		* 
		*/
		static void saveContent(std::string filename, const DBContent* content);
		/*
		* 加载结构
		* 
		*/
		static void loadContent(std::string filename, DBContent* content);
	};
}