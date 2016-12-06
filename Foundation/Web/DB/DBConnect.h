#pragma once

namespace web
{
	class SQLite;

	class DBConnect
	{
	private:
		DBConnect();
		~DBConnect();
	public:
		static DBConnect* getInstance();

		// 创建sqlite连接
		SQLite* createSQLite(const char* url);
	};
}