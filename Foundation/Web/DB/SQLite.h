#pragma once

#include "IDataBase.h"

struct sqlite3;

namespace web
{
	// mysql ����
	class SQLite : public IDataBase
	{
	public:
		SQLite();
		virtual ~SQLite();
	public:
		// �������ݿ�
		virtual bool connect(const char* url, int port = 0, const char* username = nullptr, const char* password = nullptr);
		// �Ͽ����ݿ�����
		virtual bool disconnect();
		// ִ��sql���
		virtual bool exec_sql(const char* sqlExpression, IDataSheet* pDataSheet = nullptr);
	private:
		sqlite3* _instance;
	};
}