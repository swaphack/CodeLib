#pragma once

#include "system.h"

#include <vector>
#include <map>
#include <string>

namespace web
{
	class DBProxy
	{
	public:
		DBProxy(sys::IDataBase* db);
		~DBProxy();
	public:
		/** 
		*	加载表数据
		*	@param readTableNames 要读取的表名称
		*	@param tableSheet 读出后缓存的地方
		*/
		bool load(const std::vector<std::string>& readTableNames, std::map<std::string, sys::DataSheet*>& tableSheet);
		/**
		*	插入数据
		*	@param tableName 表名称
		*	@param values 改变的字段名和值
		*/
		bool insert(const char* tableName, const std::map<std::string, std::string>& values);
		/**
		*	删除数据
		*	@param tableName 表名称
		*	@param conditions 条件{字段名，值}
		*/
		bool del(const char* tableName, const std::map<std::string, std::string>& conditions);
		/**
		*	更新表数据
		*	@param tableName 表名称
		*	@param conditions 条件{字段名，值}
		*	@param values 改变的字段名和值
		*/
		bool update(const char* tableName, const std::map<std::string, std::string>& conditions, const std::map<std::string, std::string>& values);
		/**
		*	更新表数据
		*	@param strSQL sql语句
		*	@param pDataSheet 存储回调数据
		*/
		bool exec(const char* strSQL, sys::IDataSheet* pDataSheet = nullptr);
	private:
		sys::IDataBase* _db;
	};
}