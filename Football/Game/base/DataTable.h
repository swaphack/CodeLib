#pragma once

#include <map>
#include <functional>

#include "../base/Component.h"
#include "../base/Dictionary.h"

namespace game
{
	typedef std::function<void(int type, float newValue, float lastValue)> RecordHandler;
	/**
	*	���ݼ�¼
	*/
	class DataRecord : public Component
	{
	public:
		DataRecord();
		virtual ~DataRecord();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(DataRecord);
	public:
		/**
		*	��������ֵ
		*/
		CREATE_COMPONENT_PROPERTY(float, Value);
		/**
		*	��������ֵ�ı�ʱ�Ĵ���
		*/
		CREATE_COMPONENT_PROPERTY_POINT(RecordHandler, ValueChangedHand);
		/**
		*	�ı�����ֵ
		*/
		void addValue(float value);
	protected:
		/**
		*	֪ͨ���Ըı�
		*/
		void onChangedHandler(float newValue);
	};

	/**
	*	���ݱ�
	*/
	class DataTable : public Dictionary<uint64_t, DataRecord*>
	{
	public:
		DataTable();
		virtual ~DataTable();
	protected:
		virtual void destoryValue(DataRecord* value);
	};
}