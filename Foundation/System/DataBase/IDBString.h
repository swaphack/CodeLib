#pragma once

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
		virtual bool excuteSQL(const std::string& sqlExpression, sys::IDataSheet* pDataSheet = nullptr) = 0;
	};
}