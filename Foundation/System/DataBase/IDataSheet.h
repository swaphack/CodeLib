#pragma once

#include "IDataRecord.h"

#include <cstdint>
#include <string>

namespace sys
{
	class IDataSheet
	{
	public:
		virtual ~IDataSheet() {}
	public:
		// ���ùؼ���
		virtual void setKey(const std::string& key) = 0;
		// ���ҹؼ���
		virtual const std::string& getKey() = 0;
		// ����һ���������ļ�¼
		virtual IDataRecord* create() = 0;
		// ������¼
		virtual const IDataRecord* operator[](int32_t index) { return nullptr; }
		// �����������ü�¼
		virtual void setRecord(const std::string& key, const IDataRecord* record) = 0;
		// ������������
		virtual const IDataRecord* getRecord(const std::string& key) = 0;
		// ��¼����
		virtual int32_t count() = 0;
		// �������
		virtual void clear() = 0;
	};
}