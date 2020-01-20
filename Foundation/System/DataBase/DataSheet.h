#pragma once

#include "IDataSheet.h"
#include <vector>
#include <cstdint>
#include <map>
#include <string>

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
		virtual const std::string& getKey();
		// ����һ���������ļ�¼
		virtual IDataRecord* create();
		// ������¼
		virtual const IDataRecord* operator[](int32_t index);
		// �����������ü�¼
		virtual void setRecord(const std::string& key, const IDataRecord* record);
		// ������������
		virtual const IDataRecord* getRecord(const std::string& key);
		// ��¼����
		virtual int32_t count();
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