#pragma once

#include <string>

namespace sys
{
	class IDataRecord
	{
	public:
		virtual ~IDataRecord() {}
	public:
		// 查找值
		virtual std::string getValue(const std::string& key) const = 0;
		// 添加值
		virtual void setValue(const std::string& key, const std::string& value) = 0;
	};
}