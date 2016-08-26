#pragma once

#include "system.h"
#include "IDBString.h"

struct sqlite3;

namespace web
{
	class SQLiteString : public IDBString
	{
	public:
		SQLiteString(IDataBase* db);
		virtual ~SQLiteString();
	public:
		virtual bool createDataBase(const char* name);

		virtual bool deleteDataBase(const char* name);

		virtual bool createTable(const char* name, const std::vector<TableMember>& members);

		virtual bool deleteTable(const char* name);

		virtual bool selectTable(const char* name, sys::IDataSheet* pDataSheet = nullptr);
	private:
		IDataBase* _db;
	};

	// mysql ����
	class SQLite : public sys::IDataBase
	{
	public:
		SQLite();
		virtual ~SQLite();
	public:
		// �������ݿ�
		virtual bool connect(const char* url, const char* username = nullptr, const char* password = nullptr);
		// �Ͽ����ݿ�����
		virtual bool disconnect();
		// ִ��sql���
		virtual bool exec_sql(const char* sqlExpression, IDataSheet* pDataSheet = nullptr);

		const IDBString* getDBString();
	private:
		sqlite3* _instance;
		IDBString* _dbString;
	};
}