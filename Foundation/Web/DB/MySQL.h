#pragma once

#include "system.h"

struct st_mysql;

namespace web
{
	// MySQL ����
	class MySQL : public sys::IDataBase
	{
	public:
		MySQL();
		virtual ~MySQL();
	public:
		// �������ݿ�
		virtual bool connect(const sys::Author& info);
		// �Ͽ����ݿ�����
		virtual bool disconnect();
		// ִ��sql���
		virtual bool executeSQL(const std::string& sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
		// ��ȡdb����
		virtual sys::IDBString* getDBString();
	private:
		st_mysql* _instance;
		sys::IDBString* _dbString;
	};
}