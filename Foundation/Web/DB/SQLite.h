#pragma once

#include "system.h"

struct sqlite3;

namespace web
{
	// SQLite ����
	class SQLite : public sys::IDataBase
	{
	public:
		SQLite();
		virtual ~SQLite();
	public:
		// �������ݿ�
		virtual bool connect(const sys::Author& info);
		// �Ͽ����ݿ�����
		virtual bool disconnect();
		// ִ��sql���
		virtual bool executeSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
		// ��ȡdb����
		virtual sys::IDBString* getDBString();
	private:
		sqlite3* _instance;
		sys::IDBString* _dbString;
	};
}