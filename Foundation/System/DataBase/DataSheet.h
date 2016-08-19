#pragma once

#include "IDataSheet.h"
#include <vector>

namespace sys
{
	class DataSheet : public IDataSheet
	{
	public:
		DataSheet();
		virtual ~DataSheet();
	public:
		// ����һ����¼
		virtual IDataRecord* create();
		// ��¼����
		virtual int count();
		// ���ö�ȡ�α�
		virtual void reset();
		// ��ȡ��һ����¼
		virtual IDataRecord* next();
		// ������м�¼
		virtual void clear();
	private:
		// �α�
		int _cursor;
		// ��¼����
		std::vector<IDataRecord*> _records;
	};
}