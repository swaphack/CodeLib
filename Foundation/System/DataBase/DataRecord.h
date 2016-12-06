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

		virtual const char* getValue(const char* key);

		virtual void setValue(const char* key, const char* value);
	private:
		// 键值对数据
		std::map<std::string, std::string> _values;
	};
}