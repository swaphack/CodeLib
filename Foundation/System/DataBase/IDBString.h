#pragma once

#include "Base/Types.h"

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