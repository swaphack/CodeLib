#pragma once

#include "../Struct/DBTable.h"
#include "DBRecord.h"
#include "system.h"

#include <string>
#include <map>

namespace db
{
	// ���ݱ�
	class DBSheet
	{
	public:
		DBSheet();
		virtual ~DBSheet();
	public:
		// ��Ӽ�¼
		void addRecord(DBRecord* record);
		// �Ƴ���¼
		void removeRecord(DBRecord* record);
		// �Ƴ���¼
		void removeRecord(int index);
		// ��ȡ��¼
		DBRecord* getRecord(int index);
		// �Ƿ��иļ�¼
		bool findRecord(DBRecord* record);
		// ��¼��
		int count();
		// �����¼
		void clear();
	protected:
		// ������
		std::vector<DBRecord*> _records;
	};
}