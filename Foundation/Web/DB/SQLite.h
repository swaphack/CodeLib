#pragma once

#include "system.h"

struct sqlite3;

namespace sys
{
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
	private:
		sqlite3* _instance;
	};
}