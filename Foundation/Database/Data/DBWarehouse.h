#pragma once

#include "system.h"
#include "DBSheet.h"

#include <map>
#include <string>

namespace db
{
	// ���ݲֿ�
	class DBWarehouse
	{
	public:
		DBWarehouse();
		virtual ~DBWarehouse();
	public:
		// ��ӱ�
		void addSheet(const char* name, DBSheet* sheet);
		// �Ƴ���
		void removeSheet(const char* name);
		// ��ȡ��
		DBSheet* getSheet(const char* name);
		// ��ձ�
		void removeAllSheets();
		// ���������
		void truncate();
	protected:
		// ��
		std::map<std::string, DBSheet*> _sheets;
	};
}