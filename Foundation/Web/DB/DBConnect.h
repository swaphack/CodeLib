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

		// ����sqlite����
		SQLite* createSQLite(const char* url);
	};
}