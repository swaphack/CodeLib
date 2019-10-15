#pragma once

#include "../Core/import.h"
#include <map>

namespace business
{
	class FinanceRecord;
	// ����
	class Finance
	{
	public:
		Finance();
		virtual ~Finance();
	public:
		// ��Ӽ�¼
		void addRecord(const FinanceRecord* pRecord);
		// �Ƴ���¼
		void removeRecord(uint64_t nRecordID);
		// ���
		void clear();
		// ���Ҽ�¼
		const FinanceRecord* getRecord(uint64_t nRecordID);
		// ��ȡ���м�¼
		const std::map<uint64_t, FinanceRecord*>& getRecords();
	private:
		// ��¼��Ϣ
		std::map<uint64_t, FinanceRecord*> m_mapRecords;
	};
}