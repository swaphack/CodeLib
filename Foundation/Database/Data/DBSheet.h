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
		DBSheet(DBTable* table);
		virtual ~DBSheet();
	public:
		// ���¼��ر�ṹ���ṹͬ��
		// ��ṹ�����޸ģ�������ҲҪ�޸�
		void reloadStruct(DBTable* table);
		// ��ȡ��ṹ
		const DBTable* getTable() const;

		void addRecord(DBRecord* record);
		// ��Ӽ�¼
		void addRecord(int key, DBRecord* record);
		// �Ƴ���¼
		void removeRecord(int key);
		// ��ȡ��¼
		DBRecord* getRecord(int key);

		// ��¼������
		std::map<int, DBRecord*>::const_iterator beginRecord() const;
		std::map<int, DBRecord*>::const_iterator endRecord() const;

		// �����¼
		void clear();
	protected:
		// ��ṹ(ָ������)
		DBTable* _table;
		// ������
		std::map<int, DBRecord*> _records;
	};
}