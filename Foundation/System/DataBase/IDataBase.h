#pragma once

#include "IDataSheet.h"
#include "IDBString.h"
#include "Security/Author.h"

namespace sys
{
	class IDataBase
	{
	public:
		virtual ~IDataBase() {}
	public:
		// ------------------ ���ݿ����Ӳ��� ------------------ 
		// �������ݿ�
		virtual bool connect(const Author& info) = 0;
		// �Ͽ����ݿ�����
		virtual bool disconnect() = 0;
		// ִ��sql���
		virtual bool executeSQL(const std::string& sqlExpression, IDataSheet* pDataSheet = nullptr) = 0;
		// ��ȡdb�������
		virtual IDBString* getDBString() = 0;
	};
}