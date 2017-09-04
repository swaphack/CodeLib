#pragma once

#include "IDataRecord.h"

#include <map>
#include <string>

namespace sys
{
	class IDataSheet
	{
	public:
		virtual ~IDataSheet() {}
	public:
		// ����һ����¼
		virtual IDataRecord* create() = 0;
		// ��¼����
		virtual int count() = 0;
		// �����α�
		virtual void reset() = 0;
		// �������
		virtual void clear() = 0;
		// ��ȡ��һ����¼
		virtual IDataRecord* next() = 0;
	};
}