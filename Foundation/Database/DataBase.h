#pragma once

#include "Data/import.h"
#include "Query/import.h"
#include "Struct/import.h"
#include "Tool/import.h"

#include <string>

namespace db
{
	struct DBConfig
	{
	public:
		// 数据结构文件路径
		std::string dbStructFilepath;
		// 表格式文件路径
		std::string dbTableFilepath;
		// 表数据配置文件路径
		std::string dbDataFilepath;
		
		DBConfig();

		// 重置路径参数
		void reset();

		// 加载路径参数
		void load(const char* configFilepath);
		// 保存路径参数
		void save(const char* configFilepath);
	};

	class DataBase
	{
	public:
		DataBase();
		virtual ~DataBase();
	public:
		// 获取配置文件
		DBConfig* getConfig();
		// 获取数据库索引目录
		DBContent* getContent();
		// 获取数据仓库
		DBWarehouse* getWarehouse();

		// 加载数据库
		void loadDB(const char* configFilepath);
		// 加载数据库
		void loadDB(const DBConfig& dbConfig);
		// 保存配置
		void saveDB(const char* configFilepath);
	protected:
		// 加载数据库索引目录
		void loadContent(const char* filepath);
		// 加载数据
		void loadData(const char* filepath);
		// 保存数据库索引目录
		void saveContent(const char* filepath);
		// 保存数据
		void saveData(const char* filepath);
	private:
		// 配置文件
		DBConfig _config;
		// 数据库索引目录
		DBContent _content;
		// 数据仓库
		DBWarehouse _warehouse;
	};
}