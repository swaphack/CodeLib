#pragma once

#include "DBTable.h"

#include <string>
#include <map>

namespace db
{
	// ���ݿ�Ŀ¼
	class DBContent
	{
	public:
		DBContent();
		~DBContent();
	public:
		// ��ӱ�ṹ
		void addTable(const DBTable& dbTable);
		// �Ƴ���ṹ
		void removeTable(const char* tableName);
		// ��ȡ��ṹ
		const DBTable* getTable(const char* tableName);
		// �Ƴ����б�ṹ
		void removeAllTables();
		// ��ȡ���б�
		const std::map<std::string, DBTable>& getTables() const;
	private:
		// ����
		std::map<std::string, DBTable> _dbTables;
	};
}