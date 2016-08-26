#pragma once

#include <string>
#include <vector>

namespace sys
{
	class IDataSheet;
}

namespace web
{
	// ���ݿ�������
	class IDBString
	{
	public:
		virtual ~IDBString() {}
	public:
		// �������ݿ�
		virtual bool createDataBase(const char* name) = 0;
		// ɾ�����ݿ�
		virtual bool deleteDataBase(const char* name) = 0;
		// �����±�
		virtual bool createTable(const char* name, const std::vector<TableMember>& members) = 0;
		// ɾ����
		virtual bool deleteTable(const char* name) = 0;
		// ��ѯ��
		virtual bool selectTable(const char* name, sys::IDataSheet* pDataSheet = nullptr) = 0;
	};
}