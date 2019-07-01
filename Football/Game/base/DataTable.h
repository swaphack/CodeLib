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
		*	设置属性类型
		*/
		void setType(int nType);
		/**
		*	属性类型
		*/
		int getType() const;
		/**
		*	设置属性值
		*/
		void setValue(float fValue);
		/**
		*	获取属性值
		*/
		float getValue() const;
		/**
		*	改变属性值
		*/
		void addValue(float value);
		/**
		*	设置属性改变时的通知
		*/
		void setChangedHandler(RecordHandler handler);
		/**
		*	属性改变时的通知
		*/
		RecordHandler getChangedHandler();
		/**
		*	克隆
		*/
		DataRecord* clone();
	protected:
		/**
		*	通知属性改变
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
		*	获取属性
		*/
		DataRecord* getRecord(int nRecordType);
		/**
		*	添加属性
		*/
		void addRecord(DataRecord* pRecord);
		/**
		*	移除属性
		*/
		void removeRecord(int nRecordType);
		/**
		*	移除所有属性
		*/
		void removeAllRecords();
		/**
		*	遍历
		*/
		void foreach(const std::function<void(DataRecord*)>& handler);
		/**
		*	克隆
		*/
		DataTable* clone();
	private:
		std::map<int, DataRecord*> m_mRecords;
	};
}