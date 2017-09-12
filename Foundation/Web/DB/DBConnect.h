#pragma once

#include "system.h"

namespace web
{
	// 数据库类型
	enum class DBType
	{
		DB_SQLITT,
		DB_MYSQL,
		DB_SQLSERVER,
		DB_ORACLE,
	};
	// 数据库连接
	class DBConnect
	{
	private:
		DBConnect();
		~DBConnect();
	public:
		static DBConnect* getInstance();

		// 创建sys::IDataBase连接
		template<typename T>
		T* create(const sys::Author& info);
		// 创建sys::IDataBase连接
		sys::IDataBase* create(const sys::Author& info, DBType type);
	};	

	template<typename T>
	T* DBConnect::create(const sys::Author& info)
	{
		T* db = new T();
		if (db == nullptr)
		{
			return nullptr;
		}

		if (!db->connect(info))
		{
			delete db;
			return nullptr;
		}

		return db;
	}
}