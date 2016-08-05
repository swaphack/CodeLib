#pragma once

#include "IDataSheet.h"

namespace web
{
	class IDataBase
	{
	public:
		virtual ~IDataBase() {}
	public:
		// ------------------ ���ݿ����Ӳ��� ------------------ 
		// �������ݿ�
		virtual bool connect(const char* url, int port = 0, const char* username = nullptr, const char* password = nullptr) = 0;
		// �Ͽ����ݿ�����
		virtual bool disconnect() = 0;
		// ִ��sql���
		virtual bool exec_sql(const char* sqlExpression, IDataSheet* pDataSheet = nullptr) = 0;
	};
}