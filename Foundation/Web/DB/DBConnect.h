#pragma once

#include "system.h"

namespace web
{
	// ���ݿ�����
	enum class DBType
	{
		DB_SQLITT,
		DB_MYSQL,
		DB_SQLSERVER,
		DB_ORACLE,
	};
	// ���ݿ�����
	class DBConnect
	{
	private:
		DBConnect();
		~DBConnect();
	public:
		static DBConnect* getInstance();

		// ����sys::IDataBase����
		template<typename T>
		T* create(const sys::Author& info);
		// ����sys::IDataBase����
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