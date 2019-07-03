#pragma once

#include <map>
#include <functional>

#include "../base/Component.h"
#include "../base/Dictionary.h"

namespace game
{
	typedef std::function<void(int type, float newValue, float lastValue)> RecordHandler;
	/**
	*	数据记录
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
		*	设置属性值
		*/
		CREATE_COMPONENT_PROPERTY(float, Value);
		/**
		*	设置属性值改变时的处理
		*/
		CREATE_COMPONENT_PROPERTY_POINT(RecordHandler, ValueChangedHand);
		/**
		*	改变属性值
		*/
		void addValue(float value);
	protected:
		/**
		*	通知属性改变
		*/
		void onChangedHandler(float newValue);
	};

	/**
	*	数据表
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