#pragma once

#include "system.h"
#include "web.h"

#include <vector>
#include <string>

namespace hs
{
	// 数据库管理者
	class DBManager
	{
	private:
		DBManager();
		~DBManager();
	public:
		static DBManager* getInstance();
		/** 
		*	初始化
		*	@param url 数据库文件地址
		*	@param readTableNames 要读取的表
		*/
		bool init(const char* url, std::vector<std::string> readTableNames);
		/**
		*	更新表数据
		*	@param tableName 表名称
		*	@param keys 查找条件的字段名和值
		*	@param values 改变的字段名和值
		*/
		bool update(const char* tableName, const std::map<std::string, std::string>& keys, const std::map<std::string, std::string>& values);
		/**
		*	插入数据
		*	@param tableName 表名称
		*	@param values 改变的字段名和值
		*/
		bool insert(const char* tableName, const std::map<std::string, std::string>& values);
	protected:
		// 添加一个表数据
		void addDataSheet(const char* tableName, sys::DataSheet* pDataSheet);
		// 移除一个表数据
		void removeDataSheet(const char* tableName);
		// 获取一个表数据
		sys::DataSheet* getDataSheet(const char* tableName);
		// 移除所有表数据
		void clearDataSheets();
		// 更新缓存
		bool updateMemory(const char* tableName, const std::map<std::string, std::string>& keys, const std::map<std::string, std::string>& values);
		// 添加到缓存
		bool insertMemory(const char* tableName, const std::map<std::string, std::string>& values);
	protected:
		// 更新数据库
		bool updateDataBase(const char* tableName, const std::map<std::string, std::string>& keys, const std::map<std::string, std::string>& values);
		// 添加到数据库
		bool insertDataBase(const char* tableName, const std::map<std::string, std::string>& values);
	private:
		// 数据库sqlite
		sys::IDataBase* _db;
		// 数据表
		std::map<std::string, sys::DataSheet*> _tableSheet;
	};
}