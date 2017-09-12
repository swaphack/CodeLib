#pragma once

#include <string>
#include <vector>

namespace sys
{
	class IDataSheet;

	// ���ݿ�������
	class IDBString
	{
	public:
		virtual ~IDBString() {}
	public:
		// ��ѯ��
		virtual bool excuteSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr) = 0;
	};
}