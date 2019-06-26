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
		// ���ùؼ���
		virtual void setKey(const std::string& key);
		// ���ҹؼ���
		virtual const char* getKey();
		// ����һ���������ļ�¼
		virtual IDataRecord* create();
		// ������¼
		virtual const IDataRecord* operator[](int32 index);
		// �����������ü�¼
		virtual void setRecord(const std::string& key, const IDataRecord* record);
		// ������������
		virtual const IDataRecord* getRecord(const std::string& key);
		// ��¼����
		virtual int32 count();
		// ������м�¼
		virtual void clear();
	private:
		// ����
		std::string _key;
		// ˳���¼����
		std::vector<IDataRecord*> _records;
		// ������¼����
		std::map<std::string, IDataRecord*> _keyRecords;
	};
}