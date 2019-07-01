#pragma once

#include <map>
#include <functional>

namespace game
{
	typedef std::function<void(int type, float newValue, float lastValue)> RecordHandler;

	class DataRecord
	{
	public:
		DataRecord();
		~DataRecord();
	public:
		/**
		*	������������
		*/
		void setType(int nType);
		/**
		*	��������
		*/
		int getType() const;
		/**
		*	��������ֵ
		*/
		void setValue(float fValue);
		/**
		*	��ȡ����ֵ
		*/
		float getValue() const;
		/**
		*	�ı�����ֵ
		*/
		void addValue(float value);
		/**
		*	�������Ըı�ʱ��֪ͨ
		*/
		void setChangedHandler(RecordHandler handler);
		/**
		*	���Ըı�ʱ��֪ͨ
		*/
		RecordHandler getChangedHandler();
		/**
		*	��¡
		*/
		DataRecord* clone();
	protected:
		/**
		*	֪ͨ���Ըı�
		*/
		void onChangedHandler(float newValue);
	private:
		int m_nType = 0;
		float m_nValue = 0;
		RecordHandler m_pHandler = nullptr;
	};

	class DataTable
	{
	public:
		DataTable();
		~DataTable();
	public:
		/**
		*	��ȡ����
		*/
		DataRecord* getRecord(int nRecordType);
		/**
		*	�������
		*/
		void addRecord(DataRecord* pRecord);
		/**
		*	�Ƴ�����
		*/
		void removeRecord(int nRecordType);
		/**
		*	�Ƴ���������
		*/
		void removeAllRecords();
		/**
		*	����
		*/
		void foreach(const std::function<void(DataRecord*)>& handler);
		/**
		*	��¡
		*/
		DataTable* clone();
	private:
		std::map<int, DataRecord*> m_mRecords;
	};
}