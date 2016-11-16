#pragma once

#include "system.h"
#include "IDBString.h"

struct sqlite3;

namespace web
{
	// sqlite ���
	class SQLiteString : public IDBString
	{
	public:
		SQLiteString(sys::IDataBase* db);
		virtual ~SQLiteString();
	public:
		virtual bool excuteSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
	private:
		sys::IDataBase* _db;
	};

	// SQLite ����
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
		virtual bool executeSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
		// ��ȡdb����
		const IDBString* getDBString();
	private:
		sqlite3* _instance;
		IDBString* _dbString;
	};
}