#pragma once

#include <string>
#include <vector>


namespace sys
{
	class IDataSheet;
}

namespace web
{
	class TableMember;

	// ���ݿ�������
	class IDBString
	{
	public:
		virtual ~IDBString() {}
	public:
		// ��ѯ��
		virtual bool excuteSQL(const char* name, sys::IDataSheet* pDataSheet = nullptr) = 0;
	};
}