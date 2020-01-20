#include "IDataRecord.h"

#include <map>

namespace sys
{
	// 数据记录
	class DataRecord : public IDataRecord
	{
	public:
		DataRecord();
		virtual ~DataRecord();
		
		/**
		*	获取指定参数的值
		*/
		virtual std::string getValue(const std::string& key);
		/**
		*	设置键值对
		*/
		virtual void setValue(const std::string& key, const std::string& value);
	private:
		// 键值对数据
		std::map<std::string, std::string> _values;
	};
}