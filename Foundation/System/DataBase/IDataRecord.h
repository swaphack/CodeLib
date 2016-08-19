#pragma once

namespace sys
{
	class IDataRecord
	{
	public:
		virtual ~IDataRecord() {}
	public:
		// 查找值
		virtual const char* getValue(const char* key) = 0;
		// 添加值
		virtual void setValue(const char* key, const char* value) = 0;
	};
}