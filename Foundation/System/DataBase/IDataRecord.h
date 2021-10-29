#pragma once

#include <string>

namespace sys
{
	class IDataRecord
	{
	public:
		virtual ~IDataRecord() {}
	public:
		// ����ֵ
		virtual std::string getValue(const std::string& key) const = 0;
		// ���ֵ
		virtual void setValue(const std::string& key, const std::string& value) = 0;
	};
}