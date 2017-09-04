#pragma once

#include "system.h"

namespace web
{
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
	};	

	template<typename T>
	T* DBConnect::create(const sys::Author& info)
	{
		if (info.url.empty())
		{
			return nullptr;
		}
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